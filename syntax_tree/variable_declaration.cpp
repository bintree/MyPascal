#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	VariableDeclaration::VariableDeclaration(std::pair< int, int > beginP,std::vector<AbstractNode*>* identList_,AbstractNode* varType_, std::pair< int, int > endP) : AbstractNode(beginP,endP){
		identList = identList_;
		varType = varType_;
		beginPos = beginP;
		endPos = endP;	
	}
	std::vector< AbstractNode* > * VariableDeclaration::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();		
		result->push_back(varType);
		result->insert(result->begin(),identList->begin(),identList->end());
		return result;	
	}
	std::string VariableDeclaration::getDesc() {
	    return "VariableDeclaration"; 
	}
	std::vector<AbstractNode*>* VariableDeclaration::getIdentList()
	{
		return identList;
	}
	AbstractNode* VariableDeclaration::getVarType()
	{
		return varType;
	}
	void VariableDeclaration::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
