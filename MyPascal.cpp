#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>

#include "generated/parser.h"
#include "generated/scanner.h"
#include "syntax_tree/abstract_node.h"
#include "semantical_visitor.h"
#include "context.h"
#include "jasmin_visitor.h"

#include "type/type.h"

using namespace std;
std::map< int, Type* > types;
void print_tree(syntax_tree::AbstractNode *node, std::string prefix) {
	if (node != NULL) {
		std::string desc = node->getDesc();
		int nodeId = (size_t)node;

		if (types[nodeId] != NULL) {
			desc += "[" + types[nodeId]->getName() + "]";
		}

		std::cout << prefix << desc << std::endl;

		std::vector< syntax_tree::AbstractNode* > *children = node->getChildren();

		for (int i = 0; i < children->size(); i++) {
			print_tree((*children)[i], "---"+prefix);
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc > 1) {
		std::ifstream f(argv[1], std::ifstream::in);

		generated::Scanner scanner(&f, &std::cout); 

		std::vector< std::pair< std::string, std::pair< int, int > > > errors;

		syntax_tree::AbstractNode *root = NULL;

		generated::Parser p(scanner, root, errors); 

		if (p.parse() > 0 || errors.size() > 0) {
			std::cout << "There was a syntax errors:\n";
			
			for (int i = 0; i < errors.size(); i++) {
				std::cout<< "At line " << errors[i].second.first << ", column " << errors[i].second.second << ": " << errors[i].first;
				std::cout << '\n';
			}

			return 1;
		}

		//

		Context* global = new Context();

		SemanticalVisitor visitor(global);
		root->accept(&visitor);

		if (global->hasErrors()) {
			global->printErrors();
			return 1;
		}

		global->print();

		types = visitor.expressionTypes;

		print_tree(root, "");

		JasminVisitor jasminGenerator;

		std::string jasminFilename = string(argv[1])+".j";
		std::ofstream jasminOutput(jasminFilename);

		jasminGenerator.generateJasminCode(global, root, argv[1], "Main", visitor.expressionTypes, jasminOutput);
		
		char cmd[1000];

		sprintf(cmd, "java -jar jasmin.jar %s", jasminFilename.c_str());

		system(cmd);

		system("java Main");
	}
	return 0;
}

