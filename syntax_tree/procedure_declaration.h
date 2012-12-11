#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_PROCEDURE_DECLARATION
#define CLASS_H_PROCEDURE_DECLARATION
#include "abstract_node.h"

namespace syntax_tree {
	class ProcedureDeclaration : public AbstractNode {
	private:
		AbstractNode* procName;
		AbstractNode* procBlock;
		std::vector<AbstractNode*>* formalParamList;
	public:
		ProcedureDeclaration(std::pair< int, int > beginP, AbstractNode* procName_,AbstractNode* procBlock_,std::vector<AbstractNode*>* formalParamList_,std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getProcName();
		virtual AbstractNode* getProcBlock();
		virtual std::vector<AbstractNode*>* getFormalParamList();
		virtual void accept(class Visitor *v);
	};
}

#endif
