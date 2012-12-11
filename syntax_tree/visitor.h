#include <string>
#include <utility>

#ifndef CLASS_H_VISITOR
#define CLASS_H_VISITOR

#include "syntax_tree.h"

namespace syntax_tree {
	class Visitor {
	public: 
			void virtual visit(ArrayType *node) = 0;
			void virtual visit(AssignmentStatement *node) = 0;
			void virtual visit(BinaryOperator *node) = 0;
			void virtual visit(Block *node) = 0;
			void virtual visit(CollectionType *node) = 0;
			void virtual visit(CompoundStatement *node) = 0;
			void virtual visit(ForStatement *node) = 0;
			void virtual visit(FormalParameterSection *node) = 0;
			void virtual visit(FunctionDeclaration *node) = 0;
			void virtual visit(FunctionDesignator *node) = 0;
			void virtual visit(IfStatement *node) = 0;
			void virtual visit(IndexedVariable *node) = 0;
			void virtual visit(ProcedureDeclaration *node) = 0;
			void virtual visit(ProcedureStatement *node) = 0;
			void virtual visit(Program *node) = 0;
			void virtual visit(SubrangeType *node) = 0;
			void virtual visit(Terminal *node) = 0;
			void virtual visit(UnaryOperator *node) = 0;
			void virtual visit(VariableDeclaration *node) = 0;
			void virtual visit(WhileStatement *node) = 0;
			void virtual visit(Variable *node) = 0;
	};
}

#endif CLASS_H_VISITOR