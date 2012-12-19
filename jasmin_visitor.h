#include "syntax_tree/visitor.h"

#ifndef CLASS_H_JASMIN_VISITOR
#define CLASS_H_JASMIN_VISITOR
#include <vector>
#include <utility>
#include "context.h"
#include "jvm_type/jvm_type_visitor.h"

const int DEFAULT_STACK_LIMIT = 100;

class JasminVisitor : public syntax_tree::Visitor {
	private:
		Context *currentContext, *global;
		std::map< std::string, int > localsVariablesMap;
		std::string className;
		std::vector< std::pair< std::string, int > > instructions; 
		JVMTypeVisitor* jvmTypeVisitor;
		std::ostream* out;
		int labelCounter;

		std::string determineValue(syntax_tree::AbstractNode*);
		std::string* currentValue;
		std::map< int, Type* > expressionTypes;

		Type* getTypeOfExpression(syntax_tree::AbstractNode *node);

		bool waitingForLabeledInstruction;
		syntax_tree::AbstractNode* assignExpression;
		void clearInstructions();
		void addInstruction(std::string instructionText);
		void addCMPInstruction(std::string ins, int trueValue);
		void addNewInstruction(std::string className);
		void addInvokation(std::string invokationType, std::string className, std::string method, std::string argsTypes[], int argc, std::string returnType);
		void addInvokeVirtualInstruction(std::string className, std::string method, std::string argsTypes[], int argc, std::string returnType);
		void addInvokeStaticInstruction(std::string className, std::string method, std::string argsTypes[], int argc, std::string returnType);
		void addInvokationConstructorInstruction(std::string className, std::string argsTypes[], int argc);
		void addPutFieldInstruction(std::string className, std::string fieldName, std::string type);
		void addGetFieldInstruction(std::string className, std::string fieldName, std::string type);
		
		void appendArrayCreation(Type* arrayType);
		void appendValueObjectWrapping(std::string jvmType);
		bool appendHashMapCreation(std::string jvmType);

		int getLastInstructionIndex();

		void appendLabelToInstruction(int index, int labelNumber);

		int getNextLabelNumber();
		int getLastLabelNumber();

		void printInstructions();

		void methodInvokation(syntax_tree::AbstractNode *identNode, std::vector< syntax_tree::AbstractNode* >* argsExpressions);

		void putExpressionsToStack(std::vector< syntax_tree::AbstractNode* >* argsExpressions);

	public:
		JasminVisitor(); 
		void generateJasminCode(Context *global, syntax_tree::AbstractNode *root, std::string sourceFilename, std::string className, std::map< int, Type* > expressionTypes, std::ostream &out);
		void virtual visit(syntax_tree::ArrayType *node);
		void virtual visit(syntax_tree::AssignmentStatement *node);
		void virtual visit(syntax_tree::BinaryOperator *node);
		void virtual visit(syntax_tree::Block *node);
		void virtual visit(syntax_tree::CollectionType *node);
		void virtual visit(syntax_tree::CompoundStatement *node);
		void virtual visit(syntax_tree::ForStatement *node);
		void virtual visit(syntax_tree::FormalParameterSection *node);
		void virtual visit(syntax_tree::FunctionDeclaration *node);
		void virtual visit(syntax_tree::FunctionDesignator *node);
		void virtual visit(syntax_tree::IfStatement *node);
		void virtual visit(syntax_tree::IndexedVariable *node);
		void virtual visit(syntax_tree::ProcedureDeclaration *node);
		void virtual visit(syntax_tree::ProcedureStatement *node);
		void virtual visit(syntax_tree::Program *node);
		void virtual visit(syntax_tree::SubrangeType *node);
		void virtual visit(syntax_tree::Terminal *node);
		void virtual visit(syntax_tree::UnaryOperator *node);
		void virtual visit(syntax_tree::VariableDeclaration *node);
		void virtual visit(syntax_tree::WhileStatement *node);
		void virtual visit(syntax_tree::Variable *node);
};

#endif