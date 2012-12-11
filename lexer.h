#include <stdio.h>
#include <fstream>
#include <iostream>
#include "generated/scanner.h"

#ifndef MY_LEXER_H
#define MY_LEXER_H

class Lexeme {
public:
	char *type;
	int line;
	int column;
	char *value;
};

class Lexer {
public:
	Lexer(std::istream* in);
	Lexeme next_token();
private:
	generated::Scanner* scanner;
	generated::Parser::location_type loc;
};

#endif