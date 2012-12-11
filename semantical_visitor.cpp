#include <sstream>

#include "semantical_visitor.h"
#include "context.h"
#include "type/simple_type.h"
#include "type/array.h"
#include "type/hash_map_type.h"

#define VECTOR_NODE_ITERATOR std::vector< syntax_tree::AbstractNode* >::iterator
#define ITERATE(it, a) for (VECTOR_NODE_ITERATOR it = a->begin(); it != a->end(); it++)


int convertToInt(std::string s) {
	std::stringstream ss(s);
	int ans;
	ss>> ans;
	return ans;
}

SemanticalVisitor::SemanticalVisitor(Context *_context) 
{
	context = _context;
}

Type* SemanticalVisitor::determineType(syntax_tree::AbstractNode* node) {
	currentType=NULL;
	
	node->accept(this);

	if (currentType == NULL) {
		std::string typeName = determineValue(node);
		currentType = getTypeByName(typeName);
		if (currentType == NULL) {
			context->addError("undefined type '" + typeName + "'", node->getBeginPosition());
			currentType = getTypeBySimpleTypeId(VOID_SIMPLE_TYPE);
		}
	}

	return currentType;
}
std::string SemanticalVisitor::determineValue(syntax_tree::AbstractNode* node) {
	currentValue=NULL;
	node->accept(this);
	return *currentValue;
}

void SemanticalVisitor::visit(syntax_tree::Terminal *node) {
	currentValue = new std::string(node->getValue());

	switch(node->getTokenType()) {
		case syntax_tree::INTEGER_LITERAL:
			currentExpressionType = getTypeBySimpleTypeId(INTEGER_SIMPLE_TYPE);
			break;
		case syntax_tree::DOUBLE_LITERAL:
			currentExpressionType = getTypeBySimpleTypeId(DOUBLE_SIMPLE_TYPE);
			break;
		case syntax_tree::STRING_LITERAL:
			currentExpressionType = getTypeBySimpleTypeId(STRING_SIMPLE_TYPE);
			break;
		default:
			break;
	}
}

void SemanticalVisitor::visit(syntax_tree::Program *node) { 
	ITERATE(it, node->getProcAndFuncDeclaration()) {
		(*it)->accept(this);
	}

	node->getBlock()->accept(this);

	Context *global = context;
	for (int i = 0; i < global->getFunctionsAmount(); i++) {
		context = global->getFunctionContext(i);
		global->getFunctionStatement(i)->accept(this);
	}

	context = global;

	currentBlockStatemenent->accept(this);
}

void SemanticalVisitor::visit(syntax_tree::Block *node) {
	ITERATE(it, node->getVariableDeclaration()) {
		(*it)->accept(this);
	}

	currentBlockStatemenent = node->getCompoundStatement();
}

void SemanticalVisitor::addFunction(syntax_tree::AbstractNode* functionName_,std::vector<syntax_tree::AbstractNode*>* formalParametrList_,syntax_tree::AbstractNode* block_,syntax_tree::AbstractNode* typeIdent_) {
	std::string funcName = determineValue(functionName_);
	
	
	currentArgs.clear();

	Context* prev = context;
	context = new Context(prev);

	Type* returnType=NULL;

	if (typeIdent_ == NULL) {
		returnType = getTypeBySimpleTypeId(VOID_SIMPLE_TYPE);
	} else {
		returnType = determineType(typeIdent_);
		context->addVariable("result", returnType);
	}

	ITERATE(it, formalParametrList_) {
		(*it)->accept(this);
	}

	std::vector< Type* > argsTypes;
	argsTypes.reserve(currentArgs.size());

	for (int i = 0; i < currentArgs.size(); i++) {
		argsTypes.push_back(currentArgs[i].second);
	}

	block_->accept(this);

	prev->addFunction(funcName, returnType, argsTypes, context, currentBlockStatemenent, functionName_->getBeginPosition());
	context = prev;
}

void SemanticalVisitor::visit(syntax_tree::FunctionDeclaration *node) {
	addFunction(node->getFunctionName(), node->getFormalParametrList(),node->getBlock(), node->getTypeIdent());
}
void SemanticalVisitor::visit(syntax_tree::ProcedureDeclaration *node) { 
	addFunction(node->getProcName(), node->getFormalParamList(),node->getProcBlock(), NULL);
}
void SemanticalVisitor::visit(syntax_tree::FormalParameterSection *node) { 
	Type* type = determineType(node->getType());

	ITERATE(it, node->getIdentifiersList()) {
		std::string name = determineValue(*it);
		currentArgs.push_back(std::make_pair(name, type));
		context->addVariable(name, type, (*it)->getBeginPosition());
	}
}

void SemanticalVisitor::visit(syntax_tree::VariableDeclaration *node) { 
	Type* type = determineType(node->getVarType());

	ITERATE(it, node->getIdentList()) {
		std::string name = determineValue(*it);
		context->addVariable(name, type, (*it)->getBeginPosition());
	}
}

void SemanticalVisitor::visit(syntax_tree::ArrayType *node) { 
	Type* ofType = determineType(node->getType());

	std::vector< std::pair< int, int > > subranges;
	subranges.reserve(node->getIndexTypeList()->size());

	ITERATE(it, node->getIndexTypeList()) {
		(*it)->accept(this);
		subranges.push_back(currentSubrange);
	}

	std::reverse(subranges.begin(), subranges.end());

	Type* result = ofType;

	for (int i = 0; i < subranges.size(); i++) {
		result = new Array(subranges[i].first, subranges[i].second, result);
	}

	currentType = result;
}
void SemanticalVisitor::visit(syntax_tree::CollectionType *node) { 
	std::string collectionName = determineValue(node->getCollectionName());
	
	//пустое значение на случай, если неправильно определена коллекция
	currentType = getTypeBySimpleTypeId(VOID_SIMPLE_TYPE);
	if (collectionName == "map") {

		if (node->getIdentifierList()->size() != 2) {
			context->addError("wrong types amount", node->getIdentifierList()->back()->getEndPosition());
			return;
		}

		std::vector< syntax_tree::AbstractNode* > types = *(node->getIdentifierList());

		currentType = new HashMapType(determineType(types[0]), determineType(types[1]));
	} else {
		context->addError(collectionName + " is undefined collection type", node->getCollectionName()->getBeginPosition());
		
	}
}
void SemanticalVisitor::visit(syntax_tree::SubrangeType *node) {
	currentSubrange = std::make_pair(convertToInt(determineValue(node->getFromNumber())), convertToInt(determineValue(node->getToNumber())));
}


Type* SemanticalVisitor::determineExpressionType(syntax_tree::AbstractNode* node) {
	int nodeId = (size_t)node;

	if (expressionTypes.find(nodeId) != expressionTypes.end()) {
		return expressionTypes.find(nodeId)->second;
	}

	currentExpressionType = NULL;

	node->accept(this);

	if (currentExpressionType == NULL) {
		currentExpressionType = getTypeBySimpleTypeId(VOID_SIMPLE_TYPE);
	}

	expressionTypes[nodeId] = currentExpressionType;
	return currentExpressionType;
}

void SemanticalVisitor::checkFunctionCall(syntax_tree::AbstractNode* functionName_,std::vector<syntax_tree::AbstractNode*>* params_) {
	std::string name = determineValue(functionName_);

	std::vector< Type* > argsTypes;
	std::vector< std::pair< int, int> > argsPos;
	argsTypes.reserve(params_->size());
	argsPos.reserve(params_->size());

	for (int i = 0; i < params_->size(); i++) {
		argsTypes.push_back(determineExpressionType(params_->at(i)));
		argsPos.push_back(params_->at(i)->getBeginPosition());
	}

	if (context->checkFunctionCall(name, argsTypes, functionName_->getBeginPosition(), argsPos)) {
	} 

	currentExpressionType = context->getReturnTypeOfFunction(name);
}

void SemanticalVisitor::visit(syntax_tree::ProcedureStatement *node) {
	checkFunctionCall(node->getIdentProcName(), node->getActParamList());
}

void SemanticalVisitor::visit(syntax_tree::FunctionDesignator *node) { 
	checkFunctionCall(node->getIdent(), node->getActualParametrList());
}

void SemanticalVisitor::visit(syntax_tree::WhileStatement *node) {
	Type* type = determineExpressionType(node->getWhileExpr());

	if (*type != *(getTypeBySimpleTypeId(INTEGER_SIMPLE_TYPE))) {
		context->addError("while expr should be an integer", node->getWhileExpr()->getBeginPosition());
	}

	determineExpressionType(node->getWhileStatement());
	currentExpressionType=NULL;
}

void SemanticalVisitor::checkIfExpressionIsInteger(syntax_tree::AbstractNode *node) {
	Type* type = determineExpressionType(node);

	if (*type != *(getTypeBySimpleTypeId(INTEGER_SIMPLE_TYPE))) {
		context->addError("expr should be an integer", node->getBeginPosition());
	}
}

void SemanticalVisitor::visit(syntax_tree::ForStatement *node) { 

	checkIfExpressionIsInteger(node->getVariable());
	checkIfExpressionIsInteger(node->getExpression1());
	checkIfExpressionIsInteger(node->getExpression2());

	determineExpressionType(node->getStatement());

	currentExpressionType=NULL;
}


void SemanticalVisitor::visit(syntax_tree::IfStatement *node) { 	
	Type* type = determineExpressionType(node->getExpression());

	if (*type != *(getTypeBySimpleTypeId(INTEGER_SIMPLE_TYPE))) {
		context->addError("if expr should be an integer", node->getExpression()->getBeginPosition());
	}

	determineExpressionType(node->getStatement());

	if (node->getElseExpression()!=NULL) {
		determineExpressionType(node->getElseExpression());
	}

	currentExpressionType=NULL;
}


void SemanticalVisitor::visit(syntax_tree::CompoundStatement *node) {
	for (int i = 0; i < node->getStatementSequence()->size(); i++) {
		determineExpressionType(node->getStatementSequence()->at(i));
	}
}
void SemanticalVisitor::visit(syntax_tree::AssignmentStatement *node) {
	Type* left = determineExpressionType(node->getVariable());
	Type* right = determineExpressionType(node->getExpression());

	std::pair< int, int > pos = node->getExpression()->getBeginPosition();

	if (left != right) {
		context->addError("can't assign " + right->getName() + " to " + left->getName(), pos);
	} else if (left == getTypeBySimpleTypeId(VOID_SIMPLE_TYPE)) {
		context->addError("bad assignment", pos);
	}

	currentExpressionType=NULL;
}

void SemanticalVisitor::visit(syntax_tree::Variable *node) {
	std::string name=determineValue(node->getValue());

	currentExpressionType = context->getVariableType(name, node->getValue()->getBeginPosition());
}

void SemanticalVisitor::visit(syntax_tree::IndexedVariable *node) {
	Type *left = determineExpressionType(node->getVariable());

	for (int i = 0; i < node->getExprList()->size(); i++) {
		syntax_tree::AbstractNode* exprNode = node->getExprList()->at(i);
		Type *cur = determineExpressionType(exprNode);
		left = left->getTypeAfterArrayDereferencing(cur);

		if (left == NULL) {
			context->addError("can't dereference with type '"+cur->getName() + "'", exprNode->getBeginPosition());
			return;
		}
	}

	currentExpressionType = left;
}

void SemanticalVisitor::visit(syntax_tree::UnaryOperator *node) { 
	std::string op = determineValue(node->getSign());

	Type* a = determineExpressionType(node->getSimpleExpression());
	currentExpressionType = a->getTypeAfterUnaryOperation(op);

	if (currentExpressionType == NULL) {
		context->addError("can't apply unary operator '" + op + "' to '" + a->getName() + "'" ,node->getSign()->getBeginPosition());
	}

}
void SemanticalVisitor::visit(syntax_tree::BinaryOperator *node) { 
	std::string op = determineValue(node->getOper());

	Type* a = determineExpressionType(node->getSimpleExpression1());
	Type* b = determineExpressionType(node->getSimpleExpression2());

	if (a != b) {
		context->addError("can't apply binary operator '" + op + "' to '" + a->getName() + "' and '" + b->getName() + "'" ,node->getOper()->getBeginPosition());
		currentExpressionType = NULL;
		return;
	}

	currentExpressionType = a->getTypeAfterBinaryOperation(op);

	if (currentExpressionType == NULL) {
		context->addError("can't apply binary operator '" + op + "' to '" + a->getName() + "'" ,node->getOper()->getBeginPosition());
	}
}