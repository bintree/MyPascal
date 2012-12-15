#include "jvm_type_visitor.h"

void JVMTypeVisitor::visit(Array* type) {
	jvmTypeName = "[" + determineJVMType(type->getOfType());
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