#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_FACTOR
#define CLASS_H_FACTOR
#include "abstract_node.h"

namespace syntax_tree {
	class Factor : public AbstractNode {
	private:
		AbstractNode*v;
	public:
		Factor(std::pair< int, int > beginP, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
	};
}

#endif
