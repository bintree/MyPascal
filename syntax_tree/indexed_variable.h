#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_INDEXED_VARIABLE
#define CLASS_H_INDEXED_VARIABLE
#include "abstract_node.h"

namespace syntax_tree {
	class IndexedVariable : public AbstractNode {
	private:
		AbstractNode* variable;
		std::vector<AbstractNode*>* exprList;
	public:
		IndexedVariable(std::pair< int, int > beginP,AbstractNode* variable_,std::vector<AbstractNode*>* exprList_,std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getVariable();
		virtual std::vector<AbstractNode*>* getExprList();
		virtual void accept(class Visitor *v);
	};
}

#endif
