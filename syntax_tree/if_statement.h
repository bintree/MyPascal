#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_IF_STATEMENT
#define CLASS_H_IF_STATEMENT
#include "abstract_node.h"

namespace syntax_tree {
	class IfStatement : public AbstractNode {
	private:
		AbstractNode* expression;
		AbstractNode* statement;
		AbstractNode* elseExpression;
	public:
		IfStatement(std::pair< int, int > beginP,AbstractNode* expression_,AbstractNode* statement_,AbstractNode* elseExpression_, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getExpression();
		virtual AbstractNode* getStatement();
		virtual AbstractNode* getElseExpression();
		virtual void accept(class Visitor *v);
	};
}

#endif
