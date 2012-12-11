#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	BinaryOperator::BinaryOperator(std::pair< int, int > beginP, AbstractNode* simpleExpression1_, AbstractNode* oper_, AbstractNode* simpleExpression2_, std::pair< int, int > endP) : AbstractNode(beginP,endP){
		simpleExpression1 = simpleExpression1_;
		simpleExpression2 = simpleExpression2_;
		oper = oper_;
		beginPos = beginP;
		endPos = endP;
	}
	std::vector< AbstractNode* > * BinaryOperator::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();	
		result->push_back(simpleExpression1);
		result->push_back(simpleExpression2);
		result->push_back(oper);
		return result;	
	}
	std::string BinaryOperator::getDesc() {
	    return "BinaryOperator"; 
	}
	AbstractNode* BinaryOperator::getSimpleExpression1()
	{
		return simpleExpression1;
	}
	AbstractNode* BinaryOperator::getSimpleExpression2()
	{
		return simpleExpression2;
	}
	AbstractNode* BinaryOperator::getOper()
	{
		return oper;
	}
	void BinaryOperator::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
