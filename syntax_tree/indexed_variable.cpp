#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	IndexedVariable::IndexedVariable(std::pair< int, int > beginP,AbstractNode* variable_,std::vector<AbstractNode*>* exprList_,std::pair< int, int > endP) : AbstractNode(beginP,endP){
		variable = variable_;
		reverseVector(exprList_);
		exprList = exprList_;
		beginPos = beginP;
		endPos = endP;
	}
	std::vector< AbstractNode* > * IndexedVariable::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();	
		result->insert(result->begin(),exprList->begin(),exprList->end());
		result->push_back(variable);
		return result;	
	}
	std::string IndexedVariable::getDesc() {
	    return "IndexedVariable"; 
	}
	AbstractNode* IndexedVariable::getVariable()
	{
		return variable;
	}
	std::vector<AbstractNode*>* IndexedVariable::getExprList()
	{
		return exprList;
	}
	void IndexedVariable::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
