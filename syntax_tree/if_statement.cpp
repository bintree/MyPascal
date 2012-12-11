#include <vector>
#include <string>
#include <utility>

#include "if_statement.h"
#include "visitor.h"

namespace syntax_tree {
	IfStatement::IfStatement(std::pair< int, int > beginP,AbstractNode* expression_,AbstractNode* statement_,AbstractNode* elseExpression_, std::pair< int, int > endP) : AbstractNode(beginP,endP){
		expression = expression_;
		statement = statement_;
		elseExpression = elseExpression_;
		beginPos = beginP;
		endPos = endP;
	}
	std::vector< AbstractNode* > * IfStatement::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();
		if(elseExpression != NULL)
		{
			result->push_back(expression);
			result->push_back(statement);
			result->push_back(elseExpression);
		}
		else
		{
			result->push_back(expression);
			result->push_back(statement);
		}
		return result;	
	}
	std::string IfStatement::getDesc() {
	    return "IfStatement"; 
	}
	AbstractNode* IfStatement::getExpression()
	{
		return expression;
	}
	AbstractNode* IfStatement::getStatement()
	{
		return statement;
	}
	AbstractNode* IfStatement::getElseExpression()
	{
		return elseExpression;
	}
	void IfStatement::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
