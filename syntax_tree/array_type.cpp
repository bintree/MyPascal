#include <vector>
#include <string>
#include <utility>

#include "syntax_tree.h"
#include "visitor.h"

namespace syntax_tree {
	ArrayType::ArrayType(std::pair< int, int > beginP, std::vector<AbstractNode*>* indexTypeList_, AbstractNode* type_,  std::pair< int, int > endP) : AbstractNode(beginP,endP){
		type = type_;
		reverseVector(indexTypeList_);
		indexTypeList = indexTypeList_;
		beginPos = beginP;
		endPos = endP;
	}
	std::vector< AbstractNode* > * ArrayType::getChildren() {
		std::vector<AbstractNode*> * result = new std::vector<AbstractNode*>();
		result->insert(result->begin(), indexTypeList->begin(), indexTypeList->end());
		result->push_back(type);
		return result;
	}
	std::string ArrayType::getDesc() {
	    return "ArrayType"; 
	}
	AbstractNode* ArrayType::getType()
	{
		return type;
	}
	std::vector <AbstractNode*> * ArrayType::getIndexTypeList()
	{
		return indexTypeList;
	}

	void ArrayType::accept(Visitor *v) 
	{
		v->visit(this);
	}
}
