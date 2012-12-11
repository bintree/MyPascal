#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	ForStatement::ForStatement(std::pair< int, int > beginP, AbstractNode* variable_,AbstractNode* expression1_,AbstractNode* expression2_,AbstractNode* statement_,std::pair< int, int > endP):AbstractNode(beginP,endP){
		variable = variable_;
		expression1 = expression1_;
		expression2 = expression2_;
		statement = statement_;
		beginPos = beginP;
		endPos = endP;
	}
	std::vector< AbstractNode* > * ForStatement::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();		
		result ->push_back(variable);
		result ->push_back(expression1);
		result ->push_back(expression2);
		result ->push_back(statement);
		return result;	
	}
	std::string ForStatement::getDesc() {
	    return "ForStatement"; 
	}
	AbstractNode* ForStatement::getVariable()
	{
		return variable;
	}
	AbstractNode* ForStatement::getExpression1()
	{
		return expression1;
	}
	AbstractNode* ForStatement::getExpression2()
	{
		return expression2;
	}
	AbstractNode* ForStatement::getStatement()
	{
		return statement;
	}
	void ForStatement::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
