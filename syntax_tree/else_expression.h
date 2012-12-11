#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_ELSE_EXPRESSION
#define CLASS_H_ELSE_EXPRESSION
#include "abstract_node.h"
//лишний?
namespace syntax_tree {
	class ElseExpression : public AbstractNode {
	private:
	public:
		ElseExpression(std::pair< int, int > beginP, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
	};
}

#endif
