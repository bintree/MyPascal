#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_VARIABLE_DECLARATION
#define CLASS_H_VARIABLE_DECLARATION
#include "abstract_node.h"

namespace syntax_tree {
	class VariableDeclaration : public AbstractNode {
	private:
		std::vector<AbstractNode*>* identList;
		AbstractNode* varType;
	public:
		VariableDeclaration(std::pair< int, int > beginP,std::vector<AbstractNode*>* identList_,AbstractNode* varType_, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual std::vector<AbstractNode*>* getIdentList();
		virtual AbstractNode* getVarType();
		virtual void accept(class Visitor *v);
	};
}

#endif
