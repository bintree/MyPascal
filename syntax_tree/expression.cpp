#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"

namespace syntax_tree {
	Expression::Expression(std::pair< int, int > beginP, AbstractNode* sign_, std::vector<AbstractNode*> * simpleExpression_, std::pair< int, int > endP) : AbstractNode(beginP,endP){
		sign = sign_;
		simpleExpression = simpleExpression_;
		beginPos = beginP;
		endPos = endP;
		
	}
	std::vector< AbstractNode* > * Expression::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();
		if(sign != NULL)
		{
			result->push_back(sign);
		}
		result->insert(result->begin(),simpleExpression->begin(), simpleExpression->end());
		return result;	
	}
	std::string Expression::getDesc() {
	    return "Expression"; 
	}
	AbstractNode* Expression::getSign()
	{
		return sign;
	}
	std::vector<AbstractNode*> * Expression::getSimpleExpression()
	{
		return simpleExpression;
	}
}
