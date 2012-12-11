#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_PROCEDURE_STATEMENT
#define CLASS_H_PROCEDURE_STATEMENT
#include "abstract_node.h"

namespace syntax_tree {
	class ProcedureStatement : public AbstractNode {
	private:
		AbstractNode* identProcName;
		std::vector<AbstractNode*>* actParamList;
	public:
		ProcedureStatement(std::pair< int, int > beginP,AbstractNode* identProcName_,std::vector<AbstractNode*>* actParamList_,std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual AbstractNode* getIdentProcName();
		virtual std::vector<AbstractNode*>* getActParamList();
		virtual void accept(class Visitor *v);
	};
}

#endif
