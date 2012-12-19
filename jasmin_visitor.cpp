#include "jasmin_visitor.h"

std::string intToStr(int u) {
	char s[12];
	sprintf(s, "%d", u);
	return s;
}

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

std::string replaceDotsBySlashes(std::string className) {
	for (int i = 0; i < className.size(); i++)
		if (className[i]=='.')
			className[i]='/';
	return className;
}

void JasminVisitor::addInvokation(std::string invokationType, std::string className, std::string method, std::string argsTypes[], int argc, std::string returnType) {
	addInstruction("invoke" + invokationType + " " + replaceDotsBySlashes(className) + "/" + method + "(" + joinStrings(argsTypes, argc) + ")" + returnType);
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

void JasminVisitor::appendArrayCreation(Type* arrayType) {
	int dims = 0;

	std::string jvmType = jvmTypeVisitor->determineJVMType(arrayType);



	for (; jvmType[dims]=='['; dims++) {
		std::pair< int, Type* > offsetAndType = jvmTypeVisitor->getOffsetTypeOfArrayDereferencing(arrayType);

		int length = jvmTypeVisitor->getLengthOfArrayType(arrayType);

		addInstruction("ldc " + intToStr(length));

		arrayType = offsetAndType.second;
	}

	addInstruction("multianewarray " + jvmType + " " + intToStr(dims));
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
	this->global = global;
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

	for (int i = 0; i < global->functionsNames->size(); i++) {
		if (global->functionsStatements->at(i) == NULL)continue;
		
		char s[200];

		std::string *argTypes = new std::string[global->functionsArgs->at(i).size()];

		for (int j = 0; j < global->functionsArgs->at(i).size(); j++) {
			argTypes[j] = jvmTypeVisitor->determineJVMType(
				global->functionsArgs->at(i).at(j)
			);
		}

		sprintf(s, ".method public static %s(%s)%s", 
			global->functionsNames->at(i).c_str(), 
			joinStrings(argTypes, global->functionsArgs->at(i).size()).c_str(), 
			jvmTypeVisitor->determineJVMType(global->funcReturnTypes->at(i)).c_str()
		);
		printLineToOStream(s, out);

		currentContext = global->functionsContexts->at(i);
		std::vector< std::pair< std::string, Type* > > localVars = currentContext->getAllVariables();

		clearInstructions();

		int startLabel = getNextLabelNumber();
		waitingForLabeledInstruction = true;
		for (int j = global->functionsArgs->at(i).size(); j < localVars.size(); j++) {
			
			std::string type = jvmTypeVisitor->determineJVMType(localVars[j].second);
			std::string opPrefix = jvmTypeVisitor->getInstructionPrefixForType(localVars[j].second);
			int was = 0;
			if (type[0]=='[') {
				appendArrayCreation(localVars[j].second);
				was = 1;
			}

			if (appendHashMapCreation(type)) {
				addPutFieldInstruction(className, localVars[j].first, type);
				was = 1;
			}

			if (was) {
				addInstruction(opPrefix + "store " + intToStr(j));
			}
		}

		global->functionsStatements->at(i)->accept(this);

		std::string returnPrefix = jvmTypeVisitor->getInstructionPrefixForType(global->funcReturnTypes->at(i));

		if (returnPrefix.size() > 0) {
			addInstruction(returnPrefix + "load " + intToStr(currentContext->varsMap->find("result")->second));
		}
		int endLabel = getNextLabelNumber();
		waitingForLabeledInstruction = true;
		addInstruction(returnPrefix + "return");

		printStackLimit(out);
		printLocalLimit(localVars.size(), out);
		
		for (int j = 0; j < localVars.size(); j++) {
			std::string localType = jvmTypeVisitor->determineJVMType(localVars[j].second);
			printLocalDeclaration(localVars[j].first, j, localType, startLabel, endLabel, out);
		}

		printInstructions();
	
		printLineToOStream(".end method", out);
	}

	currentContext = global;
	
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

	for (int i = 0; i < allVars.size(); i++) {
		std::string type = jvmTypeVisitor->determineJVMType(allVars[i].second);
		if (type[0]=='[') {
			appendArrayCreation(allVars[i].second);
			addPutFieldInstruction(className, allVars[i].first, type);
		}

		if (appendHashMapCreation(type)) {
			addPutFieldInstruction(className, allVars[i].first, type);
		}
	}

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

	int funcId = global->getFunctionIdByName(name);

	if (global->getFunctionStatement(funcId) == NULL) {
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
	
	putExpressionsToStack(argsExpressions);

	std::string *args = new std::string[argsExpressions->size()];

	for (int i = 0; i < argsExpressions->size(); i++) {
		args[i] = jvmTypeVisitor->determineJVMType(getTypeOfExpression(argsExpressions->at(i)));
	}

	std::string retType = jvmTypeVisitor->determineJVMType(global->getReturnTypeOfFunction(name));

	addInvokeStaticInstruction(className, name, args, argsExpressions->size(), retType);
}

void JasminVisitor::visit(syntax_tree::ProcedureStatement *node) {
	methodInvokation(node->getIdentProcName(), node->getActParamList());
}

void JasminVisitor::visit(syntax_tree::FunctionDesignator *node) { 
	methodInvokation(node->getIdent(), node->getActualParametrList());
}

int JasminVisitor::getLastInstructionIndex() {
	return instructions.size()-1;
}

void JasminVisitor::appendLabelToInstruction(int index, int labelNumber) {
	instructions[index].first+=getLabelNameByNumber(labelNumber);
}

void JasminVisitor::visit(syntax_tree::WhileStatement *node) {
	int startLabel = getNextLabelNumber();
	waitingForLabeledInstruction = true;
	
	node->getWhileExpr()->accept(this);

	addInstruction("iconst_0");
	addInstruction("if_icmpeq ");
	int conditionIndex = getLastInstructionIndex();

	node->getWhileStatement()->accept(this);

	addInstruction("goto " + getLabelNameByNumber(startLabel));

	appendLabelToInstruction(conditionIndex, getNextLabelNumber());
	waitingForLabeledInstruction = true;
}

void JasminVisitor::visit(syntax_tree::ForStatement *node) { 
	syntax_tree::AssignmentStatement *begin = new syntax_tree::AssignmentStatement(node->getBeginPosition(), node->getVariable(), node->getExpression1(), node->getEndPosition());

	begin->accept(this);

	int labelStart = getNextLabelNumber();
	waitingForLabeledInstruction = true;

	syntax_tree::Terminal *opTerm = new syntax_tree::Terminal("<=", syntax_tree::OTHER, std::make_pair(0,0), std::make_pair(0,0));
	syntax_tree::BinaryOperator *condition = new syntax_tree::BinaryOperator(node->getBeginPosition(), node->getVariable(), opTerm, node->getExpression2(), node->getEndPosition());

	condition->accept(this);

	addInstruction("iconst_0");
	addInstruction("if_icmpeq ");
	int conditionIndex = getLastInstructionIndex();

	node->getStatement()->accept(this);

	syntax_tree::Terminal *plusTerm = new syntax_tree::Terminal("+", syntax_tree::OTHER, std::make_pair(0,0), std::make_pair(0,0));
	syntax_tree::Terminal *oneTerm = new syntax_tree::Terminal("1", syntax_tree::INTEGER_LITERAL, std::make_pair(0,0), std::make_pair(0,0));
	syntax_tree::BinaryOperator* addOne = new syntax_tree::BinaryOperator(std::make_pair(0, 0), node->getVariable(), plusTerm, oneTerm, std::make_pair(0,0));

	syntax_tree::AssignmentStatement *incrementStatement = new syntax_tree::AssignmentStatement(node->getBeginPosition(), node->getVariable(), addOne, node->getEndPosition());

	incrementStatement->accept(this);

	addInstruction("goto " + getLabelNameByNumber(labelStart));

	appendLabelToInstruction(conditionIndex, getNextLabelNumber());
	waitingForLabeledInstruction = true;
}


void JasminVisitor::visit(syntax_tree::IfStatement *node) { 	
	node->getExpression()->accept(this);
	addInstruction("iconst_0");

	addInstruction("if_icmpeq ");
	int ifIndex = getLastInstructionIndex();

	node->getStatement()->accept(this);

	appendLabelToInstruction(ifIndex, getNextLabelNumber());
	
	waitingForLabeledInstruction = true;
	if (node->getElseExpression() != NULL) {
		waitingForLabeledInstruction = false;
		addInstruction("goto ");
		waitingForLabeledInstruction = true;
		int gotoIndex = getLastInstructionIndex();
		node->getElseExpression()->accept(this);
		
		appendLabelToInstruction(gotoIndex, getNextLabelNumber());
		waitingForLabeledInstruction = true;
	}
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

	std::string localNumber = "-1";

	if (isLocal) {
		localNumber = intToStr(currentContext->varsMap->find(name)->second);
	}

	if (exprToAssingn != NULL) {
		exprToAssingn->accept(this);
		if (!isLocal) {
			addPutFieldInstruction(className, name, jvmTypeVisitor->determineJVMType(varType));
		} else {
			addInstruction(jvmTypeVisitor->getInstructionPrefixForType(varType) + "store " + localNumber);
		}
	} else {
		if (!isLocal) {
			addGetFieldInstruction(className, name, jvmTypeVisitor->determineJVMType(varType));
		} else {
			addInstruction(jvmTypeVisitor->getInstructionPrefixForType(varType) + "load " + localNumber);
		}
	}
}

std::string getJVMClassWrapperFor(std::string jvmType) {
	return jvmType == "I" ? "Integer" : "Double";
}

void JasminVisitor::appendValueObjectWrapping(std::string jvmType) {
	if (jvmType == "I" || jvmType == "D") {
		std::string valueClassName = getJVMClassWrapperFor(jvmType);

		valueClassName = "java.lang." + valueClassName;

		std::string args[] = { jvmType };

		addInvokeStaticInstruction(valueClassName, "valueOf", args, 1, "L" + replaceDotsBySlashes(valueClassName) + ";");
	}
}

bool JasminVisitor::appendHashMapCreation(std::string jvmType) {
	if (jvmType.find("HashMap") != std::string::npos) {
		addNewInstruction("java/util/HashMap");
		addInstruction("dup");
		addInvokationConstructorInstruction("java.util.HashMap", NULL, 0);
		return true;
	}
	return false;
}

void JasminVisitor::visit(syntax_tree::IndexedVariable *node) {
	syntax_tree::AbstractNode *expr = assignExpression;
	assignExpression = NULL;

	std::string jvmType = jvmTypeVisitor->determineJVMType(getTypeOfExpression(node->getVariable()));

	node->getVariable()->accept(this);

	if (jvmType[0] == '[') {
		std::vector< syntax_tree::AbstractNode* > indexes = *(node->getExprList());

		Type *currentType = getTypeOfExpression(node->getVariable());
		int i;
		for (i = 0; i < indexes.size()-1; i++) {
			indexes[i]->accept(this);

			std::pair< int, Type* > offsetType = jvmTypeVisitor->getOffsetTypeOfArrayDereferencing(currentType);

			addInstruction("ldc " + intToStr(offsetType.first));
			addInstruction("isub");
			addInstruction("aaoad");
		}
		indexes[i]->accept(this);

		std::pair< int, Type* > offsetType = jvmTypeVisitor->getOffsetTypeOfArrayDereferencing(currentType);

		addInstruction("ldc " + intToStr(offsetType.first));
		addInstruction("isub");

		std::string ins = "";

		std::string jvmPrefix = jvmTypeVisitor->getInstructionPrefixForType(offsetType.second);

		if (expr != NULL) {
			expr->accept(this);
			ins = jvmPrefix + "astore";
		} else {
			ins = jvmPrefix + "aload";
		}

		addInstruction(ins);
	} else {
		//hashmap
		node->getExprList()->at(0)->accept(this);

		std::string keyJvmType = jvmTypeVisitor->determineJVMType(getTypeOfExpression( node->getExprList()->at(0) ));

		appendValueObjectWrapping(keyJvmType);

		const std::string objectClassName = "Ljava/lang/Object;";
		std::string args[] = { objectClassName };

		if (expr != NULL) {
			expr->accept(this);

			std::string jvmValueType = jvmTypeVisitor->determineJVMType(getTypeOfExpression(expr));
			appendValueObjectWrapping(jvmValueType);
			std::string args[] = { objectClassName, objectClassName };
			addInvokeVirtualInstruction("java.util.HashMap", "put", args, 2, objectClassName);
			addInstruction("pop");
		} else {
			std::string jvmValueType = jvmTypeVisitor->determineJVMType(getTypeOfExpression(node));

			addInvokeVirtualInstruction("java.util.HashMap", "get", args, 1, objectClassName);

			std::string castTypeName = jvmValueType;

			if (jvmValueType == "I" || jvmValueType == "D") {
				castTypeName = "java/lang/";
				castTypeName += getJVMClassWrapperFor(jvmValueType);
			}

			addInstruction("checkcast " + castTypeName);

			if (jvmValueType == "I" || jvmValueType == "D") {
				std::string castingMethodPrefix = jvmValueType == "I" ? "int" : "double";
				
				addInvokeVirtualInstruction(
					"java.lang." + getJVMClassWrapperFor(jvmValueType), 
					castingMethodPrefix + "Value", 
					NULL,
					0,
					jvmValueType
				);

			}
		}
	}
}

void JasminVisitor::addCMPInstruction(std::string ins, int trueValue) {
	addInstruction(ins + " " + getLabelNameByNumber(getNextLabelNumber()));

	std::string trueStringValue = trueValue ? "0" : "1";

	addInstruction("iconst_" + trueStringValue);

	addInstruction("goto " + getLabelNameByNumber(getNextLabelNumber() + 1));
	
	waitingForLabeledInstruction = true;
	trueStringValue = trueValue ? "1" : "0";
	addInstruction("iconst_" + trueStringValue);
	waitingForLabeledInstruction = true;
}

void JasminVisitor::visit(syntax_tree::UnaryOperator *node) { 
	std::string op = determineValue(node->getSign());

	node->getSimpleExpression()->accept(this);

	if (op == "not") {
		addInstruction("iconst_1");
		addInstruction("ixor");
	} else if (op == "-") {
		std::string prefix = jvmTypeVisitor->getInstructionPrefixForType(getTypeOfExpression(node->getSimpleExpression()));
		addInstruction(prefix + "neg");
	}
}
void JasminVisitor::visit(syntax_tree::BinaryOperator *node) {
	std::string op = determineValue(node->getOper());

	std::string jvmType = jvmTypeVisitor->determineJVMType(getTypeOfExpression(node->getSimpleExpression1()));

	node->getSimpleExpression1()->accept(this);
	node->getSimpleExpression2()->accept(this);

	if (op == "<" || op == "<=" || op == "==" || op == ">=" || op == ">" || op == "!=") {
		if (jvmType == "I") {
			std::string opType = "";
			if (op ==  "<") {
				opType = "lt";
			} else if (op == "<=") {
				opType = "le";
			} else if (op == "==") {
				opType = "eq";
			} else if (op == ">=") {
				opType = "ge";
			} else if (op == ">") {
				opType = "gt";
			} else if (op == "!=") {
				opType = "ne";
			}

			addCMPInstruction("if_icmp" + opType, 1);
		} else if (jvmType == "D") {
			addInstruction("dcmpl");
			int compareValue=0;
            int trueValue=0;
			if (op ==  "<") {
				compareValue = -1; trueValue = 1;
			} else if (op == "<=") {
				compareValue = 1; trueValue = 0;
			} else if (op == "==") {
				compareValue = 0; trueValue = 1;
			} else if (op == ">=") {
				compareValue = -1; trueValue = 0;
			} else if (op == ">") {
				compareValue = 1; trueValue = 1;
			} else if (op == "!=") {
				compareValue = 0; trueValue = 0;
			}
			
			std::string c = "1";
			if (compareValue == 0) {
				c="0";
			}
			if (compareValue == -1) {
				c="m1";
			}

			addInstruction("iconst_" + c);
			addCMPInstruction("if_icmpeq", trueValue);
		}
	} else {
		std::string prefix = jvmTypeVisitor->getInstructionPrefixForType(getTypeOfExpression(node->getSimpleExpression1()));
		
		if (prefix != "a") {
			std::string opcode = "";
			if (op == "||") {
				opcode = "or";
			} else if (op == "&&") {
				opcode = "and";
			} else if (op == "/" || op == "div") {
				opcode = "div";
			} else if (op == "-") {
				opcode = "sub";
			} else if (op == "mod") {
				opcode = "rem";
			} else if (op == "+") {
				opcode = "add";
			} else if (op == "*") {
				opcode = "mul";
			}

			addInstruction(prefix + opcode);
		} else {
			std::string arg[] = {"Ljava/lang/String;"};
			addInvokeVirtualInstruction("java.lang.String", "concat", arg, 1, arg[0]);
		}
	}
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