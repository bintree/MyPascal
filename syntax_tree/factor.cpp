#include <vector>
#include <string>
#include <utility>

#include "factor.h"

namespace syntax_tree {
	Factor::Factor(std::pair< int, int > beginP, std::pair< int, int > endP) : AbstractNode(beginP,endP){
		
	}
	std::vector< AbstractNode* > * Factor::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();			
		return result;	
	}
	std::string Factor::getDesc() {
	    return "Factor"; 
	}
}
