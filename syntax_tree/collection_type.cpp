#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	CollectionType::CollectionType(std::pair< int, int > beginP,AbstractNode* collectionName_, std::vector<AbstractNode*>* identifierList_, std::pair< int, int > endP) : AbstractNode(beginP,endP){
		collectionName=collectionName_;
		reverseVector(identifierList_);
		identifierList = identifierList_;
		beginPos = beginP;
		endPos = endP;
	}
	std::vector< AbstractNode* > * CollectionType::getChildren() {
		std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();
		result->push_back(collectionName);
		result->insert(result->begin(),identifierList->begin(),identifierList->end());
		return result;
	}
	std::string CollectionType::getDesc() {
	    return "CollectionType"; 
	}
	AbstractNode* CollectionType::getCollectionName()
	{
		return collectionName;
	}

	std::vector<AbstractNode*> * CollectionType::getIdentifierList() {
		return identifierList;
	}
	void CollectionType::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
