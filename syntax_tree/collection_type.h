#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_COLLECTION_TYPE
#define CLASS_H_COLLECTION_TYPE
#include "abstract_node.h"

namespace syntax_tree {
	class CollectionType : public AbstractNode {
	private:
		std::vector<AbstractNode*> * identifierList;
		AbstractNode* collectionName;
	public:
		CollectionType(std::pair< int, int > beginP,AbstractNode* collectionName_, std::vector<AbstractNode*> * identifierList_, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual std::vector<AbstractNode*> * getIdentifierList();
		virtual AbstractNode* getCollectionName();
		virtual void accept(class Visitor *v);
	};
}

#endif
