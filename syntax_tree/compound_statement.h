#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_COMPOUND_STATEMENT
#define CLASS_H_COMPOUND_STATEMENT
#include "abstract_node.h"

namespace syntax_tree {
	class CompoundStatement : public AbstractNode {
	private:
		std::vector<AbstractNode*> * statementSequence;
	public:
		CompoundStatement(std::pair< int, int > beginP, std::vector<AbstractNode*> * statementSequence_, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual std::vector<AbstractNode*> * getStatementSequence();
		virtual void accept(class Visitor *v);
	};
}

#endif
