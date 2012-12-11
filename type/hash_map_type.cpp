#include "hash_map_type.h"

HashMapType::HashMapType(Type* _keyType, Type* _valueType) {
	keyType = _keyType;
	valueType = _valueType;
	id = "hashmap< " + _keyType->getId() + ", " + valueType->getId() + " >";
}
std::string HashMapType::getId() const {
	return id;
}
Type* HashMapType::getKeyType() {
	return keyType;
}
Type* HashMapType::getValueType() {
	return valueType;
}

Type* HashMapType::getTypeAfterArrayDereferencing(Type* type) {
	if (*type == *keyType) {
		return valueType;
	}
	return NULL;
}