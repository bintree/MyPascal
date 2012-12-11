#include "lexer.h"

Lexer::Lexer(std::istream* in) {
	scanner = new generated::Scanner(in, &std::cout); 
}

Lexeme Lexer::next_token() {
	generated::Parser::token_type type;
	generated::Parser::semantic_type val;
	while (true) {
		Lexeme current;
		type = scanner->lex(&val, &loc);
		current.column = loc.begin.column;
		current.line = loc.begin.line;
		if (!type) {
			current.type = "EOF";
			current.value = "EOF";
			return current;
		}

		
		current.value = val.s;

		switch(type) {
			case generated::Parser::token_type::VAR:
				current.type = "VAR";
				break;
			case generated::Parser::token_type::PROCEDURE:
				current.type = "PROCEDURE";
				break;
			case generated::Parser::token_type::FUNCTION:
				current.type = "FUNCTION";
				break;
			case generated::Parser::token_type::ARRAY:
				current.type = "ARRAY";
				break;
			case generated::Parser::token_type::WHILE:
				current.type = "WHILE";
				break;
			case generated::Parser::token_type::FOR:
				current.type = "FOR";
				break;
			case generated::Parser::token_type::IF:
				current.type = "IF";
				break;
			case generated::Parser::token_type::ELSE:
				current.type = "ELSE";
				break;
			case generated::Parser::token_type::OR:
				current.type = "OR";
				break;
			case generated::Parser::token_type::DIV:
				current.type = "DIV";
				break;
			case generated::Parser::token_type::MOD:
				current.type = "MOD";
				break;
			case generated::Parser::token_type::AND:
				current.type = "AND";
				break;
			case generated::Parser::token_type::RECORD:
				current.type = "RECORD";
				break;
			case generated::Parser::token_type::BEGINST:
				current.type = "BEGINST";
				break;
			case generated::Parser::token_type::ENDST:
				current.type = "ENDST";
				break;
			case generated::Parser::token_type::DOT:
				current.type = "DOT";
				break;
			case generated::Parser::token_type::LEFTPAR:
				current.type = "LEFTPAR";
				break;
			case generated::Parser::token_type::RIGTHPAR:
				current.type = "RIGTHPAR";
				break;
			case generated::Parser::token_type::SEMICOLON:
				current.type = "SEMICOLON";
				break;
			case generated::Parser::token_type::COMMA:
				current.type = "COMMA";
				break;
			case generated::Parser::token_type::EQUALS:
				current.type = "EQUALS";
				break;
			case generated::Parser::token_type::COLON:
				current.type = "COLON";
				break;
			case generated::Parser::token_type::DOTDOT:
				current.type = "DOTDOT";
				break;
			case generated::Parser::token_type::ASSIGN:
				current.type = "ASSIGN";
				break;
			case generated::Parser::token_type::NOT:
				current.type = "NOT";
				break;
			case generated::Parser::token_type::NOTEQUAL:
				current.type = "NOTEQUAL";
				break;
			case generated::Parser::token_type::LESS:
				current.type = "LESS";
				break;
			case generated::Parser::token_type::LESSOREQUAL:
				current.type = "LESSOREQUAL";
				break;
			case generated::Parser::token_type::MORE:
				current.type = "MORE";
				break;
			case generated::Parser::token_type::MOREOREQUAL:
				current.type = "MOREOREQUAL";
				break;
			case generated::Parser::token_type::PLUS:
				current.type = "PLUS";
				break;
			case generated::Parser::token_type::MINUS:
				current.type = "MINUS";
				break;
			case generated::Parser::token_type::MULTIPLY:
				current.type = "MULTIPLY";
				break;
			case generated::Parser::token_type::DIVIDE:
				current.type = "DIVIDE";
				break;
			case generated::Parser::token_type::LEFTBRACE:
				current.type = "LEFTBRACE";
				break;
			case generated::Parser::token_type::RIGHTBRACE:
				current.type = "RIGHTBRACE";
				break;
			case generated::Parser::token_type::LEFTBRACKET:
				current.type = "LEFTBRACKET";
				break;
			case generated::Parser::token_type::RIGHTBRACKET:
				current.type = "RIGHTBRACKET";
				break;
			case generated::Parser::token_type::STRING_LITERAL:
				current.type = "STRING_LITERAL";
				break;
			case generated::Parser::token_type::INTEGER_LITERAL:
				current.type = "INTEGER_LITERAL";
				break;
			case generated::Parser::token_type::DOUBLE_LITERAL:
				current.type = "DOUBLE_LITERAL";
				break;
			case generated::Parser::token_type::IDENT:
				current.type = "IDENT";
				break;
			default:
				current.type = "<unknown>";
				break;
		}
		return current;
	}
	
}