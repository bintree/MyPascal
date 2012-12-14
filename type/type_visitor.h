#ifndef CLASS_H_TYPE_VISITOR
#define CLASS_H_TYPE_VISITOR

#include "type.h"
#include "hash_map_type.h"
#include "simple_type.h"
#include "array.h"

class TypeVisitor {
public:
	virtual void visit(Array* type) = 0;
	virtual void visit(HashMapType* type) = 0;
	virtual void visit(SimpleType* type) = 0;
};

#endif CLASS_H_TYPE_VISITOR