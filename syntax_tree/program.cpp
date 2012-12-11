#include <vector>
#include <string>
#include <utility>

#include "program.h"
#include "visitor.h"

namespace syntax_tree {
	Program::Program(std::pair< int, int > beginP,std::vector< AbstractNode* >* procAndFuncDeclaration_,AbstractNode* block_, std::pair< int, int > endP) : AbstractNode(beginP,endP){
		reverseVector(procAndFuncDeclaration_);
		procAndFuncDeclaration = procAndFuncDeclaration_;
		block = block_;
	}
	std::vector< AbstractNode* > * Program::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();	
		result->insert(result->begin(), procAndFuncDeclaration->begin(), procAndFuncDeclaration->end());
		result->push_back(block);
		return result;	
	}
	std::string Program::getDesc() {
	    return "Program"; 
	}

	std::vector< AbstractNode* >* Program::getProcAndFuncDeclaration() {
		return procAndFuncDeclaration;
	}
	AbstractNode* Program::getBlock() {
		return block;
	}
	void Program::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
