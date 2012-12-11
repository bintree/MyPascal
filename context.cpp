#include "context.h"

#include <iostream>

std::string convertInt(int number)
{
    if (number == 0)
        return "0";
    std::string temp="";
    std::string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

Context::Context() {
	init();
	parentContext = NULL;
}

Context::Context(Context *_parent)  {
	init();
	parentContext = _parent;
}

void Context::init() {
	functionsMap = new std::map< std::string, int >();
	functionsNames = new std::vector< std::string >();
	funcReturnTypes = new std::vector< Type* >();
	functionsArgs = new std::vector< std::vector< Type* > >();
	functionsStatements = new std::vector< syntax_tree::AbstractNode* >();
	functionsContexts = new std::vector< Context* >();

	varsMap = new std::map< std::string, int >();
	varsNames = new std::vector< std::string >();
	varsTypes = new std::vector< Type* >();

	errors = new std::vector< std::string >();
}

bool addItemIfNotExists( std::map< std::string, int >* m, std::string &name) {
	std::map< std::string, int >::iterator it = m->find(name);

	if (it != m->end()) {
		return false;
	}

	int nextId = m->size();
	(*m)[name]=nextId;

	return true;
}

int getId(std::map< std::string, int >* m, std::string &name) {
	std::map< std::string, int >::iterator it = m->find(name);

	return (it != m->end()) ? it->second : -1;
}

bool Context::addFunction(std::string name, Type *returnType, std::vector< Type* > &argsTypes, Context* funcContext, syntax_tree::AbstractNode* statement) {
	if (addItemIfNotExists(functionsMap, name)) {
		functionsNames->push_back(name);
		funcReturnTypes->push_back(returnType);
		functionsStatements->push_back(statement);
		functionsArgs->push_back(argsTypes);
		functionsContexts->push_back(funcContext);

		return true;
	} else {
		return false;
	}
}

bool Context::addFunction(std::string name, Type *returnType, std::vector< Type* > &argsTypes, Context* funcContext, syntax_tree::AbstractNode* statement, std::pair< int, int > &identPosition) {
	if (addFunction(name, returnType, argsTypes, funcContext, statement)) {
		return true;
	} else {
		addError("attempt to redeclare function '" + name + "'", identPosition);
		return false;
	}
}

bool Context::checkFunctionCall(std::string name, std::vector< Type* > &argsTypes, std::pair< int, int > &identPosition, std::vector< std::pair< int, int > > &argsPositions) {
	int funcId = getId(functionsMap, name);
	if (funcId == -1) {
		addError("undeclared function '" + name + "'", identPosition);
		return false;
	}

	std::vector< Type*> realArgs = (*functionsArgs)[funcId];

	if (realArgs.size() != argsTypes.size()) {
		addError(std::string("wrong parameters count"), identPosition);
		return false;
	}

	int wasErrors = 0;

	for (int i = 0; i < realArgs.size(); i++) {
		if (realArgs[i]->getId() != argsTypes[i]->getId()) {
			addError("wrong parameter " + convertInt(i+1) + ", " + realArgs[i]->getId() + " is expected", argsPositions[i]);
			wasErrors=1;
		}
	}

	return wasErrors==0;
}

Type* Context::getReturnTypeOfFunction(std::string &name) {
	int funcId = getId(functionsMap, name);
	if (funcId == -1) {
		return NULL;
	}

	return (*funcReturnTypes)[funcId];
}

Type* Context::getVariableType(std::string &name) {
	int varId = getId(varsMap, name);
	if (varId == -1) {
		
		if (parentContext != NULL) {
			return parentContext->getVariableType(name);
		}
		return NULL;
	}

	return (*varsTypes)[varId];
}

Type* Context::getReturnTypeOfFunction(std::string &name, std::pair< int, int > &identPosition) {
	Type* result = getReturnTypeOfFunction(name);

	if (result == NULL) {
		addError("undeclared function '" + name + "'", identPosition);
	} 

	return result;
}

Type* Context::getVariableType(std::string &name, std::pair< int, int > &identPosition) {
	Type* result = getVariableType(name);
	
	if (result == NULL) {
		addError("undeclared variable '" + name + "'", identPosition);
	} 

	return result;
}

bool Context::addVariable(std::string name, Type *type) {
	if (addItemIfNotExists(varsMap, name)) {
		varsNames->push_back(name);
		varsTypes->push_back(type);
		return true;
	}
	return false;
}

bool Context::addVariable(std::string name, Type *type, std::pair< int, int > &identPosition) {
	if (!addVariable(name, type)) {
		addError("attempt to redeclare variable '" + name + "'", identPosition);
		return false;
	}
	return true;
}

void Context::addError(std::string msg, std::pair< int, int > &pos) {
	std::string fullError = "Error at line " + convertInt(pos.first) + ", column " + convertInt(pos.second) + ": " + msg;
	errors->push_back(fullError);

	if (parentContext != NULL) {
		parentContext->addError(msg, pos);
	}
}

bool Context::hasErrors() {
	return errors->size() > 0;
}
void Context::printErrors() {
	for (int i = 0; i < errors->size(); i++) {
		std::cout << errors->at(i) << std::endl;
	}
}

void Context::print() {

	std::cout<< "vars" << std::endl;
	for (int i = 0; i < varsNames->size(); i++) {
		std::cout << (*varsNames)[i] << ": " << (*varsTypes)[i]->getName() << std::endl;
	}

	for (int i = 0; i < functionsNames->size(); i++) {
		std::cout << std::endl;
		std::cout << (*functionsNames)[i] << ": " << (*funcReturnTypes)[i]->getName() << "(";
		std::vector< Type* > args = functionsArgs->at(i);

		for (int j = 0; j < args.size(); j++) {
			if (j)std::cout << ", ";

			std::cout << args[j]->getName();
		}

		std::cout << ")";

		std::cout<< std::endl; 

		functionsContexts->at(i)->print();
	}
}

int Context::getFunctionsAmount() {
	return functionsMap->size();
}
Context* Context::getFunctionContext(int id) {
	return functionsContexts->at(id);
}
syntax_tree::AbstractNode* Context::getFunctionStatement(int id) {
	return functionsStatements->at(id);
}