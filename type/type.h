#include<string>


#ifndef CLASS_H_TYPE
#define CLASS_H_TYPE

class Type {
public:
	virtual std::string getId() const = 0;
	virtual void accept(class TypeVisitor* visitor) = 0;
	virtual Type* getTypeAfterArrayDereferencing(Type *type);
	virtual Type* getTypeAfterBinaryOperation(std::string op);
	virtual Type* getTypeAfterUnaryOperation(std::string op);
	virtual std::string getName();
	virtual bool operator==(const Type &other);
	virtual bool operator!=(const Type &other);
};

#endif