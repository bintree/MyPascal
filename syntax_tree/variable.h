#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_VARIABLE
#define CLASS_H_VARIABLE
#include "abstract_node.h"

namespace syntax_tree {
	class Variable : public AbstractNode {
	private:
		AbstractNode* value;
	public:
		Variable(std::pair< int, int > beginP, AbstractNode* value_,  std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getValue();
		virtual void accept(class Visitor *v);
	};
}

#endif
