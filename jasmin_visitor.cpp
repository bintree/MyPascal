#include "jasmin_visitor.h"

void printLineToOStream(std::string s, std::ostream &out) {
	out<< s << std::endl;
}

std::string joinStrings(std::string a[], int cnt) {
	std::string result = "";
	for (int i = 0; i < cnt; i++) {
		result+=a[i];
	}
	return result;
}

std::string JasminVisitor::determineValue(syntax_tree::AbstractNode* node) {
	currentValue=NULL;
	node->accept(this);
	return *currentValue;
}

JasminVisitor::JasminVisitor() {
	jvmTypeVisitor = new JVMTypeVisitor();
}

void JasminVisitor::clearInstructions() {
	instructions.clear();
}

void JasminVisitor::addInstruction(std::string instructionText) {
	int label = -1;
	if (waitingForLabeledInstruction) {
		label = labelCounter++;
	}

	waitingForLabeledInstruction = false;

	instructions.push_back(std::make_pair(instructionText, label));
}

void JasminVisitor::addNewInstruction(std::string className) {
	addInstruction("new " + className);	
}

void JasminVisitor::addInvokation(std::string invokationType, std::string className, std::string method, std::string argsTypes[], int argc, std::string returnType) {
	addInstruction("invoke" + invokationType + " " + className + "/" + method + "(" + joinStrings(argsTypes, argc) + ")" + returnType);

}

void JasminVisitor::addInvokeVirtualInstruction(std::string className, std::string method, std::string argsTypes[], int argc, std::string returnType) {
	addInvokation("virtual", className, method, argsTypes, argc, returnType);
}
void JasminVisitor::addInvokeStaticInstruction(std::string className, std::string method, std::string argsTypes[], int argc, std::string returnType) {
	addInvokation("static", className, method, argsTypes, argc, returnType);
}
void JasminVisitor::addInvokationConstructorInstruction(std::string className, std::string argsTypes[], int argc) {
	addInvokation("special", className, "<init>", argsTypes, argc, "V");
}

void JasminVisitor::addPutFieldInstruction(std::string className, std::string fieldName, std::string type) {
	addInstruction("putstatic " + className + "." + fieldName + " " + type);
}
void JasminVisitor::addGetFieldInstruction(std::string className, std::string fieldName, std::string type) {
	addInstruction("getstatic " + className + "." + fieldName + " " + type);
}

int JasminVisitor::getNextLabelNumber() {
	return labelCounter;
}

int JasminVisitor::getLastLabelNumber() {
	return labelCounter-1;
}

std::string getLabelNameByNumber(int number) {
	char s[10];
	sprintf(s, "Label%d", number);
	return s;
}

void printStackLimit(std::ostream &out) {
	char s[20];

	sprintf(s, ".limit stack %d", DEFAULT_STACK_LIMIT);

	printLineToOStream(s, out);
}

void printLocalLimit(int limit, std::ostream &out) {
	char s[20];

	sprintf(s, ".limit locals %d", limit);

	printLineToOStream(s, out);
}

void printLocalDeclaration(std::string name, int id, std::string type, int labelFrom, int labelTo, std::ostream &out) {
	char s[1000];

	sprintf(s, ".var %d is %s %s from %s to %s", id, name.c_str(), type.c_str(), getLabelNameByNumber(labelFrom).c_str(), getLabelNameByNumber(labelTo).c_str());

	printLineToOStream(s, out);
}

Type* JasminVisitor::getTypeOfExpression(syntax_tree::AbstractNode *node) {
	int hash = (size_t)node;
	return expressionTypes[hash];
}

void JasminVisitor::generateJasminCode(Context *global, syntax_tree::AbstractNode *root, std::string sourceFilename, std::string className, std::map< int, Type* > expressionTypes, std::ostream &out) {
	this->out = &out;
	this->expressionTypes = expressionTypes;
	this->className = className;
	currentContext = global;
	labelCounter = 0;
	waitingForLabeledInstruction = false;
	assignExpression = NULL;
	printLineToOStream(".source " + sourceFilename, out);
	printLineToOStream(".class public " + className, out);
	printLineToOStream(".super java/lang/Object", out);

	std::vector< std::pair< std::string, Type* > > allVars = global->getAllVariables();
	
	for (int i = 0; i < allVars.size(); i++) {
		printLineToOStream(".field public static " + allVars[i].first + " " + jvmTypeVisitor->determineJVMType(allVars[i].second) , out);
	}

	//отсюда мы будем читать
	printLineToOStream(".field public static __input Ljava/util/Scanner;", out);
	
	printLineToOStream(".method public static main([Ljava/lang/String;)V", out);

	clearInstructions();
	int startLabelNumber = getNextLabelNumber();
	waitingForLabeledInstruction = true;
	//Далее инициализация сканнера
	addNewInstruction("java/util/Scanner");
	addInstruction("dup");
	addGetFieldInstruction("java.lang.System", "in", "Ljava/io/InputStream;");
	std::string args[] = {"Ljava/io/InputStream;"};
	addInvokationConstructorInstruction("java/util/Scanner", args, 1);
	addPutFieldInstruction(className, "__input", "Ljava/util/Scanner;");

	localsVariablesMap.clear();

	/*
	Обработка глобального кода
	*/
	root->accept(this);
	waitingForLabeledInstruction = true;
	addInstruction("return");

	int endLabelNumber = getLastLabelNumber();

	printStackLimit(out);
	printLocalLimit(1, out);
	printLocalDeclaration("argv", 0, "[Ljava/lang/String;",startLabelNumber, endLabelNumber, out);

	printInstructions();
	
	printLineToOStream(".end method", out);

}

void JasminVisitor::printInstructions() {
	for (int i = 0; i < instructions.size(); i++) {
		if (instructions[i].second != -1) {
			printLineToOStream(getLabelNameByNumber(instructions[i].second)+":", *out);
		}
		printLineToOStream(instructions[i].first, *out);
	}
}

void JasminVisitor::visit(syntax_tree::Terminal *node) {
	currentValue = new std::string(node->getValue());
	
	char *cmd = NULL;

	switch(node->getTokenType()) {
		case syntax_tree::INTEGER_LITERAL:
			cmd = "ldc %s";
			break;
		case syntax_tree::DOUBLE_LITERAL:
			cmd = "ldc2_w %s";
			break;
		case syntax_tree::STRING_LITERAL:
			cmd = "ldc \"%s\"";
			break;
		default:
			break;
	}

	if (cmd != NULL) {
		char *buf = new char[currentValue->length() + strlen(cmd)];
		sprintf(buf, cmd, currentValue->c_str());
		addInstruction(buf);
	}
}

void JasminVisitor::visit(syntax_tree::Program *node) { 
	node->getBlock()->accept(this);
}

void JasminVisitor::visit(syntax_tree::Block *node) {
	node->getCompoundStatement()->accept(this);
}

void JasminVisitor::putExpressionsToStack(std::vector< syntax_tree::AbstractNode* >* argsExpressions) {
	ITERATE(it, argsExpressions) {
		(*it)->accept(this);
	}
}

void JasminVisitor::methodInvokation(syntax_tree::AbstractNode *identNode, std::vector< syntax_tree::AbstractNode* >* argsExpressions) {
	std::string name = determineValue(identNode);

	int funcId = currentContext->getFunctionIdByName(name);

	if (currentContext->getFunctionStatement(funcId) == NULL) {
		//стандартные функции ввода/вывода

		if (name.find("println") == 0) {
			addGetFieldInstruction("java.lang.System","out", "Ljava/io/PrintStream;");
		
			putExpressionsToStack(argsExpressions);


			std::string arg[] = { jvmTypeVisitor->determineJVMType(getTypeOfExpression(argsExpressions->back())) };
			addInvokeVirtualInstruction("java/io/PrintStream", "println", arg, 1, "V");
		} else if (name.find("next") == 0) {
			addGetFieldInstruction(className, "__input", "Ljava/util/Scanner;");

			putExpressionsToStack(argsExpressions);

			std::string typeNameToRead = name.substr(5);

			//default type is string
			Type* typeToRead = getTypeBySimpleTypeId(STRING_SIMPLE_TYPE);
			std::string methodPostfix = "";

			if (typeNameToRead == "integer") {
				typeToRead = getTypeBySimpleTypeId(INTEGER_SIMPLE_TYPE);
				methodPostfix = "Int";
			} else if (typeNameToRead == "double") {
				typeToRead = getTypeBySimpleTypeId(DOUBLE_SIMPLE_TYPE);
				methodPostfix = "Double";
			}


			addInvokeVirtualInstruction("java/util/Scanner", "next" + methodPostfix, NULL, 0, jvmTypeVisitor->determineJVMType(typeToRead));
		}

		return;
	}
	

}

void JasminVisitor::visit(syntax_tree::ProcedureStatement *node) {
	methodInvokation(node->getIdentProcName(), node->getActParamList());
}

void JasminVisitor::visit(syntax_tree::FunctionDesignator *node) { 
	methodInvokation(node->getIdent(), node->getActualParametrList());
}

void JasminVisitor::visit(syntax_tree::WhileStatement *node) {

}

void JasminVisitor::visit(syntax_tree::ForStatement *node) { 

}


void JasminVisitor::visit(syntax_tree::IfStatement *node) { 	

}


void JasminVisitor::visit(syntax_tree::CompoundStatement *node) {
	ITERATE(it, node->getStatementSequence()) {
		(*it)->accept(this);
	}
}
void JasminVisitor::visit(syntax_tree::AssignmentStatement *node) {
	assignExpression = node->getExpression();
	node->getVariable()->accept(this);
}

void JasminVisitor::visit(syntax_tree::Variable *node) {
	syntax_tree::AbstractNode* exprToAssingn = assignExpression;
	assignExpression =  NULL;
	std::string name = determineValue(node->getValue());
	bool isLocal = (!currentContext->isGlobal()) && currentContext->hasLocalVariable(name);

	Type* varType = currentContext->getVariableType(name);

	if (exprToAssingn != NULL) {
		exprToAssingn->accept(this);
		if (!isLocal) {
			addPutFieldInstruction(className, name, jvmTypeVisitor->determineJVMType(varType));
		}
	} else {
		if (!isLocal) {
			addGetFieldInstruction(className, name, jvmTypeVisitor->determineJVMType(varType));
		}
	}
}

void JasminVisitor::visit(syntax_tree::IndexedVariable *node) {

}

void JasminVisitor::visit(syntax_tree::UnaryOperator *node) { 
}
void JasminVisitor::visit(syntax_tree::BinaryOperator *node) { 
}

/*
there is no need in visiting declaration's nodes here
*/
void JasminVisitor::visit(syntax_tree::FunctionDeclaration *node) {
}
void JasminVisitor::visit(syntax_tree::ProcedureDeclaration *node) { 
}
void JasminVisitor::visit(syntax_tree::FormalParameterSection *node) { 
}
void JasminVisitor::visit(syntax_tree::VariableDeclaration *node) { 
}
void JasminVisitor::visit(syntax_tree::ArrayType *node) { 
}
void JasminVisitor::visit(syntax_tree::CollectionType *node) { 
}
void JasminVisitor::visit(syntax_tree::SubrangeType *node) {
}