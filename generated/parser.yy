%{
#  include <stdio.h>
%}

%defines

%debug
%expect 1

%skeleton "lalr1.cc"


%name-prefix="generated"

%{

#include "../syntax_tree/syntax_tree.h"
#include <vector>
#include <utility>

#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex lexer.lex
#define BEGIN_POSITION(a) std::make_pair(a.begin.line,a.begin.column)
#define END_POSITION(a) std::make_pair(a.end.line, a.end.column)
#define MAKE_TERMINAL_NODE(A, B) new syntax_tree::Terminal((A),syntax_tree::OTHER,BEGIN_POSITION(B),END_POSITION(B))
#define NEW_NODE_VECTOR new std::vector< syntax_tree::AbstractNode* >()
%}

%define "parser_class_name" "Parser"
%locations

%parse-param { class Scanner &lexer }
%parse-param { syntax_tree::AbstractNode* &result }
%parse-param { std::vector< std::pair< std::string, std::pair< int, int> > > &errors }
%error-verbose


%token <s> VAR PROCEDURE FUNCTION ARRAY WHILE FOR IF ELSE BEGINST ENDST LEFTPAR RIGHTPAR SEMICOLON COMMA EQUALS AND OR TYPE DIV MOD TO THEN DOWNTO DO OF
%token <s> COLON DOT DOTDOT ASSIGN NOT NOTEQUAL LESS LESSOREQUAL MORE MOREOREQUAL PLUS MINUS MULTIPLY DIVIDE LEFTBRACE RIGHTBRACE LEFTBRACKET RIGHTBRACKET
%token <s> IDENT
%token <s> STRING_LITERAL
%token <s> INTEGER_LITERAL
%token <s> DOUBLE_LITERAL

%token END	     0	"end of file"

%union {
	double d;
	int i;
	char* s;
	class syntax_tree::AbstractNode* an;
	class std::vector<class syntax_tree::AbstractNode*> * vn;
}

%left ELSE 
%left EQUALS NOTEQUAL LESS LESSOREQUAL MORE MOREOREQUAL OR
%left NOT
%left PLUS MINUS
%left DIV MULTIPLY DIVIDE MOD AND
%left UMINUS

%type <an> program
%type <an> block
%type <vn> variable_declaration_part
%type <vn> variable_declaration_list
%type <an> variable_declaration
%type <vn> procedure_and_function_declaration
%type <an> procedure_declaration
%type <an> function_declaration
%type <vn> formal_parameter_list
%type <an> formal_parameter_section
%type <vn> statement_sequence
%type <an> statement
%type <an> simple_statement
%type <an> assignment_statement
%type <an> procedure_statement
%type <an> structured_statement
%type <an> compound_statement
%type <an> repetitive_statement
%type <an> while_statement
%type <an> for_statement
%type <an> if_statement
%type <an> else_expression
%type <vn> actual_parameter_list
%type <an> expression
%type <an> variable
%type <an> indexed_variable
%type <an> function_designator
%type <an> type
%type <an> subrange_type
%type <an> structured_type
%type <an> array_type
%type <vn> index_type_list
%type <an> collection_type
%type <vn> identifier_list
%type <vn> expression_list
%type <an> number
%type <an> ident_terminal

%%
program :
procedure_and_function_declaration block DOT { $$=new syntax_tree::Program(BEGIN_POSITION(@1),$1,$2,END_POSITION(@2)); result = $$; }
;

block :
variable_declaration_part compound_statement { $$=new syntax_tree::Block(BEGIN_POSITION(@1),$1,$2,END_POSITION(@2)); }
;

variable_declaration_part :
 { $$=new std::vector<syntax_tree::AbstractNode*>(); }
| VAR variable_declaration_list { $$=$2; }
;

variable_declaration_list :
variable_declaration SEMICOLON { $$=new std::vector<syntax_tree::AbstractNode*>();$$->push_back($1); }
| variable_declaration SEMICOLON variable_declaration_list { $3->push_back($1);$$=$3; }
;

variable_declaration :
identifier_list COLON  type { $$=new syntax_tree::VariableDeclaration(BEGIN_POSITION(@1),$1,$3,END_POSITION(@3)); }
;

procedure_and_function_declaration :
 { $$=new std::vector< syntax_tree::AbstractNode* >(); }
| procedure_declaration SEMICOLON procedure_and_function_declaration { $3->push_back($1); $$=$3; }
| function_declaration SEMICOLON procedure_and_function_declaration { $3->push_back($1); $$=$3; }
| error SEMICOLON { yyerrok; }
;

procedure_declaration :
PROCEDURE ident_terminal SEMICOLON block { $$=new syntax_tree::ProcedureDeclaration(BEGIN_POSITION(@2),$2,$4,new std::vector< syntax_tree::AbstractNode* >(),END_POSITION(@4)); }
| PROCEDURE ident_terminal LEFTPAR formal_parameter_list RIGHTPAR SEMICOLON block { $$=new syntax_tree::ProcedureDeclaration(BEGIN_POSITION(@2),$2,$7,$4,END_POSITION(@7)); }
;

function_declaration :
FUNCTION ident_terminal COLON ident_terminal SEMICOLON block { $$=new syntax_tree::FunctionDeclaration(BEGIN_POSITION(@1),$2,NEW_NODE_VECTOR,$4,$6,END_POSITION(@6)); }
| FUNCTION ident_terminal LEFTPAR formal_parameter_list RIGHTPAR COLON ident_terminal SEMICOLON block { $$=new syntax_tree::FunctionDeclaration(BEGIN_POSITION(@1),$2,$4,$7,$9,END_POSITION(@9)); }
;

formal_parameter_list :
	{ $$=NEW_NODE_VECTOR; }
| formal_parameter_section SEMICOLON formal_parameter_list { $3->push_back($1); $$=$3; }
| error SEMICOLON { yyerrok; }
;

formal_parameter_section :
identifier_list COLON ident_terminal { $$=new syntax_tree::FormalParameterSection(BEGIN_POSITION(@1),$1,$3, END_POSITION(@3)); }
;

statement_sequence :
 { $$=new std::vector<syntax_tree::AbstractNode*>(); }
| statement SEMICOLON statement_sequence { $3->push_back($1); $$=$3; }
;

statement :
simple_statement { $$=$1; }
| structured_statement { $$=$1; }
;

simple_statement :
assignment_statement { $$=$1; }
| procedure_statement { $$=$1; }
;

assignment_statement :
variable ASSIGN expression { $$=new syntax_tree::AssignmentStatement(BEGIN_POSITION(@1),$1,$3,END_POSITION(@3)); }
;

procedure_statement :
ident_terminal { $$=$1; }
| ident_terminal LEFTPAR actual_parameter_list RIGHTPAR { $$=new syntax_tree::ProcedureStatement(BEGIN_POSITION(@1),$1,$3,END_POSITION(@4)); }
;

structured_statement :
compound_statement { $$=$1; }
| repetitive_statement { $$=$1; }
| if_statement { $$=$1; }
;

compound_statement :
BEGINST statement_sequence ENDST { $$=new syntax_tree::CompoundStatement(BEGIN_POSITION(@1), $2, END_POSITION(@3)); }
;

repetitive_statement :
while_statement { $$=$1; }
| for_statement { $$=$1; }
;

while_statement :
WHILE LEFTPAR expression RIGHTPAR DO statement { $$=new syntax_tree::WhileStatement(BEGIN_POSITION(@1),$3,$6,END_POSITION(@6)); }
;

for_statement :
FOR variable ASSIGN expression TO expression DO statement { $$=new syntax_tree::ForStatement(BEGIN_POSITION(@1),$2,$4,$6,$8,END_POSITION(@8)); }
| FOR variable ASSIGN expression DOWNTO expression DO statement { $$=new syntax_tree::ForStatement(BEGIN_POSITION(@1),$2,$4,$6,$8,END_POSITION(@8)); }
;

if_statement :
IF LEFTPAR expression RIGHTPAR  THEN statement else_expression { $$=new syntax_tree::IfStatement(BEGIN_POSITION(@1),$3, $6, $7,END_POSITION(@7) ); }
;

else_expression :
{ $$=NULL; }
| ELSE statement { $$=$2; }
;

actual_parameter_list :
 { $$=new std::vector<syntax_tree::AbstractNode*>(); }
| expression { $$=NEW_NODE_VECTOR; $$->push_back($1); }
| expression COMMA actual_parameter_list { $$=$3; $3->push_back($1); }
;

expression :
MINUS expression %prec UMINUS { $$=new syntax_tree::UnaryOperator(BEGIN_POSITION(@1),MAKE_TERMINAL_NODE("-", @1), $2,END_POSITION(@2)); }
| expression AND expression { $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE("&&", @2),$3,END_POSITION(@3)); } 
| expression MOD expression { $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE("mod", @2),$3,END_POSITION(@3)); } 
| expression DIV expression { $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE("div", @2),$3,END_POSITION(@3)); } 
| expression DIVIDE expression { $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE("/", @2),$3,END_POSITION(@3)); } 
| expression MULTIPLY expression { $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE("*", @2),$3,END_POSITION(@3)); } 
| expression PLUS expression {  $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE("+", @2),$3,END_POSITION(@3)); } 
| expression MINUS expression { $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE("-", @2),$3,END_POSITION(@3)); } 
| expression OR expression { $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE("||", @2),$3,END_POSITION(@3)); } 
| expression MOREOREQUAL expression { $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE(">=", @2),$3,END_POSITION(@3)); } 
| expression MORE expression { $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE(">", @2),$3,END_POSITION(@3)); } 
| expression LESSOREQUAL expression { $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE("<=", @2),$3,END_POSITION(@3)); } 
| expression LESS expression { $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE("<", @2),$3,END_POSITION(@3)); } 
| expression NOTEQUAL expression { $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE("!=", @2),$3,END_POSITION(@3)); } 
| expression EQUALS expression { $$=new syntax_tree::BinaryOperator(BEGIN_POSITION(@1),$1,MAKE_TERMINAL_NODE("==", @2),$3,END_POSITION(@3)); } 
| variable { $$=$1; }
| number { $$=$1; }
| STRING_LITERAL { $$=new syntax_tree::Terminal($1,syntax_tree::STRING_LITERAL,BEGIN_POSITION(@1),END_POSITION(@1)); }
| function_designator { $$=$1; }
| LEFTPAR expression RIGHTPAR { $$=$2; }
| NOT expression { $$=new syntax_tree::UnaryOperator(BEGIN_POSITION(@1),MAKE_TERMINAL_NODE("not", @1),$2,END_POSITION(@2)); }
;

variable :
ident_terminal { $$=new syntax_tree::Variable(BEGIN_POSITION(@1),$1,END_POSITION(@1)); }
| indexed_variable { $$=$1; }
;

indexed_variable :
variable LEFTBRACKET expression_list RIGHTBRACKET { $$=new syntax_tree::IndexedVariable(BEGIN_POSITION(@1),$1,$3,END_POSITION(@4)); }
;

function_designator :
ident_terminal LEFTPAR actual_parameter_list RIGHTPAR { $$=new syntax_tree::FunctionDesignator(BEGIN_POSITION(@1),$1,$3,END_POSITION(@4)); }
;

type :
structured_type { $$=$1; }
| ident_terminal { $$=$1; }
;

subrange_type :
INTEGER_LITERAL DOTDOT INTEGER_LITERAL { 
	$$=new syntax_tree::SubrangeType(
		BEGIN_POSITION(@1),
		new syntax_tree::Terminal($1,syntax_tree::INTEGER_LITERAL,BEGIN_POSITION(@1),END_POSITION(@1)),
		new syntax_tree::Terminal($3,syntax_tree::INTEGER_LITERAL,BEGIN_POSITION(@3),END_POSITION(@3)),
		END_POSITION(@3)
	); }
;

structured_type :
array_type { $$=$1; }
| collection_type { $$=$1; }
;

array_type :
ARRAY LEFTBRACKET index_type_list RIGHTBRACKET OF type { $$=new syntax_tree::ArrayType(BEGIN_POSITION(@1),$3,$6, END_POSITION(@6)); }
;

index_type_list :
subrange_type { $$=NEW_NODE_VECTOR; $$->push_back($1); }
| subrange_type COMMA index_type_list { $$=$3; $$->push_back($1); }
;

collection_type :
ident_terminal LESS identifier_list MORE { $$=new syntax_tree::CollectionType(BEGIN_POSITION(@1),$1,$3,END_POSITION(@4)); }
;

identifier_list :
ident_terminal { $$=NEW_NODE_VECTOR; $$->push_back($1); }
| ident_terminal COMMA identifier_list { $$=$3; $$->push_back($1); }
;

expression_list :
expression { $$=NEW_NODE_VECTOR; $$->push_back($1); }
| expression COMMA expression_list { $$=$3; $$->push_back($1); }
;

number :
INTEGER_LITERAL { $$ = new syntax_tree::Terminal($1,syntax_tree::INTEGER_LITERAL,BEGIN_POSITION(@1),END_POSITION(@1)); }
| DOUBLE_LITERAL { $$ = new syntax_tree::Terminal($1,syntax_tree::DOUBLE_LITERAL,BEGIN_POSITION(@1),END_POSITION(@1)); }
;

ident_terminal :
IDENT { $$ = MAKE_TERMINAL_NODE($1, @1); }

%%


void generated::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
     errors.push_back(std::make_pair(m, std::make_pair(l.begin.line, l.begin.column)));
}
