#include <vector>
#include <string>
#include <utility>

#include "compound_statement.h"
#include "visitor.h"

namespace syntax_tree {
	CompoundStatement::CompoundStatement(std::pair< int, int > beginP, std::vector<AbstractNode*> * statementSequence_, std::pair< int, int > endP) : AbstractNode(beginP,endP){
		reverseVector(statementSequence_);
		statementSequence = statementSequence_;
		beginPos = beginP;
		endPos = endP;		
	}
	std::vector< AbstractNode* > * CompoundStatement::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();	
		result->insert(result->begin(),statementSequence->begin(), statementSequence->end());
		return result;	
	}
	std::string CompoundStatement::getDesc() {
	    return "CompoundStatement"; 
	}

	std::vector<AbstractNode*> * CompoundStatement::getStatementSequence() {
		return statementSequence;
	}
	void CompoundStatement::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
