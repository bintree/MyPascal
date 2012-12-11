#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	Variable::Variable(std::pair< int, int > beginP, AbstractNode* value_,  std::pair< int, int > endP) : AbstractNode(beginP,endP){
		value = value_;
		beginPos = beginP;
		endPos = endP;
	}
	std::vector< AbstractNode* > * Variable::getChildren() {
		std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();
		result->push_back(value);
		return result;
	}
	std::string Variable::getDesc() {
	    return "Variable"; 
	}
	AbstractNode* Variable::getValue()
	{
		return value;
	}
	
	void Variable::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
