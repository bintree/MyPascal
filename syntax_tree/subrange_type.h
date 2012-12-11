#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_SUBRANGE_TYPE
#define CLASS_H_SUBRANGE_TYPE
#include "abstract_node.h"

namespace syntax_tree {
	class SubrangeType : public AbstractNode {
	private:
		AbstractNode* fromNumber;
		AbstractNode* toNumber;
	public:
		SubrangeType(std::pair< int, int > beginP,AbstractNode* fromNumber_,AbstractNode* toNumber,std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getFromNumber();
		virtual AbstractNode* getToNumber();
		virtual void accept(class Visitor *v);
	};
}

#endif
