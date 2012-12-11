#include <map>
#include <string>

#ifndef CLASS_H_SIMPLE_TYPE
#define CLASS_H_SIMPLE_TYPE

#define SIMPLE_TYPES_AMOUNT 4
#include "type.h"

enum SIMPLE_TYPE {
	INTEGER_SIMPLE_TYPE = 0,
	DOUBLE_SIMPLE_TYPE = 1,
	STRING_SIMPLE_TYPE = 2,
	VOID_SIMPLE_TYPE = 3
};

Type *getTypeByName(std::string name);
Type *getTypeBySimpleTypeId(int id);

class SimpleType : public Type {
private:
	int id;
public:
	SimpleType(int simpleTypeId);
	virtual Type* getTypeAfterBinaryOperation(std::string op);
	virtual Type* getTypeAfterUnaryOperation(std::string op);
	virtual std::string getId() const;
};

#endif
