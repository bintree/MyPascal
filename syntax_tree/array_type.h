#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H___ARRAY_TYPE
#define CLASS_H___ARRAY_TYPE
#include "abstract_node.h"

namespace syntax_tree {
	class ArrayType : public AbstractNode {
	private:
		std::vector<AbstractNode*>* indexTypeList;
		AbstractNode* type;
	public:
		ArrayType(std::pair< int, int > beginP, std::vector<AbstractNode*>* indexTypeList_, AbstractNode* type_,  std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getType();
		virtual std::vector <AbstractNode*> * getIndexTypeList();
		virtual void accept(class Visitor *v);
	};
}

#endif
