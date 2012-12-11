#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_EXPRESSION
#define CLASS_H_EXPRESSION
#include "abstract_node.h"

namespace syntax_tree {
	class Expression : public AbstractNode {
	private:
		std::vector<AbstractNode*> * simpleExpression;
		AbstractNode* sign;
	public:
		Expression(std::pair< int, int > beginP, AbstractNode* sign_, std::vector<AbstractNode*> * simpleExpression_, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual std::vector<AbstractNode*> * getSimpleExpression();
		virtual AbstractNode* getSign();
	};
}

#endif
