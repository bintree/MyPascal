#include "array.h"
#include "simple_type.h"

	Array::Array(int _from,int _to, Type* _ofType) {
		from = _from;
		to = _to;
		ofType = _ofType;
		id = "[" + _ofType->getId();
	}
	std::string Array::getId() const {
		return id;
	}
	int Array::getFrom() {
		return from;
	}
	int Array::getTo() {
		return to;
	}
	Type* Array::getOfType() {
		return ofType;
	}

Type* Array::getTypeAfterArrayDereferencing(Type* type) {
	if (*type == *(getTypeBySimpleTypeId(INTEGER_SIMPLE_TYPE))) {
		return ofType;
	}
	return NULL;
}