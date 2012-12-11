#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	FunctionDesignator::FunctionDesignator(std::pair< int, int > beginP,AbstractNode* ident_,std::vector<AbstractNode*>* actualParametrList_,std::pair< int, int > endP):AbstractNode(beginP,endP){
		ident = ident_;
		reverseVector(actualParametrList_);
		actualParametrList=actualParametrList_;
		beginPos = beginP;
		endPos = endP;
	}
	std::vector< AbstractNode* > * FunctionDesignator::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();		
		result->push_back(ident);
		result->insert(result->begin(),actualParametrList->begin(),actualParametrList->end());
		return result;	
	}
	std::string FunctionDesignator::getDesc() {
	    return "FunctionDesignator"; 
	}
	std::vector<AbstractNode*>* FunctionDesignator::getActualParametrList()
	{
		return actualParametrList;
	}
	AbstractNode* FunctionDesignator::getIdent()
	{
		return ident;
	}
	void FunctionDesignator::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
