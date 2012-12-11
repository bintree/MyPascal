/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2010 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

// Take the name prefix into account.
#define yylex   generatedlex

/* First part of user declarations.  */

/* Line 310 of lalr1.cc  */
#line 1 "parser.yy"

#  include <stdio.h>

/* Line 310 of lalr1.cc  */
#line 14 "parser.yy"


#include "scanner.h"
#include "..\syntax_tree\syntax_tree.h"
#include <vector>
#include <utility>

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex lexer.lex
#define BEGIN_POSITION(a) std::make_pair(a.begin.line,a.begin.column)
#define END_POSITION(a) std::make_pair(a.end.line, a.end.column)
#define MAKE_TERMINAL_NODE(A, B) new Terminal(A,OTHER,BEGIN_POSITION(B),END_POSITION(B))


/* Line 310 of lalr1.cc  */
#line 64 "parser.tab.cc"


#include "parser.tab.hh"

/* User implementation prologue.  */


/* Line 316 of lalr1.cc  */
#line 73 "parser.tab.cc"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace generated {

/* Line 379 of lalr1.cc  */
#line 139 "parser.tab.cc"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Parser::Parser (class Scanner& lexer_yyarg, class AbstractNode **result_yyarg, class std::vector< class std::pair< string, class std::pair< int, int> > > &errors_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg),
      result (result_yyarg),
      errors (errors_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 677 of lalr1.cc  */
#line 105 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(2) - (1)].an),(yysemantic_stack_[(2) - (2)].an); }
    break;

  case 3:

/* Line 677 of lalr1.cc  */
#line 109 "parser.yy"
    { (yyval.an)=new Block(BEGIN_POSITION((yylocation_stack_[(2) - (1)])),(yysemantic_stack_[(2) - (1)].vn),(yysemantic_stack_[(2) - (2)].an),END_POSOTION((yylocation_stack_[(2) - (2)]))); }
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 113 "parser.yy"
    { (yyval.vn)=new std::vector<AbstractNode*>(); }
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 114 "parser.yy"
    { (yyval.vn)=(yysemantic_stack_[(2) - (2)].vn); }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 118 "parser.yy"
    { (yyval.vn)=new std::vector<AbstractNode*>(); }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 119 "parser.yy"
    { (yysemantic_stack_[(3) - (3)].vn)->push_back((yysemantic_stack_[(3) - (1)].an));(yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 123 "parser.yy"
    { (yyval.an)=new VariableDeclaration(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 9:

/* Line 677 of lalr1.cc  */
#line 127 "parser.yy"
    { (yyval.an)=new std::vector< AbstractNode* >(); }
    break;

  case 10:

/* Line 677 of lalr1.cc  */
#line 128 "parser.yy"
    { (yysemantic_stack_[(3) - (3)].an)->push_back((yysemantic_stack_[(3) - (1)].an)); (yyval.an)=(yysemantic_stack_[(3) - (3)].an); }
    break;

  case 11:

/* Line 677 of lalr1.cc  */
#line 129 "parser.yy"
    { (yysemantic_stack_[(3) - (3)].an)->push_back((yysemantic_stack_[(3) - (1)].an)); (yyval.an)=(yysemantic_stack_[(3) - (3)].an); }
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 130 "parser.yy"
    { yyerrok; }
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 134 "parser.yy"
    { (yyval.an)=new ProcedureDeclaration(BEGIN_POSITION((yylocation_stack_[(4) - (2)])),(yysemantic_stack_[(4) - (2)].an),(yysemantic_stack_[(4) - (4)].an),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 135 "parser.yy"
    { (yyval.an)=new ProcedureDeclaration(BEGIN_POSITION((yylocation_stack_[(7) - (2)])),(yysemantic_stack_[(7) - (2)].an),(yysemantic_stack_[(7) - (4)].an),(yysemantic_stack_[(7) - (7)].an),END_POSITION((yylocation_stack_[(7) - (7)]))); }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 139 "parser.yy"
    { (yyval.an)=new FunctionDeclaration(BEGIN_POSITION((yylocation_stack_[(6) - (1)])),(yysemantic_stack_[(6) - (2)].an),(yysemantic_stack_[(6) - (4)].an),(yysemantic_stack_[(6) - (5)].s),END_POSITION((yylocation_stack_[(6) - (6)]))); }
    break;

  case 16:

/* Line 677 of lalr1.cc  */
#line 140 "parser.yy"
    { (yyval.an)=new FunctionDeclaration(BEGIN_POSITION((yylocation_stack_[(10) - (1)])),(yysemantic_stack_[(10) - (2)].an),(yysemantic_stack_[(10) - (4)].an),(yysemantic_stack_[(10) - (7)].an),(yysemantic_stack_[(10) - (10)].an),END_POSITION((yylocation_stack_[(10) - (10)]))); }
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 144 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 145 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (2)].s); }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 146 "parser.yy"
    { yyerrok; }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 150 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (2)].s); }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 154 "parser.yy"
    { (yyval.an)=new std::vector<AbstractNode*>(); }
    break;

  case 22:

/* Line 677 of lalr1.cc  */
#line 155 "parser.yy"
    { (yysemantic_stack_[(3) - (2)].s)->push_back((yysemantic_stack_[(3) - (1)].an)); (yyval.an)=(yysemantic_stack_[(3) - (2)].s); }
    break;

  case 23:

/* Line 677 of lalr1.cc  */
#line 159 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 160 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 25:

/* Line 677 of lalr1.cc  */
#line 164 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 26:

/* Line 677 of lalr1.cc  */
#line 165 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 27:

/* Line 677 of lalr1.cc  */
#line 169 "parser.yy"
    { (yyval.an)=new AssignmentStatement(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)])); }
    break;

  case 28:

/* Line 677 of lalr1.cc  */
#line 173 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 29:

/* Line 677 of lalr1.cc  */
#line 174 "parser.yy"
    { (yyval.an)=new ProcedureStatement(BEGIN_POSITION((yylocation_stack_[(4) - (1)])),(yysemantic_stack_[(4) - (1)].an),(yysemantic_stack_[(4) - (3)].an),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 30:

/* Line 677 of lalr1.cc  */
#line 178 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 31:

/* Line 677 of lalr1.cc  */
#line 179 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 32:

/* Line 677 of lalr1.cc  */
#line 180 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 33:

/* Line 677 of lalr1.cc  */
#line 184 "parser.yy"
    { (yyval.an)=new CompoundStatement((yysemantic_stack_[(3) - (2)].an)); }
    break;

  case 34:

/* Line 677 of lalr1.cc  */
#line 188 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 35:

/* Line 677 of lalr1.cc  */
#line 189 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 36:

/* Line 677 of lalr1.cc  */
#line 193 "parser.yy"
    { (yyval.an)=new WhileStatement(BEGIN_POSITION((yylocation_stack_[(6) - (1)])),(yysemantic_stack_[(6) - (3)].an),(yysemantic_stack_[(6) - (6)].an),END_POSITION((yylocation_stack_[(6) - (6)]))); }
    break;

  case 37:

/* Line 677 of lalr1.cc  */
#line 197 "parser.yy"
    { (yyval.an)=new ForStatement(BEGIN_POSITION((yylocation_stack_[(8) - (1)])),(yysemantic_stack_[(8) - (2)].an),(yysemantic_stack_[(8) - (4)].an),(yysemantic_stack_[(8) - (6)].an),(yysemantic_stack_[(8) - (8)].an),END_POSITION((yylocation_stack_[(8) - (8)]))); }
    break;

  case 38:

/* Line 677 of lalr1.cc  */
#line 198 "parser.yy"
    { (yyval.an)=new ForStatement(BEGIN_POSITION((yylocation_stack_[(8) - (1)])),(yysemantic_stack_[(8) - (2)].an),(yysemantic_stack_[(8) - (4)].an),(yysemantic_stack_[(8) - (6)].an),(yysemantic_stack_[(8) - (8)].an),END_POSITION((yylocation_stack_[(8) - (8)]))); }
    break;

  case 39:

/* Line 677 of lalr1.cc  */
#line 202 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(7) - (1)].s); }
    break;

  case 40:

/* Line 677 of lalr1.cc  */
#line 206 "parser.yy"
    { (yyval.an)=NULL; }
    break;

  case 41:

/* Line 677 of lalr1.cc  */
#line 207 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(2) - (2)].an); }
    break;

  case 42:

/* Line 677 of lalr1.cc  */
#line 211 "parser.yy"
    { (yyval.an)=new std::vector<AbstractNode*>(); }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 212 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 213 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(3) - (1)].an); }
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 217 "parser.yy"
    { (yyval.an)=new UnaryOperator(BEGIN_POSITIN((yylocation_stack_[(2) - (1)])),(yysemantic_stack_[(2) - (1)].an),(yysemantic_stack_[(2) - (2)].an),END_POSITION((yylocation_stack_[(2) - (2)]))); }
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 218 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 219 "parser.yy"
    { (yyval.an)=new BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (2)].an),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 223 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 224 "parser.yy"
    { (yyval.an)=new BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (2)].an),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 50:

/* Line 677 of lalr1.cc  */
#line 228 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 51:

/* Line 677 of lalr1.cc  */
#line 229 "parser.yy"
    { (yyval.an)=new BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (2)].an),(yysemantic_stack_[(3) - (3)].an),END_POSOTION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 52:

/* Line 677 of lalr1.cc  */
#line 233 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 53:

/* Line 677 of lalr1.cc  */
#line 234 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 54:

/* Line 677 of lalr1.cc  */
#line 235 "parser.yy"
    { (yyval.an)=new Terminal((yysemantic_stack_[(1) - (1)].s),STRING_LITERAL,BEGIN_POSITION((yylocation_stack_[(1) - (1)])),END_POSITION((yylocation_stack_[(1) - (1)]))); }
    break;

  case 55:

/* Line 677 of lalr1.cc  */
#line 236 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 56:

/* Line 677 of lalr1.cc  */
#line 237 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(3) - (2)].an); }
    break;

  case 57:

/* Line 677 of lalr1.cc  */
#line 238 "parser.yy"
    { (yyval.an)=new UnaryOperator(BEGIN_POSITION((yylocation_stack_[(2) - (1)])),(yysemantic_stack_[(2) - (1)].s),(yysemantic_stack_[(2) - (2)].an),END_POSITION((yylocation_stack_[(2) - (2)]))); }
    break;

  case 58:

/* Line 677 of lalr1.cc  */
#line 242 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 59:

/* Line 677 of lalr1.cc  */
#line 243 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 60:

/* Line 677 of lalr1.cc  */
#line 244 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 61:

/* Line 677 of lalr1.cc  */
#line 245 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 62:

/* Line 677 of lalr1.cc  */
#line 246 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 63:

/* Line 677 of lalr1.cc  */
#line 247 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 64:

/* Line 677 of lalr1.cc  */
#line 251 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 65:

/* Line 677 of lalr1.cc  */
#line 252 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)]));}
    break;

  case 66:

/* Line 677 of lalr1.cc  */
#line 253 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 67:

/* Line 677 of lalr1.cc  */
#line 257 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 68:

/* Line 677 of lalr1.cc  */
#line 258 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 69:

/* Line 677 of lalr1.cc  */
#line 259 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 70:

/* Line 677 of lalr1.cc  */
#line 260 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 71:

/* Line 677 of lalr1.cc  */
#line 261 "parser.yy"
    { MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 72:

/* Line 677 of lalr1.cc  */
#line 265 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 73:

/* Line 677 of lalr1.cc  */
#line 266 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 74:

/* Line 677 of lalr1.cc  */
#line 270 "parser.yy"
    { (yyval.an)=new IndexedVariable(BEGIN_POSITION((yylocation_stack_[(4) - (1)])),(yysemantic_stack_[(4) - (1)].an),(yysemantic_stack_[(4) - (3)].an),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 75:

/* Line 677 of lalr1.cc  */
#line 274 "parser.yy"
    { (yyval.an)=new FunctionDesignator(BEGIN_POSITION((yylocation_stack_[(4) - (1)])),(yysemantic_stack_[(4) - (1)].an),(yysemantic_stack_[(4) - (3)].an),END_POSITION((yylocation_stack_[(4) - (4)])); }
    break;

  case 76:

/* Line 677 of lalr1.cc  */
#line 278 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 77:

/* Line 677 of lalr1.cc  */
#line 279 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 78:

/* Line 677 of lalr1.cc  */
#line 283 "parser.yy"
    { (yyval.an)=new SubrangeType(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),new Terminal((yysemantic_stack_[(3) - (1)].i),INTEGER_LITERAL,BEGIN_POSITION((yylocation_stack_[(3) - (1)])),END_POSITION((yylocation_stack_[(3) - (1)]))),Terminal((yysemantic_stack_[(3) - (3)].i),INTEGER_LITERAL,BEGIN_POSITION((yylocation_stack_[(3) - (3)])),END_POSITION((yylocation_stack_[(3) - (3)]))),END_POSOTION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 79:

/* Line 677 of lalr1.cc  */
#line 287 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 80:

/* Line 677 of lalr1.cc  */
#line 288 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 81:

/* Line 677 of lalr1.cc  */
#line 292 "parser.yy"
    { (yyval.an)=new ArrayType(BEGIN_POSITION((yylocation_stack_[(6) - (1)])),(yysemantic_stack_[(6) - (3)].an),(yysemantic_stack_[(6) - (6)].an), END_POSITION((yylocation_stack_[(6) - (6)]))); }
    break;

  case 82:

/* Line 677 of lalr1.cc  */
#line 296 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 83:

/* Line 677 of lalr1.cc  */
#line 297 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (3)].an); }
    break;

  case 84:

/* Line 677 of lalr1.cc  */
#line 301 "parser.yy"
    { (yyval.an)=new CollectionType(BEGIN_POSITION((yylocation_stack_[(4) - (1)])),(yysemantic_stack_[(4) - (1)].an),(yysemantic_stack_[(4) - (3)].an),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 85:

/* Line 677 of lalr1.cc  */
#line 305 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 86:

/* Line 677 of lalr1.cc  */
#line 306 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (3)].an); }
    break;

  case 87:

/* Line 677 of lalr1.cc  */
#line 310 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 88:

/* Line 677 of lalr1.cc  */
#line 311 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (3)].an); }
    break;

  case 89:

/* Line 677 of lalr1.cc  */
#line 315 "parser.yy"
    { (yyval.an) = new Terminal((yysemantic_stack_[(1) - (1)].i),INTEGER_LITERAL,BEGIN_POSITION((yylocation_stack_[(1) - (1)])),END_POSITION((yylocation_stack_[(1) - (1)]))); }
    break;

  case 90:

/* Line 677 of lalr1.cc  */
#line 316 "parser.yy"
    { (yyval.an) = new Terminal((yysemantic_stack_[(1) - (1)].d),DOUBLE_LITERAL,BEGIN_POSITION((yylocation_stack_[(1) - (1)])),END_POSITION((yylocation_stack_[(1) - (1)]))); }
    break;

  case 91:

/* Line 677 of lalr1.cc  */
#line 320 "parser.yy"
    { (yyval.an) = MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 92:

/* Line 677 of lalr1.cc  */
#line 321 "parser.yy"
    { (yyval.an) = MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 93:

/* Line 677 of lalr1.cc  */
#line 325 "parser.yy"
    { (yyval.an) = MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;



/* Line 677 of lalr1.cc  */
#line 1076 "parser.tab.cc"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Parser::yypact_ninf_ = -114;
  const short int
  Parser::yypact_[] =
  {
       106,    14,   -28,   -28,    59,    67,    58,    60,  -114,  -114,
      38,    41,  -114,   -28,  -114,    77,   106,   106,     2,    67,
       2,   -28,  -114,    83,    71,    84,    33,  -114,  -114,  -114,
      89,    91,    93,    78,  -114,   104,   105,   -28,     1,   -28,
     108,   -28,   109,   107,   110,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,   -22,  -114,    13,  -114,   111,     2,
     -28,   114,    67,  -114,    81,  -114,  -114,  -114,  -114,    90,
    -114,    48,   -16,  -114,    48,  -114,    33,    48,    48,    48,
      67,  -114,  -114,   -28,  -114,    82,   -28,    48,    19,  -114,
    -114,  -114,  -114,  -114,   117,    80,    -4,    50,    85,  -114,
    -114,    19,   119,    48,   120,  -114,  -114,   122,    92,   121,
     123,  -114,   126,   112,   127,    98,   113,   131,  -114,   124,
    -114,  -114,  -114,  -114,  -114,  -114,    19,  -114,  -114,  -114,
      19,  -114,  -114,  -114,  -114,  -114,    19,  -114,    48,    37,
     130,    48,  -114,  -114,    48,   118,    99,    82,   128,  -114,
    -114,    33,  -114,  -114,  -114,   133,    48,    48,    33,  -114,
    -114,    67,  -114,  -114,     1,  -114,  -114,   132,   134,   147,
    -114,  -114,    33,    33,    33,  -114,  -114,  -114,  -114
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     4,     0,     0,    12,    93,
       0,     0,     1,     0,     2,     0,     0,     0,     0,     4,
       0,     0,     5,     0,     0,    85,    21,     3,    10,    11,
       0,     0,    17,     0,    13,     0,     0,     6,     0,     0,
       0,     0,     0,     0,     0,    23,    25,    26,    24,    30,
      31,    34,    35,    32,     0,    73,    28,    19,     0,     0,
       0,     0,     4,     7,     0,     8,    76,    79,    80,    77,
      86,     0,     0,    72,     0,    33,    21,     0,     0,    42,
       4,    18,    20,     0,    15,     0,     0,     0,     0,    91,
      92,    54,    89,    90,     0,    46,    48,    50,    52,    55,
      53,     0,    72,     0,     0,    22,    27,    87,     0,     0,
      43,    14,     0,     0,    82,     0,     0,     0,    57,     0,
      58,    59,    60,    61,    62,    63,     0,    66,    64,    65,
       0,    71,    69,    70,    67,    68,     0,    45,    42,     0,
       0,     0,    74,    29,    42,     0,     0,     0,     0,    84,
      56,     0,    47,    49,    51,     0,     0,     0,     0,    88,
      44,     4,    78,    83,     0,    36,    75,     0,     0,    40,
      16,    81,     0,     0,     0,    39,    37,    38,    41
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -114,  -114,   -17,  -114,   129,  -114,    66,  -114,  -114,   -10,
    -114,    87,   -71,  -114,  -114,  -114,  -114,   144,  -114,  -114,
    -114,  -114,  -114,  -113,   -65,   -78,    25,    76,  -114,  -114,
    -114,   -21,  -114,  -114,     3,  -114,  -114,  -114,    18,  -114,
      -9,    27,  -114,  -114,    -2
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,     4,    14,    15,    22,    23,     5,     6,     7,    31,
      32,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,   175,   109,   110,    95,    96,    97,   126,   130,
     136,    98,    55,    99,    65,   114,    66,    67,   115,    68,
      33,   108,   100,   101,   102
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -73;
  const short int
  Parser::yytable_[] =
  {
        10,    11,    34,    30,    24,    54,    94,    64,    77,   104,
      35,    25,   106,   107,   103,   127,    25,     9,    25,    36,
      72,    78,   117,   137,    56,   155,    79,    78,    24,     8,
      70,   160,    87,   128,   129,    25,    69,    25,   139,    73,
      40,    41,    42,   -72,    26,    84,     9,     9,   152,    81,
      88,    18,   153,    19,    20,    54,   -72,    25,    82,    12,
     156,    87,   157,   111,     9,    91,    92,    93,   131,    21,
      13,   132,   133,    16,    56,    17,   107,   116,     9,    88,
     165,   112,    28,    29,    25,    89,    90,   169,    26,   134,
     135,   167,   168,     9,    91,    92,    93,   120,    37,    38,
      39,   176,   177,   178,    57,    58,    60,     1,    59,    -9,
       2,     3,   121,   122,   123,   124,   125,    -9,    61,    75,
      62,    71,    74,    86,    85,    76,    80,    83,    78,   113,
      54,   119,   138,   161,   140,   143,   142,    54,   141,   144,
     145,   146,   148,   147,   170,   150,   162,   166,   149,    56,
     151,    54,    54,    54,   158,   164,    56,   174,   172,    27,
     173,   154,    69,   105,   118,   163,    63,   171,   159,     0,
      56,    56,    56
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         2,     3,    19,     1,    13,    26,    71,     6,    30,    74,
      20,    13,    77,    78,    30,    19,    18,    45,    20,    21,
      41,    43,    87,   101,    26,   138,    13,    43,    37,    15,
      39,   144,    13,    37,    38,    37,    38,    39,   103,    41,
       7,     8,     9,    30,    11,    62,    45,    45,   126,    59,
      31,    13,   130,    15,    13,    76,    43,    59,    60,     0,
      23,    13,    25,    80,    45,    46,    47,    48,    18,    28,
       3,    21,    22,    15,    76,    15,   141,    86,    45,    31,
     151,    83,    16,    17,    86,    37,    38,   158,    11,    39,
      40,   156,   157,    45,    46,    47,    48,    17,    15,    28,
      16,   172,   173,   174,    15,    14,    28,     1,    15,     3,
       4,     5,    32,    33,    34,    35,    36,    11,    14,    12,
      15,    13,    13,    33,    43,    15,    15,    13,    43,    47,
     151,    14,    13,    15,    14,    14,    44,   158,    16,    16,
      14,    29,    44,    16,   161,    14,    47,    14,    35,   151,
      26,   172,   173,   174,    24,    27,   158,    10,    26,    15,
      26,   136,   164,    76,    88,   147,    37,   164,   141,    -1,
     172,   173,   174
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     1,     4,     5,    50,    55,    56,    57,    15,    45,
      93,    93,     0,     3,    51,    52,    15,    15,    13,    15,
      13,    28,    53,    54,    89,    93,    11,    66,    55,    55,
       1,    58,    59,    89,    51,    58,    93,    15,    28,    16,
       7,     8,     9,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    80,    81,    93,    15,    14,    15,
      28,    14,    15,    53,     6,    83,    85,    86,    88,    93,
      89,    13,    80,    93,    13,    12,    15,    30,    43,    13,
      15,    58,    93,    13,    51,    43,    33,    13,    31,    37,
      38,    46,    47,    48,    73,    74,    75,    76,    80,    82,
      91,    92,    93,    30,    73,    60,    73,    73,    90,    72,
      73,    51,    93,    47,    84,    87,    89,    73,    76,    14,
      17,    32,    33,    34,    35,    36,    77,    19,    37,    38,
      78,    18,    21,    22,    39,    40,    79,    74,    13,    73,
      14,    16,    44,    14,    16,    14,    29,    16,    44,    35,
      14,    26,    74,    74,    75,    72,    23,    25,    24,    90,
      72,    15,    47,    87,    27,    61,    14,    73,    73,    61,
      51,    83,    26,    26,    10,    71,    61,    61,    61
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    49,    50,    51,    52,    52,    53,    53,    54,    55,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    58,
      59,    60,    60,    61,    61,    62,    62,    63,    64,    64,
      65,    65,    65,    66,    67,    67,    68,    69,    69,    70,
      71,    71,    72,    72,    72,    73,    73,    73,    74,    74,
      75,    75,    76,    76,    76,    76,    76,    76,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    79,
      79,    79,    80,    80,    81,    82,    83,    83,    84,    85,
      85,    86,    87,    87,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     2,     2,     0,     2,     2,     3,     3,     0,
       3,     3,     2,     4,     7,     6,    10,     1,     3,     2,
       3,     0,     3,     1,     1,     1,     1,     3,     1,     4,
       1,     1,     1,     3,     1,     1,     6,     8,     8,     7,
       0,     2,     0,     1,     3,     2,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     1,     1,     3,     1,
       1,     6,     1,     3,     4,     1,     3,     1,     3,     1,
       1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "VAR", "PROCEDURE",
  "FUNCTION", "ARRAY", "WHILE", "FOR", "IF", "ELSE", "BEGINST", "ENDST",
  "LEFTPAR", "RIGHTPAR", "SEMICOLON", "COMMA", "EQUALS", "AND", "OR",
  "TYPE", "DIV", "MOD", "TO", "THEN", "DOWNTO", "DO", "OF", "COLON",
  "DOTDOT", "ASSIGN", "NOT", "NOTEQUAL", "LESS", "LESSOREQUAL", "MORE",
  "MOREOREQUAL", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "LEFTBRACE",
  "RIGHTBRACE", "LEFTBRACKET", "RIGHTBRACKET", "IDENT", "STRING_LITERAL",
  "INTEGER_LITERAL", "DOUBLE_LITERAL", "$accept", "program", "block",
  "variable_declaration_part", "variable_declaration_list",
  "variable_declaration", "procedure_and_function_declaration",
  "procedure_declaration", "function_declaration", "formal_parameter_list",
  "formal_parameter_section", "statement_sequence", "statement",
  "simple_statement", "assignment_statement", "procedure_statement",
  "structured_statement", "compound_statement", "repetitive_statement",
  "while_statement", "for_statement", "if_statement", "else_expression",
  "actual_parameter_list", "expression", "simple_expression", "term",
  "factor", "relational_operator", "addition_operator",
  "multiplication_operator", "variable", "indexed_variable",
  "function_designator", "type", "subrange_type", "structured_type",
  "array_type", "index_type_list", "collection_type", "identifier_list",
  "expression_list", "number", "sign", "ident_terminal", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        50,     0,    -1,    55,    51,    -1,    52,    66,    -1,    -1,
       3,    53,    -1,    54,    15,    -1,    54,    15,    53,    -1,
      89,    28,    83,    -1,    -1,    56,    15,    55,    -1,    57,
      15,    55,    -1,     1,    15,    -1,     4,    93,    15,    51,
      -1,     4,    93,    13,    58,    14,    15,    51,    -1,     5,
      93,    28,    93,    15,    51,    -1,     5,    93,    13,    58,
      14,    13,    93,    14,    15,    51,    -1,    59,    -1,    59,
      15,    58,    -1,     1,    15,    -1,    89,    28,    93,    -1,
      -1,    61,    15,    60,    -1,    62,    -1,    65,    -1,    63,
      -1,    64,    -1,    80,    30,    73,    -1,    93,    -1,    93,
      13,    72,    14,    -1,    66,    -1,    67,    -1,    70,    -1,
      11,    60,    12,    -1,    68,    -1,    69,    -1,     7,    13,
      73,    14,    26,    61,    -1,     8,    80,    30,    73,    23,
      73,    26,    61,    -1,     8,    80,    30,    73,    25,    73,
      26,    61,    -1,     9,    13,    73,    14,    24,    61,    71,
      -1,    -1,    10,    61,    -1,    -1,    73,    -1,    73,    16,
      72,    -1,    92,    74,    -1,    74,    -1,    74,    77,    74,
      -1,    75,    -1,    75,    78,    74,    -1,    76,    -1,    76,
      79,    75,    -1,    80,    -1,    91,    -1,    46,    -1,    82,
      -1,    13,    73,    14,    -1,    31,    76,    -1,    17,    -1,
      32,    -1,    33,    -1,    34,    -1,    35,    -1,    36,    -1,
      37,    -1,    38,    -1,    19,    -1,    39,    -1,    40,    -1,
      21,    -1,    22,    -1,    18,    -1,    93,    -1,    81,    -1,
      80,    43,    90,    44,    -1,    93,    13,    72,    14,    -1,
      85,    -1,    93,    -1,    47,    29,    47,    -1,    86,    -1,
      88,    -1,     6,    43,    87,    44,    27,    83,    -1,    84,
      -1,    84,    16,    87,    -1,    93,    33,    89,    35,    -1,
      93,    -1,    93,    16,    89,    -1,    73,    -1,    73,    16,
      90,    -1,    47,    -1,    48,    -1,    37,    -1,    38,    -1,
      45,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    10,    13,    16,    20,    24,
      25,    29,    33,    36,    41,    49,    56,    67,    69,    73,
      76,    80,    81,    85,    87,    89,    91,    93,    97,    99,
     104,   106,   108,   110,   114,   116,   118,   125,   134,   143,
     151,   152,   155,   156,   158,   162,   165,   167,   171,   173,
     177,   179,   183,   185,   187,   189,   191,   195,   198,   200,
     202,   204,   206,   208,   210,   212,   214,   216,   218,   220,
     222,   224,   226,   228,   230,   235,   240,   242,   244,   248,
     250,   252,   259,   261,   265,   270,   272,   276,   278,   282,
     284,   286,   288,   290
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   105,   105,   109,   113,   114,   118,   119,   123,   127,
     128,   129,   130,   134,   135,   139,   140,   144,   145,   146,
     150,   154,   155,   159,   160,   164,   165,   169,   173,   174,
     178,   179,   180,   184,   188,   189,   193,   197,   198,   202,
     206,   207,   211,   212,   213,   217,   218,   219,   223,   224,
     228,   229,   233,   234,   235,   236,   237,   238,   242,   243,
     244,   245,   246,   247,   251,   252,   253,   257,   258,   259,
     260,   261,   265,   266,   270,   274,   278,   279,   283,   287,
     288,   292,   296,   297,   301,   305,   306,   310,   311,   315,
     316,   320,   321,   325
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 172;
  const int Parser::yynnts_ = 45;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 12;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 49;

  const unsigned int Parser::yyuser_token_number_max_ = 303;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


} // generated

/* Line 1053 of lalr1.cc  */
#line 1666 "parser.tab.cc"


/* Line 1055 of lalr1.cc  */
#line 327 "parser.yy"



void generated::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
     errors.push_back(std::make_pair(m, std::make_pair(l.begin.line, l.begin.column)));
}

