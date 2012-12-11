#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	Block::Block(std::pair< int, int > beginP,std::vector<AbstractNode*>* variableDeclaration_, AbstractNode* compoundStatement_, std::pair< int, int > endP):AbstractNode(beginP,endP)
	{
		beginPos = beginP;
		endPos = endP;
		compoundStatement =compoundStatement_;
		reverseVector(variableDeclaration_);
		variableDeclaration = variableDeclaration_;
	}
	
	std::vector< AbstractNode* > * Block::getChildren() {
		std::vector<AbstractNode*>* result = new std::vector<AbstractNode*>();
		result->insert(result->begin(),variableDeclaration->begin(), variableDeclaration->end());
		result->push_back(compoundStatement);
	    return result;
	}
	std::string Block::getDesc() {
	    return "Block"; 
	}
	AbstractNode* Block::getCompoundStatement()
	{
		return compoundStatement;
	}
	std::vector<AbstractNode*>* Block::getVariableDeclaration()
	{
		return variableDeclaration;
	}
	void Block::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
