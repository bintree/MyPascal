#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_BINARY_OPERATOR
#define CLASS_H_BINARY_OPERATOR
#include "abstract_node.h"

namespace syntax_tree {
	class BinaryOperator : public AbstractNode {
	private:
		AbstractNode* simpleExpression1;
		AbstractNode* simpleExpression2;
		AbstractNode* oper;
	public:
		BinaryOperator(std::pair< int, int > beginP, AbstractNode* simpleExpression1_, AbstractNode* oper_, AbstractNode* simpleExpression2_, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getSimpleExpression1();
		virtual AbstractNode* getSimpleExpression2();
		virtual AbstractNode* getOper();
		virtual void accept(class Visitor *v);
	};
}
#endif
