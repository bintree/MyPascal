#include <string>
#include "type.h"

std::string Type::getName() {
	return getId();
}

Type* Type::getTypeAfterArrayDereferencing(Type* type) {
	return NULL;
}

Type* Type::getTypeAfterBinaryOperation(std::string op) {
	return NULL;
}
Type* Type::getTypeAfterUnaryOperation(std::string op) {
	return NULL;
}

bool Type::operator==(const Type &other) {
	return getId() == other.getId();
}

bool Type::operator!=(const Type &other) {
	return !(*this == other);
}