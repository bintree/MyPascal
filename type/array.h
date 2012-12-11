
#ifndef CLASS_H_ARRAY_TYPE
#define CLASS_H_ARRAY_TYPE
#include "type.h"

class Array : public Type {
private:
	int from,to;
	Type* ofType;
	std::string id;
public:
	Array(int _from,int _to, Type* ofType);
	virtual std::string getId() const;
	virtual Type* getTypeAfterArrayDereferencing(Type *type);
	int getFrom();
	int getTo();
	Type *getOfType();
};

#endif