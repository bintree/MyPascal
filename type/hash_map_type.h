
#ifndef CLASS_H_HASH_MAP_TYPE
#define CLASS_H_HASH_MAP_TYPE
#include "type.h"
class HashMapType : public Type {
private:
	Type* keyType;
	Type* valueType;
	std::string id;
public:
	HashMapType(Type* keyType, Type *valueType);
	virtual Type* getTypeAfterArrayDereferencing(Type *type);
	virtual std::string getId() const;
	Type* getKeyType();
	Type* getValueType();
};

#endif