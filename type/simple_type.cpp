#include "simple_type.h"
#include "type.h"
#include "type_visitor.h"

Type** simpleTypes;
std::map< std::string, int > *mapOfSimpleTypes=NULL;
std::string* simpleTypeNames;

void initTypes() {
	if (mapOfSimpleTypes == NULL) {
		simpleTypes = new Type*[SIMPLE_TYPES_AMOUNT];
		mapOfSimpleTypes = new std::map< std::string, int >();
		std::string a[] = { "integer", "double", "string", "void" };
		
		simpleTypeNames = new std::string[SIMPLE_TYPES_AMOUNT];

		for (int i = 0; i < SIMPLE_TYPES_AMOUNT; i++) {
			simpleTypes[i] = new SimpleType(i);
			simpleTypeNames[i] = a[i];

			(*mapOfSimpleTypes)[a[i]] = i;
		}
	}
}

Type *getTypeByName(std::string name) {
	initTypes();

	if (mapOfSimpleTypes->find(name) != mapOfSimpleTypes->end()) {
		return simpleTypes[mapOfSimpleTypes->find(name)->second];
	}

	return NULL;
}

Type *getTypeBySimpleTypeId(int id) {
	initTypes();

	return simpleTypes[id];
}

SimpleType::SimpleType(int _typeId) {
	id = _typeId;
}

std::string SimpleType::getId() const {
	return simpleTypeNames[id];
}

Type* SimpleType::getTypeAfterBinaryOperation(std::string op) {
	if (id == VOID_SIMPLE_TYPE)return NULL;
	if (op == "==" || op == "!=") {
		return this;
	}

	bool isNumeric = id == INTEGER_SIMPLE_TYPE || id == DOUBLE_SIMPLE_TYPE;

	if ((op.find('<') != std::string::npos || op.find('>') != std::string::npos) && isNumeric) {
		return getTypeBySimpleTypeId(INTEGER_SIMPLE_TYPE);
	}

	if ((op == "+" || op == "-" || op == "*") && isNumeric) {
		return this;
	}

	if (op == "/" && isNumeric) {
		return getTypeBySimpleTypeId(DOUBLE_SIMPLE_TYPE);
	}

	if ((op == "||" || op == "&&" || op == "div" || op  == "mod") && id == INTEGER_SIMPLE_TYPE) {
		return this;
	}

	return NULL;
}
Type* SimpleType::getTypeAfterUnaryOperation(std::string op) {
	if (id == VOID_SIMPLE_TYPE)return NULL;
	bool isNumeric = id == INTEGER_SIMPLE_TYPE || id == DOUBLE_SIMPLE_TYPE;

	if (op == "not") {
		if (id == INTEGER_SIMPLE_TYPE) {
			return this;
		}
	}

	if (op == "-") {
		if (isNumeric) {
			return this;
		}
	}

	return NULL;
}

void SimpleType::accept(TypeVisitor* visitor) {
	visitor->visit(this);
}