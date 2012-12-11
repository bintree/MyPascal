#include <vector>
#include <string>
#include <utility>

#ifndef CLASS_H_PROGRAM
#define CLASS_H_PROGRAM
#include "abstract_node.h"

namespace syntax_tree {
	class Program : public AbstractNode {
	private:
		std::vector< AbstractNode* >* procAndFuncDeclaration;
		AbstractNode* block;
	public:
		Program(std::pair< int, int > beginP,std::vector< AbstractNode* >* procAndFuncDeclaration,AbstractNode* block, std::pair< int, int > endP);
		virtual std::vector< AbstractNode* > * getChildren();
		virtual std::string getDesc();
		virtual std::vector< AbstractNode* >* getProcAndFuncDeclaration();
		virtual AbstractNode* getBlock();
		virtual void accept(class Visitor *v);
	};
}

#endif
