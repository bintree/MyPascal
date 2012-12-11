#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	WhileStatement::WhileStatement(std::pair< int, int > beginP,AbstractNode* whileExpr_,AbstractNode* whileStatement_,std::pair< int, int > endP) : AbstractNode(beginP,endP){
		whileExpr=whileExpr_;
		whileStatement=whileStatement_;
		beginPos = beginP;
		endPos = endP;	
	}
	std::vector< AbstractNode* > * WhileStatement::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();	
		result->push_back(whileExpr);
		result->push_back(whileStatement);
		return result;	
	}
	std::string WhileStatement::getDesc() {
	    return "WhileStatement"; 
	}
	AbstractNode* WhileStatement::getWhileExpr()
	{
		return whileExpr;
	}
	AbstractNode* WhileStatement::getWhileStatement()
	{
		return whileStatement;
	}
	void WhileStatement::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
