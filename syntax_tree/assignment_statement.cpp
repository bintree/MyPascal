#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	AssignmentStatement::AssignmentStatement(std::pair< int, int > beginP, AbstractNode* variable_, AbstractNode* expression_, std::pair< int, int > endP) : AbstractNode(beginP,endP){
		variable = variable_;
		expression = expression_;
		beginPos = beginP;
		endPos = endP;
	}
	std::vector< AbstractNode* > * AssignmentStatement::getChildren() {
	    std::vector<AbstractNode*>* result = new std::vector<AbstractNode*>();
		result->push_back(variable);
		result->push_back(expression);
		return result;
	}
	std::string AssignmentStatement::getDesc() {
	    return "AssignmentStatement"; 
	}
	AbstractNode* AssignmentStatement::getVariable()
	{
		return variable;
	}
	AbstractNode* AssignmentStatement::getExpression()
	{
		return expression;
	}
	void AssignmentStatement::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
