#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_ASSIGNMENT_STATEMENT
#define CLASS_H_ASSIGNMENT_STATEMENT
#include "abstract_node.h"

namespace syntax_tree {
	class AssignmentStatement : public AbstractNode {
	private:
		AbstractNode* variable;
		AbstractNode* expression;
	public:
		AssignmentStatement(std::pair< int, int > beginP, AbstractNode* variable_, AbstractNode* expression_, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getVariable();
		virtual AbstractNode* getExpression();
		virtual void accept(class Visitor *v);
	};
}

#endif
