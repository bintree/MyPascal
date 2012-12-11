#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_FOR_STATEMENT
#define CLASS_H_FOR_STATEMENT
#include "abstract_node.h"

namespace syntax_tree {
	class ForStatement : public AbstractNode {
	private:
		AbstractNode* variable;
		AbstractNode* expression1;
		AbstractNode* expression2;
		AbstractNode* statement;
	public:
		ForStatement(std::pair< int, int > beginP, AbstractNode* variable_,AbstractNode* expression1_,AbstractNode* expression2_,AbstractNode* statement,std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getVariable();
		virtual AbstractNode* getExpression1();
		virtual AbstractNode* getExpression2();
		virtual AbstractNode* getStatement();
		virtual void accept(class Visitor *v);

	};
}

#endif
