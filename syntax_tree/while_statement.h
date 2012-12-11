#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_WHILE_STATEMENT
#define CLASS_H_WHILE_STATEMENT
#include "abstract_node.h"

namespace syntax_tree {
	class WhileStatement : public AbstractNode {
	private:
		AbstractNode* whileExpr;
		AbstractNode* whileStatement;
	public:
		WhileStatement(std::pair< int, int > beginP,AbstractNode* whileExpr_,AbstractNode* whileStatement_,std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getWhileExpr();
		virtual AbstractNode* getWhileStatement();
		virtual void accept(class Visitor *v);
	};
}

#endif
