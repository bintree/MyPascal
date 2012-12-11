#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_UNARY_OPERATOR
#define CLASS_H_UNARY_OPERATOR
#include "abstract_node.h"

namespace syntax_tree {
	class UnaryOperator : public AbstractNode {
	private:
		AbstractNode* sign;
		AbstractNode* simpleExpression;
	public:
		UnaryOperator(std::pair< int, int > beginP, AbstractNode* sign_, AbstractNode* simpleExpression_, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getSign();
		virtual AbstractNode* getSimpleExpression();
		virtual void accept(class Visitor *v);
	};
}

#endif
