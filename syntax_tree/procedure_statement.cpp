#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	ProcedureStatement::ProcedureStatement(std::pair< int, int > beginP,AbstractNode* identProcName_,std::vector<AbstractNode*>* actParamList_,std::pair< int, int > endP) : AbstractNode(beginP,endP){
		identProcName = identProcName_;
		reverseVector(actParamList_);
		actParamList = actParamList_;
		beginPos = beginP;
		endPos = endP;	
	}
	std::vector< AbstractNode* > * ProcedureStatement::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();			
		result->insert(result->begin(),actParamList->begin(),actParamList->end());
		result->push_back(identProcName);
		return result;	
	}
	std::string ProcedureStatement::getDesc() {
	    return "ProcedureStatement"; 
	}
	AbstractNode* ProcedureStatement::getIdentProcName()
	{
		return identProcName;
	}
	 std::vector<AbstractNode*>* ProcedureStatement::getActParamList()
	 {
		 return actParamList;
	 }
	 void ProcedureStatement::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
