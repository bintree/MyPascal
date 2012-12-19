#include "syntax_tree/visitor.h"

#ifndef CLASS_H_SEMANTICAL_VISITOR
#define CLASS_H_SEMANTICAL_VISITOR
#include "context.h"
class SemanticalVisitor : public syntax_tree::Visitor {
	private:
		Context *context, *global;
		void addFunction(syntax_tree::AbstractNode* functionName_,std::vector<syntax_tree::AbstractNode*>* formalParametrList_,syntax_tree::AbstractNode* block_,syntax_tree::AbstractNode* typeIdent_);
		void checkFunctionCall(syntax_tree::AbstractNode* functionName_,std::vector<syntax_tree::AbstractNode*>* params_);
		Type* determineType(syntax_tree::AbstractNode*);
		Type* determineExpressionType(syntax_tree::AbstractNode*);
		std::string determineValue(syntax_tree::AbstractNode*);
		
		std::vector< std::pair< std::string, Type* > > currentArgs;
		Type *currentType;
		Type *currentExpressionType;
		std::string* currentValue;
		syntax_tree::AbstractNode* currentBlockStatemenent;
		std::pair< int, int > currentSubrange;

		void checkIfExpressionIsInteger(syntax_tree::AbstractNode *node);
	public:
		SemanticalVisitor(Context *_context);
		void virtual visit(syntax_tree::ArrayType *node);
		void virtual visit(syntax_tree::AssignmentStatement *node);
		void virtual visit(syntax_tree::BinaryOperator *node);
		void virtual visit(syntax_tree::Block *node);
		void virtual visit(syntax_tree::CollectionType *node);
		void virtual visit(syntax_tree::CompoundStatement *node);
		void virtual visit(syntax_tree::ForStatement *node);
		void virtual visit(syntax_tree::FormalParameterSection *node);
		void virtual visit(syntax_tree::FunctionDeclaration *node);
		void virtual visit(syntax_tree::FunctionDesignator *node);
		void virtual visit(syntax_tree::IfStatement *node);
		void virtual visit(syntax_tree::IndexedVariable *node);
		void virtual visit(syntax_tree::ProcedureDeclaration *node);
		void virtual visit(syntax_tree::ProcedureStatement *node);
		void virtual visit(syntax_tree::Program *node);
		void virtual visit(syntax_tree::SubrangeType *node);
		void virtual visit(syntax_tree::Terminal *node);
		void virtual visit(syntax_tree::UnaryOperator *node);
		void virtual visit(syntax_tree::VariableDeclaration *node);
		void virtual visit(syntax_tree::WhileStatement *node);
		void virtual visit(syntax_tree::Variable *node);

		std::map< int, Type* > expressionTypes;
};

#endif