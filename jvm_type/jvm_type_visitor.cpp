#include "jvm_type_visitor.h"

void JVMTypeVisitor::visit(Array* type) {
	jvmTypeName = "[" + determineJVMType(type->getOfType());
	offsetType = std::make_pair(type->getFrom(), type->getOfType());
	arrayLength = type->getTo() - type->getFrom() + 1;
}
void JVMTypeVisitor::visit(HashMapType* type) {
	jvmTypeName = "Ljava/util/HashMap;";
}
void JVMTypeVisitor::visit(SimpleType* type) {
	if (type == getTypeBySimpleTypeId(INTEGER_SIMPLE_TYPE)) {
		jvmTypeName = "I";
		return;
	} else
	if (type == getTypeBySimpleTypeId(DOUBLE_SIMPLE_TYPE)) {
		jvmTypeName = "D";
		return;
	} else
	if (type == getTypeBySimpleTypeId(STRING_SIMPLE_TYPE)) {
		jvmTypeName = "Ljava/lang/String;";
		return;
	} else {
		jvmTypeName = "V";
		return;
	}
}

std::string JVMTypeVisitor::determineJVMType(Type* type) {
	type->accept(this);
	return jvmTypeName;
}

std::string JVMTypeVisitor::getInstructionPrefixForType(Type* type) {
	std::string jvmType = determineJVMType(type);

	if (jvmType == "I") {
		return "i";
	} 
	if (jvmType == "D") {
		return "d";
	} 
	if (jvmType == "V") {
		return "";
	}

	return "a";
}

std::pair< int, Type* > JVMTypeVisitor::getOffsetTypeOfArrayDereferencing(Type *arrayType) {
	arrayType->accept(this);
	return offsetType;
}
int JVMTypeVisitor::getLengthOfArrayType(Type* arrayType) {
	arrayType->accept(this);
	return arrayLength;
}