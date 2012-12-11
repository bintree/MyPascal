#include <vector>
#include <string>
#include <utility>

#include "formal_parameter_section.h"
#include "visitor.h"

namespace syntax_tree {
	FormalParameterSection::FormalParameterSection(std::pair< int, int > beginP,std::vector< AbstractNode* >* identifiersList_, AbstractNode* type_, std::pair< int, int > endP) : AbstractNode(beginP,endP){
		reverseVector(identifiersList_);
		identifiersList = identifiersList_;
		type = type_;
	}
	std::vector< AbstractNode* > * FormalParameterSection::getChildren() {
	    std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();			
		result->push_back(type);
		result->insert(result->begin(), identifiersList->begin(),identifiersList->end());
		return result;	
	}
	std::string FormalParameterSection::getDesc() {
	    return "FormalParameterSection"; 
	}

	std::vector< AbstractNode* >* FormalParameterSection::getIdentifiersList() {
		return identifiersList;
	}
	AbstractNode* FormalParameterSection::getType() {
		return type;
	}
	void FormalParameterSection::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
