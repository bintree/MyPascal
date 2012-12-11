#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_BLOCK
#define CLASS_H_BLOCK
#include "abstract_node.h"

namespace syntax_tree {
	class Block : public AbstractNode {
	private:
		std::vector<AbstractNode*>* variableDeclaration;
		AbstractNode* compoundStatement;
	public:
		Block(std::pair< int, int > beginP,std::vector<AbstractNode*>* variableDeclaration_, AbstractNode* compoundStatement_, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual std::vector<AbstractNode*>* getVariableDeclaration();
		virtual AbstractNode* getCompoundStatement();
		virtual void accept(class Visitor *v);
	};
}

#endif
