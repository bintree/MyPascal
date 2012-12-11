#include <string>
#include <vector>
#include <map>
#include <utility>


#ifndef CLASS_H_CONTEXT
#define CLASS_H_CONTEXT

#include "type/type.h"
#include "syntax_tree/abstract_node.h"

class Context {
private:
	Context* parentContext;
	std::map< std::string, int >* functionsMap;
	std::vector< std::string >* functionsNames;
	std::vector< Type* >* funcReturnTypes;
	std::vector< std::vector< Type* > >* functionsArgs;
	std::vector< Context* >* functionsContexts;

	std::vector< syntax_tree::AbstractNode* >* functionsStatements;
	
	std::map< std::string, int >* varsMap;
	std::vector< std::string >* varsNames;
	std::vector< Type* >* varsTypes;

	std::vector< std::string >* errors;
	
	void init();

	bool addFunction(std::string name, Type *returnType, std::vector< Type* > &argsTypes, Context* funcContext, syntax_tree::AbstractNode* statement);
public:
	Context();
	Context(Context *_parent);

	void print();

	bool addFunction(std::string name, Type *returnType,  std::vector< Type* > &argsTypes, Context* funcContext, syntax_tree::AbstractNode* statement,  std::pair< int, int > &identPosition);
	bool checkFunctionCall(std::string name,std::vector< Type* > &argsTypes,  std::pair< int, int > &identPosition, std::vector< std::pair< int, int > > &argsPositions);
	

	bool addVariable(std::string name, Type *type, std::pair< int, int > &identPosition);
	bool addVariable(std::string name, Type *type);

	Type* getReturnTypeOfFunction(std::string &name, std::pair< int, int > &identPosition);
	Type* getReturnTypeOfFunction(std::string &name);
	Type* getVariableType(std::string &name, std::pair< int, int > &identPosition);
	Type* getVariableType(std::string &name);

	void addError(std::string msg, std::pair< int, int > &pos);
	bool hasErrors();
	void printErrors();

	int getFunctionsAmount();
	Context* getFunctionContext(int id);
	syntax_tree::AbstractNode* getFunctionStatement(int id);
};

#endif CLASS_H_CONTEXT 