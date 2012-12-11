#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	ProcedureDeclaration::ProcedureDeclaration(std::pair< int, int > beginP, AbstractNode* procName_,AbstractNode* procBlock_,std::vector<AbstractNode*>* formalParamList_,std::pair< int, int > endP) : AbstractNode(beginP,endP){
		procName=procName_;
		procBlock = procBlock_;
		reverseVector(formalParamList_);
		formalParamList = formalParamList_;
		beginPos = beginP;
		endPos = endP;
	}
	std::vector< AbstractNode* > * ProcedureDeclaration::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();		
		if(formalParamList != NULL)
		{
			result->insert(result->begin(),formalParamList->begin(),formalParamList->end());
			result->push_back(procName);
			result->push_back(procBlock);
		}
		else
		{
			result->push_back(procName);
			result->push_back(procBlock);
		}

		return result;	
	}
	std::string ProcedureDeclaration::getDesc() {
	    return "ProcedureDeclaration"; 
	}
	AbstractNode* ProcedureDeclaration::getProcName()
	{
		return procName;
	}
	AbstractNode* ProcedureDeclaration::getProcBlock()
	{
		return procBlock;
	}
	std::vector<AbstractNode*>* ProcedureDeclaration::getFormalParamList()
	{
		return formalParamList;
	}
	void ProcedureDeclaration::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
