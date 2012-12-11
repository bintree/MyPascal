#include <vector>
#include <string>
#include <utility>
#include <algorithm>

#include "abstract_node.h"

namespace syntax_tree {
	AbstractNode::AbstractNode(std::pair< int, int > beginP, std::pair< int, int > endP) {
		beginPos = beginP;
		endPos = endP;
	}
	std::pair< int, int > AbstractNode::getBeginPosition() {
	    return beginPos;
	}
	std::pair< int, int > AbstractNode::getEndPosition() {
	    return endPos;
	}

	void reverseVector(std::vector< AbstractNode* > * a) {
		std::reverse(a->begin(),a->end());
	}
}
