#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	FunctionDeclaration::FunctionDeclaration(std::pair< int, int > beginP,AbstractNode* functionName_,std::vector<AbstractNode*>* formalParametrList_,AbstractNode* typeIdent_,AbstractNode* block_,std::pair< int, int > endP) : AbstractNode(beginP,endP){
		functionName =functionName_;
		typeIdent = typeIdent_;
		reverseVector(formalParametrList_);
		formalParametrList = formalParametrList_;
		block = block_;
		beginPos = beginP;
		endPos = endP;
	}
	std::vector< AbstractNode* > * FunctionDeclaration::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();
		if(formalParametrList != NULL)
		{
			result->push_back(functionName);
			result->push_back(typeIdent);
			result->push_back(block);
			result->insert(result->begin(),formalParametrList->begin(),formalParametrList->end());
		}
		else
		{
			result->push_back(functionName);
			result->push_back(typeIdent);
			result->push_back(block);
		}
		return result;	
	}
	std::string FunctionDeclaration::getDesc() {
	    return "FunctionDeclaration"; 
	}
	AbstractNode* FunctionDeclaration::getFunctionName()
	{
		return functionName;
	}
	AbstractNode* FunctionDeclaration::getTypeIdent()
	{
		return typeIdent;
	}
	AbstractNode* FunctionDeclaration::getBlock()
	{
		return block;
	}
    std::vector<AbstractNode*>* FunctionDeclaration::getFormalParametrList()
	{
		return formalParametrList;
	}
	void FunctionDeclaration::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
