#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_TERMINAL
#define CLASS_H_TERMINAL
#include "abstract_node.h"

namespace syntax_tree {

	class Terminal : public AbstractNode {
	private:
		token_type tokenType;
		std::string tokenValue;
	public:
		Terminal(std::string value, token_type type, std::pair< int, int > beginP, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual token_type getTokenType();
		virtual std::string getValue();
		virtual void accept(class Visitor *v);
	};
}

#endif
