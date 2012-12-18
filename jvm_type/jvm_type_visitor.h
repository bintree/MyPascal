#ifndef CLASS_H_JVM_TYPE_VISITOR
#define CLASS_H_JVM_TYPE_VISITOR

#include "../type/type_visitor.h"
#include "../type/type.h"
#include "../type/hash_map_type.h"
#include "../type/simple_type.h"
#include "../type/array.h"

class JVMTypeVisitor : public TypeVisitor {
private:
	std::string jvmTypeName;
	std::pair< int, Type* > offsetType;
	int arrayLength;
public:
	std::string determineJVMType(Type* type);
	std::string getInstructionPrefixForType(Type* type);
	std::pair< int, Type* > getOffsetTypeOfArrayDereferencing(Type *arrayType);
	int getLengthOfArrayType(Type* arrayType);
	virtual void visit(Array* type);
	virtual void visit(HashMapType* type);
	virtual void visit(SimpleType* type);
};

#endif CLASS_H_JVM_TYPE_VISITOR