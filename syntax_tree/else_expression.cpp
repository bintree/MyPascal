#include <vector>
#include <string>
#include <utility>

#include "else_expression.h"

namespace syntax_tree {
	ElseExpression::ElseExpression(std::pair< int, int > beginP, std::pair< int, int > endP) : AbstractNode(beginP,endP){
		
	}
	std::vector< AbstractNode* > * ElseExpression::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();			
		return result;	
	}
	std::string ElseExpression::getDesc() {
	    return "ElseExpression"; 
	}
}
