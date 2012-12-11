#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_FORMAL_PARAMETER_SECTION
#define CLASS_H_FORMAL_PARAMETER_SECTION
#include "abstract_node.h"

namespace syntax_tree {
	class FormalParameterSection : public AbstractNode {
	private:
		std::vector< AbstractNode* >* identifiersList;
		AbstractNode* type;
	public:
		FormalParameterSection(std::pair< int, int > beginP,std::vector< AbstractNode* >* identifiersList, AbstractNode* type, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual std::vector< AbstractNode* >* getIdentifiersList();
		virtual AbstractNode* getType();
		virtual void accept(class Visitor *v);
	};
}

#endif
