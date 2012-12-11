#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_FUNCTION_DESIGNATOR
#define CLASS_H_FUNCTION_DESIGNATOR
#include "abstract_node.h"

namespace syntax_tree {
	class FunctionDesignator : public AbstractNode {
	private:
		std::vector<AbstractNode*>* actualParametrList;
		AbstractNode* ident;
	public:
		FunctionDesignator(std::pair< int, int > beginP,AbstractNode* ident_,std::vector<AbstractNode*>* actualParametrList_,std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getIdent();
		virtual std::vector<AbstractNode*>* getActualParametrList();
		virtual void accept(class Visitor *v);
	};
}

#endif
