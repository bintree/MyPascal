LEX = flex
YACC = bison

all: scanner.cc parser.cc

parser.cc: parser.yy
	$(YACC) -o parser.cc --defines=parser.h parser.yy

scanner.cc: scanner.ll parser.yy
	$(LEX) -o scanner.cc scanner.ll


