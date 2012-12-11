#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	SubrangeType::SubrangeType(std::pair< int, int > beginP,AbstractNode* fromNumber_,AbstractNode* toNumber_,std::pair< int, int > endP) : AbstractNode(beginP,endP){
		fromNumber=fromNumber_;
		toNumber=toNumber_;
		beginPos = beginP;
		endPos = endP;	
	}
	std::vector< AbstractNode* > * SubrangeType::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();		
		result->push_back(fromNumber);
		result->push_back(toNumber);
		return result;	
	}
	std::string SubrangeType::getDesc() {
	    return "SubrangeType"; 
	}
	AbstractNode* SubrangeType::getFromNumber()
	{
		return fromNumber;
	}
	AbstractNode* SubrangeType::getToNumber()
	{
		return toNumber;
	}
	void SubrangeType::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
