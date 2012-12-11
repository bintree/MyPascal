#include <vector>
#include <string>
#include <utility>

#include "unary_operator.h"
#include "visitor.h"

namespace syntax_tree {
	UnaryOperator::UnaryOperator(std::pair< int, int > beginP, AbstractNode* sign_, AbstractNode* simpleExpression_, std::pair< int, int > endP) : AbstractNode(beginP,endP){
		sign = sign_;
		simpleExpression = simpleExpression_;
		beginPos = beginP;
		endPos = endP;
	}
	std::vector< AbstractNode* > * UnaryOperator::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();	
		result->push_back(sign);
		result->push_back(simpleExpression);
		return result;	
	}
	std::string UnaryOperator::getDesc() {
	    return "UnaryOperator"; 
	}
	AbstractNode* UnaryOperator::getSign()
	{
		return sign;
	}
	AbstractNode* UnaryOperator::getSimpleExpression()
	{
		return simpleExpression;
	}
	void UnaryOperator::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
