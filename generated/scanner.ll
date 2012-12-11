%{ /*** C/C++ Declarations ***/

#include <string>
#include <cstring>

#include "scanner.h"

typedef generated::Parser::token token;
typedef generated::Parser::token_type token_type;

#define yyterminate() return token::END

#define YY_NO_UNISTD_H

%}
/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++


/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

/* no support for include files is planned */
%option yywrap nounput case-insensitive

%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
#define RETURN_TOKEN(__a) yylval->s = yytext; return token::__a;
%}
%option prefix="Abstract"

%x STRING

%% 

%{
    // reset location
    yylloc->step();
    std::string litString = "";	
%}
<INITIAL>"'"	{ litString = ""; BEGIN STRING; }
<STRING>"\\'"                           { litString.append(1,'\''); }
<STRING>"'"                             { BEGIN INITIAL; strcpy(yytext, litString.c_str()); RETURN_TOKEN(STRING_LITERAL); }
<STRING>[^\n\r\'\\]+                   { litString.append( yytext ); }
<STRING>"\\\\"                         { litString.append(1, '\\\\'); }
<STRING>"\\t"                          { litString.append(1, '\t'); }
<STRING>\n                             { litString.append(1, '\n'); yylloc->lines(yyleng); }
<STRING>"\\n"                          { litString.append(1, '\n'); }
<STRING>"\\r"|\r                       { litString.append(1,'\r'); }


"type"             { RETURN_TOKEN(TYPE) }
"var"             { RETURN_TOKEN(VAR) }
"procedure"             { RETURN_TOKEN(PROCEDURE) }
"function"             { RETURN_TOKEN(FUNCTION) }
"array"             { RETURN_TOKEN(ARRAY) }
"while"             { RETURN_TOKEN(WHILE) }
"for"             { RETURN_TOKEN(FOR) }
"if"             { RETURN_TOKEN(IF) }
"else"             { RETURN_TOKEN(ELSE) }
"||"             { RETURN_TOKEN(OR) }
"div"             { RETURN_TOKEN(DIV) }
"mod"             { RETURN_TOKEN(MOD) }
"&&"             { RETURN_TOKEN(AND) }
"to"		{ RETURN_TOKEN(TO) }
"then"		{ RETURN_TOKEN(THEN) }	
"downto"	{ RETURN_TOKEN(DOWNTO) }
"do"		{ RETURN_TOKEN(DO) }
"of"		{ RETURN_TOKEN(OF) }
"begin"             { RETURN_TOKEN(BEGINST) }
"end"             { RETURN_TOKEN(ENDST) }
"."             { RETURN_TOKEN(DOT) }
"("             { RETURN_TOKEN(LEFTPAR) }
")"             { RETURN_TOKEN(RIGHTPAR) }
";"             { RETURN_TOKEN(SEMICOLON) }
","             { RETURN_TOKEN(COMMA) }
"=="             { RETURN_TOKEN(EQUALS) }
":"             { RETURN_TOKEN(COLON) }
".."             { RETURN_TOKEN(DOTDOT) }
":="             { RETURN_TOKEN(ASSIGN) }
"not"             { RETURN_TOKEN(NOT) }
"!="             { RETURN_TOKEN(NOTEQUAL) }
"<"             { RETURN_TOKEN(LESS) }
"<="             { RETURN_TOKEN(LESSOREQUAL) }
">"             { RETURN_TOKEN(MORE) }
">="             { RETURN_TOKEN(MOREOREQUAL) }
"+"             { RETURN_TOKEN(PLUS) }
"-"             { RETURN_TOKEN(MINUS) }
"*"             { RETURN_TOKEN(MULTIPLY) }
"/"             { RETURN_TOKEN(DIVIDE) }
"{"             { RETURN_TOKEN(LEFTBRACE) }
"}"             { RETURN_TOKEN(RIGHTBRACE) }
"["             { RETURN_TOKEN(LEFTBRACKET) }
"]"             { RETURN_TOKEN(RIGHTBRACKET) }


[1-9][0-9]*\.[0-9]+		       { yylval->d = atof(yytext); RETURN_TOKEN(DOUBLE_LITERAL);}
[1-9][0-9]*			       { yylval->i = atoi(yytext); RETURN_TOKEN(INTEGER_LITERAL);}

[a-zA-Z_][a-zA-Z_0-9]*		       { RETURN_TOKEN(IDENT); }


[ \t\r]+ {
    yylloc->step();
}

\n {
    yylloc->lines(yyleng); yylloc->step();
}

. 	{ printf("error\n");  }

%%
namespace generated {

Scanner::Scanner(std::istream* in,
		 std::ostream* out)
    : AbstractFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}


#ifdef yylex
#undef yylex
#endif

int AbstractFlexLexer::yylex()
{
    std::cerr << "in ExampleFlexLexer::yylex() !" << std::endl;
    return 0;
}

int AbstractFlexLexer::yywrap()
{
    return 1;
}
