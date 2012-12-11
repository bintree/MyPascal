#include <vector>
#include <string>
#include <utility>

#include "terminal.h"
#include "visitor.h"

namespace syntax_tree {
	Terminal::Terminal(std::string value, token_type type, std::pair< int, int > beginP, std::pair< int, int > endP) : AbstractNode(beginP,endP) {
		tokenType = type;
		tokenValue = value;
	}
	std::vector< AbstractNode* > * Terminal::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();			
		return result;	
	}
	std::string Terminal::getDesc() {
	    return "Terminal(" + getValue() + ")"; 
	}
	token_type Terminal::getTokenType() {
	    return tokenType;
	}
	std::string Terminal::getValue() {
	    return tokenValue;
	}
	void Terminal::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
