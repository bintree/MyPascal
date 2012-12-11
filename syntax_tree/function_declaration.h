#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_FUNCTION_DECLARATION
#define CLASS_H_FUNCTION_DECLARATION
#include "abstract_node.h"

namespace syntax_tree {
	class FunctionDeclaration : public AbstractNode {
	private:
		AbstractNode* functionName;
		AbstractNode* typeIdent;
		std::vector<AbstractNode*>* formalParametrList;
		AbstractNode* block;
	public:
		FunctionDeclaration(std::pair< int, int > beginP,AbstractNode* functionName_,std::vector<AbstractNode*>* formalParametrList_,AbstractNode* typeIdent_,AbstractNode* block_,std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getFunctionName();
		virtual AbstractNode* getTypeIdent();
		virtual AbstractNode* getBlock();
		virtual std::vector<AbstractNode*>* getFormalParametrList();
		virtual void accept(class Visitor *v);
	};
}

#endif
