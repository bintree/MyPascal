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

/* Line 313 of lalr1.cc  */
#line 1 "parser.yy"

#  include <stdio.h>

/* Line 313 of lalr1.cc  */
#line 15 "parser.yy"


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


/* Line 313 of lalr1.cc  */
#line 66 "parser.cc"


#include "parser.h"

/* User implementation prologue.  */


/* Line 319 of lalr1.cc  */
#line 75 "parser.cc"

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

/* Line 382 of lalr1.cc  */
#line 141 "parser.cc"
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
  Parser::Parser (class Scanner &lexer_yyarg, syntax_tree::AbstractNode* &result_yyarg, std::vector< std::pair< std::string, std::pair< int, int> > > &errors_yyarg)
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

/* Line 680 of lalr1.cc  */
#line 105 "parser.yy"
    { (yyval.an)=new syntax_tree::Program(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].vn),(yysemantic_stack_[(3) - (2)].an),END_POSITION((yylocation_stack_[(3) - (2)]))); result = (yyval.an); }
    break;

  case 3:

/* Line 680 of lalr1.cc  */
#line 109 "parser.yy"
    { (yyval.an)=new syntax_tree::Block(BEGIN_POSITION((yylocation_stack_[(2) - (1)])),(yysemantic_stack_[(2) - (1)].vn),(yysemantic_stack_[(2) - (2)].an),END_POSITION((yylocation_stack_[(2) - (2)]))); }
    break;

  case 4:

/* Line 680 of lalr1.cc  */
#line 113 "parser.yy"
    { (yyval.vn)=new std::vector<syntax_tree::AbstractNode*>(); }
    break;

  case 5:

/* Line 680 of lalr1.cc  */
#line 114 "parser.yy"
    { (yyval.vn)=(yysemantic_stack_[(2) - (2)].vn); }
    break;

  case 6:

/* Line 680 of lalr1.cc  */
#line 118 "parser.yy"
    { (yyval.vn)=new std::vector<syntax_tree::AbstractNode*>();(yyval.vn)->push_back((yysemantic_stack_[(2) - (1)].an)); }
    break;

  case 7:

/* Line 680 of lalr1.cc  */
#line 119 "parser.yy"
    { (yysemantic_stack_[(3) - (3)].vn)->push_back((yysemantic_stack_[(3) - (1)].an));(yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); }
    break;

  case 8:

/* Line 680 of lalr1.cc  */
#line 123 "parser.yy"
    { (yyval.an)=new syntax_tree::VariableDeclaration(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].vn),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 9:

/* Line 680 of lalr1.cc  */
#line 127 "parser.yy"
    { (yyval.vn)=new std::vector< syntax_tree::AbstractNode* >(); }
    break;

  case 10:

/* Line 680 of lalr1.cc  */
#line 128 "parser.yy"
    { (yysemantic_stack_[(3) - (3)].vn)->push_back((yysemantic_stack_[(3) - (1)].an)); (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); }
    break;

  case 11:

/* Line 680 of lalr1.cc  */
#line 129 "parser.yy"
    { (yysemantic_stack_[(3) - (3)].vn)->push_back((yysemantic_stack_[(3) - (1)].an)); (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); }
    break;

  case 12:

/* Line 680 of lalr1.cc  */
#line 130 "parser.yy"
    { yyerrok; }
    break;

  case 13:

/* Line 680 of lalr1.cc  */
#line 134 "parser.yy"
    { (yyval.an)=new syntax_tree::ProcedureDeclaration(BEGIN_POSITION((yylocation_stack_[(4) - (2)])),(yysemantic_stack_[(4) - (2)].an),(yysemantic_stack_[(4) - (4)].an),new std::vector< syntax_tree::AbstractNode* >(),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 14:

/* Line 680 of lalr1.cc  */
#line 135 "parser.yy"
    { (yyval.an)=new syntax_tree::ProcedureDeclaration(BEGIN_POSITION((yylocation_stack_[(7) - (2)])),(yysemantic_stack_[(7) - (2)].an),(yysemantic_stack_[(7) - (7)].an),(yysemantic_stack_[(7) - (4)].vn),END_POSITION((yylocation_stack_[(7) - (7)]))); }
    break;

  case 15:

/* Line 680 of lalr1.cc  */
#line 139 "parser.yy"
    { (yyval.an)=new syntax_tree::FunctionDeclaration(BEGIN_POSITION((yylocation_stack_[(6) - (1)])),(yysemantic_stack_[(6) - (2)].an),NEW_NODE_VECTOR,(yysemantic_stack_[(6) - (4)].an),(yysemantic_stack_[(6) - (6)].an),END_POSITION((yylocation_stack_[(6) - (6)]))); }
    break;

  case 16:

/* Line 680 of lalr1.cc  */
#line 140 "parser.yy"
    { (yyval.an)=new syntax_tree::FunctionDeclaration(BEGIN_POSITION((yylocation_stack_[(9) - (1)])),(yysemantic_stack_[(9) - (2)].an),(yysemantic_stack_[(9) - (4)].vn),(yysemantic_stack_[(9) - (7)].an),(yysemantic_stack_[(9) - (9)].an),END_POSITION((yylocation_stack_[(9) - (9)]))); }
    break;

  case 17:

/* Line 680 of lalr1.cc  */
#line 144 "parser.yy"
    { (yyval.vn)=NEW_NODE_VECTOR; }
    break;

  case 18:

/* Line 680 of lalr1.cc  */
#line 145 "parser.yy"
    { (yysemantic_stack_[(3) - (3)].vn)->push_back((yysemantic_stack_[(3) - (1)].an)); (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); }
    break;

  case 19:

/* Line 680 of lalr1.cc  */
#line 146 "parser.yy"
    { yyerrok; }
    break;

  case 20:

/* Line 680 of lalr1.cc  */
#line 150 "parser.yy"
    { (yyval.an)=new syntax_tree::FormalParameterSection(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].vn),(yysemantic_stack_[(3) - (3)].an), END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 21:

/* Line 680 of lalr1.cc  */
#line 154 "parser.yy"
    { (yyval.vn)=new std::vector<syntax_tree::AbstractNode*>(); }
    break;

  case 22:

/* Line 680 of lalr1.cc  */
#line 155 "parser.yy"
    { (yysemantic_stack_[(3) - (3)].vn)->push_back((yysemantic_stack_[(3) - (1)].an)); (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); }
    break;

  case 23:

/* Line 680 of lalr1.cc  */
#line 159 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 24:

/* Line 680 of lalr1.cc  */
#line 160 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 25:

/* Line 680 of lalr1.cc  */
#line 164 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 26:

/* Line 680 of lalr1.cc  */
#line 165 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 27:

/* Line 680 of lalr1.cc  */
#line 169 "parser.yy"
    { (yyval.an)=new syntax_tree::AssignmentStatement(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 28:

/* Line 680 of lalr1.cc  */
#line 173 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 29:

/* Line 680 of lalr1.cc  */
#line 174 "parser.yy"
    { (yyval.an)=new syntax_tree::ProcedureStatement(BEGIN_POSITION((yylocation_stack_[(4) - (1)])),(yysemantic_stack_[(4) - (1)].an),(yysemantic_stack_[(4) - (3)].vn),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 30:

/* Line 680 of lalr1.cc  */
#line 178 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 31:

/* Line 680 of lalr1.cc  */
#line 179 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 32:

/* Line 680 of lalr1.cc  */
#line 180 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 33:

/* Line 680 of lalr1.cc  */
#line 184 "parser.yy"
    { (yyval.an)=new syntax_tree::CompoundStatement(BEGIN_POSITION((yylocation_stack_[(3) - (1)])), (yysemantic_stack_[(3) - (2)].vn), END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 34:

/* Line 680 of lalr1.cc  */
#line 188 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 35:

/* Line 680 of lalr1.cc  */
#line 189 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 36:

/* Line 680 of lalr1.cc  */
#line 193 "parser.yy"
    { (yyval.an)=new syntax_tree::WhileStatement(BEGIN_POSITION((yylocation_stack_[(6) - (1)])),(yysemantic_stack_[(6) - (3)].an),(yysemantic_stack_[(6) - (6)].an),END_POSITION((yylocation_stack_[(6) - (6)]))); }
    break;

  case 37:

/* Line 680 of lalr1.cc  */
#line 197 "parser.yy"
    { (yyval.an)=new syntax_tree::ForStatement(BEGIN_POSITION((yylocation_stack_[(8) - (1)])),(yysemantic_stack_[(8) - (2)].an),(yysemantic_stack_[(8) - (4)].an),(yysemantic_stack_[(8) - (6)].an),(yysemantic_stack_[(8) - (8)].an),END_POSITION((yylocation_stack_[(8) - (8)]))); }
    break;

  case 38:

/* Line 680 of lalr1.cc  */
#line 198 "parser.yy"
    { (yyval.an)=new syntax_tree::ForStatement(BEGIN_POSITION((yylocation_stack_[(8) - (1)])),(yysemantic_stack_[(8) - (2)].an),(yysemantic_stack_[(8) - (4)].an),(yysemantic_stack_[(8) - (6)].an),(yysemantic_stack_[(8) - (8)].an),END_POSITION((yylocation_stack_[(8) - (8)]))); }
    break;

  case 39:

/* Line 680 of lalr1.cc  */
#line 202 "parser.yy"
    { (yyval.an)=new syntax_tree::IfStatement(BEGIN_POSITION((yylocation_stack_[(7) - (1)])),(yysemantic_stack_[(7) - (3)].an), (yysemantic_stack_[(7) - (6)].an), (yysemantic_stack_[(7) - (7)].an),END_POSITION((yylocation_stack_[(7) - (7)])) ); }
    break;

  case 40:

/* Line 680 of lalr1.cc  */
#line 206 "parser.yy"
    { (yyval.an)=NULL; }
    break;

  case 41:

/* Line 680 of lalr1.cc  */
#line 207 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(2) - (2)].an); }
    break;

  case 42:

/* Line 680 of lalr1.cc  */
#line 211 "parser.yy"
    { (yyval.vn)=new std::vector<syntax_tree::AbstractNode*>(); }
    break;

  case 43:

/* Line 680 of lalr1.cc  */
#line 212 "parser.yy"
    { (yyval.vn)=NEW_NODE_VECTOR; (yyval.vn)->push_back((yysemantic_stack_[(1) - (1)].an)); }
    break;

  case 44:

/* Line 680 of lalr1.cc  */
#line 213 "parser.yy"
    { (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); (yysemantic_stack_[(3) - (3)].vn)->push_back((yysemantic_stack_[(3) - (1)].an)); }
    break;

  case 45:

/* Line 680 of lalr1.cc  */
#line 217 "parser.yy"
    { (yyval.an)=new syntax_tree::UnaryOperator(BEGIN_POSITION((yylocation_stack_[(2) - (1)])),MAKE_TERMINAL_NODE("-", (yylocation_stack_[(2) - (1)])), (yysemantic_stack_[(2) - (2)].an),END_POSITION((yylocation_stack_[(2) - (2)]))); }
    break;

  case 46:

/* Line 680 of lalr1.cc  */
#line 218 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE("&&", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 47:

/* Line 680 of lalr1.cc  */
#line 219 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE("mod", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 48:

/* Line 680 of lalr1.cc  */
#line 220 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE("div", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 49:

/* Line 680 of lalr1.cc  */
#line 221 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE("/", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 50:

/* Line 680 of lalr1.cc  */
#line 222 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE("*", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 51:

/* Line 680 of lalr1.cc  */
#line 223 "parser.yy"
    {  (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE("+", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 52:

/* Line 680 of lalr1.cc  */
#line 224 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE("-", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 53:

/* Line 680 of lalr1.cc  */
#line 225 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE("||", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 54:

/* Line 680 of lalr1.cc  */
#line 226 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE(">=", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 55:

/* Line 680 of lalr1.cc  */
#line 227 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE(">", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 56:

/* Line 680 of lalr1.cc  */
#line 228 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE("<=", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 57:

/* Line 680 of lalr1.cc  */
#line 229 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE("<", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 58:

/* Line 680 of lalr1.cc  */
#line 230 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE("!=", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 59:

/* Line 680 of lalr1.cc  */
#line 231 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),MAKE_TERMINAL_NODE("==", (yylocation_stack_[(3) - (2)])),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 60:

/* Line 680 of lalr1.cc  */
#line 232 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 61:

/* Line 680 of lalr1.cc  */
#line 233 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 62:

/* Line 680 of lalr1.cc  */
#line 234 "parser.yy"
    { (yyval.an)=new syntax_tree::Terminal((yysemantic_stack_[(1) - (1)].s),syntax_tree::STRING_LITERAL,BEGIN_POSITION((yylocation_stack_[(1) - (1)])),END_POSITION((yylocation_stack_[(1) - (1)]))); }
    break;

  case 63:

/* Line 680 of lalr1.cc  */
#line 235 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 64:

/* Line 680 of lalr1.cc  */
#line 236 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(3) - (2)].an); }
    break;

  case 65:

/* Line 680 of lalr1.cc  */
#line 237 "parser.yy"
    { (yyval.an)=new syntax_tree::UnaryOperator(BEGIN_POSITION((yylocation_stack_[(2) - (1)])),MAKE_TERMINAL_NODE("not", (yylocation_stack_[(2) - (1)])),(yysemantic_stack_[(2) - (2)].an),END_POSITION((yylocation_stack_[(2) - (2)]))); }
    break;

  case 66:

/* Line 680 of lalr1.cc  */
#line 241 "parser.yy"
    { (yyval.an)=new syntax_tree::Variable(BEGIN_POSITION((yylocation_stack_[(1) - (1)])),(yysemantic_stack_[(1) - (1)].an),END_POSITION((yylocation_stack_[(1) - (1)]))); }
    break;

  case 67:

/* Line 680 of lalr1.cc  */
#line 242 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 68:

/* Line 680 of lalr1.cc  */
#line 246 "parser.yy"
    { (yyval.an)=new syntax_tree::IndexedVariable(BEGIN_POSITION((yylocation_stack_[(4) - (1)])),(yysemantic_stack_[(4) - (1)].an),(yysemantic_stack_[(4) - (3)].vn),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 69:

/* Line 680 of lalr1.cc  */
#line 250 "parser.yy"
    { (yyval.an)=new syntax_tree::FunctionDesignator(BEGIN_POSITION((yylocation_stack_[(4) - (1)])),(yysemantic_stack_[(4) - (1)].an),(yysemantic_stack_[(4) - (3)].vn),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 70:

/* Line 680 of lalr1.cc  */
#line 254 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 71:

/* Line 680 of lalr1.cc  */
#line 255 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 72:

/* Line 680 of lalr1.cc  */
#line 259 "parser.yy"
    { 
	(yyval.an)=new syntax_tree::SubrangeType(
		BEGIN_POSITION((yylocation_stack_[(3) - (1)])),
		new syntax_tree::Terminal((yysemantic_stack_[(3) - (1)].s),syntax_tree::INTEGER_LITERAL,BEGIN_POSITION((yylocation_stack_[(3) - (1)])),END_POSITION((yylocation_stack_[(3) - (1)]))),
		new syntax_tree::Terminal((yysemantic_stack_[(3) - (3)].s),syntax_tree::INTEGER_LITERAL,BEGIN_POSITION((yylocation_stack_[(3) - (3)])),END_POSITION((yylocation_stack_[(3) - (3)]))),
		END_POSITION((yylocation_stack_[(3) - (3)]))
	);
	 }
    break;

  case 73:

/* Line 680 of lalr1.cc  */
#line 270 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 74:

/* Line 680 of lalr1.cc  */
#line 271 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 75:

/* Line 680 of lalr1.cc  */
#line 275 "parser.yy"
    { (yyval.an)=new syntax_tree::ArrayType(BEGIN_POSITION((yylocation_stack_[(6) - (1)])),(yysemantic_stack_[(6) - (3)].vn),(yysemantic_stack_[(6) - (6)].an), END_POSITION((yylocation_stack_[(6) - (6)]))); }
    break;

  case 76:

/* Line 680 of lalr1.cc  */
#line 279 "parser.yy"
    { (yyval.vn)=NEW_NODE_VECTOR; (yyval.vn)->push_back((yysemantic_stack_[(1) - (1)].an)); }
    break;

  case 77:

/* Line 680 of lalr1.cc  */
#line 280 "parser.yy"
    { (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); (yyval.vn)->push_back((yysemantic_stack_[(3) - (1)].an)); }
    break;

  case 78:

/* Line 680 of lalr1.cc  */
#line 284 "parser.yy"
    { (yyval.an)=new syntax_tree::CollectionType(BEGIN_POSITION((yylocation_stack_[(4) - (1)])),(yysemantic_stack_[(4) - (1)].an),(yysemantic_stack_[(4) - (3)].vn),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 79:

/* Line 680 of lalr1.cc  */
#line 288 "parser.yy"
    { (yyval.vn)=NEW_NODE_VECTOR; (yyval.vn)->push_back((yysemantic_stack_[(1) - (1)].an)); }
    break;

  case 80:

/* Line 680 of lalr1.cc  */
#line 289 "parser.yy"
    { (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); (yyval.vn)->push_back((yysemantic_stack_[(3) - (1)].an)); }
    break;

  case 81:

/* Line 680 of lalr1.cc  */
#line 293 "parser.yy"
    { (yyval.vn)=NEW_NODE_VECTOR; (yyval.vn)->push_back((yysemantic_stack_[(1) - (1)].an)); }
    break;

  case 82:

/* Line 680 of lalr1.cc  */
#line 294 "parser.yy"
    { (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); (yyval.vn)->push_back((yysemantic_stack_[(3) - (1)].an)); }
    break;

  case 83:

/* Line 680 of lalr1.cc  */
#line 298 "parser.yy"
    { (yyval.an) = new syntax_tree::Terminal((yysemantic_stack_[(1) - (1)].s),syntax_tree::INTEGER_LITERAL,BEGIN_POSITION((yylocation_stack_[(1) - (1)])),END_POSITION((yylocation_stack_[(1) - (1)]))); }
    break;

  case 84:

/* Line 680 of lalr1.cc  */
#line 299 "parser.yy"
    { (yyval.an) = new syntax_tree::Terminal((yysemantic_stack_[(1) - (1)].s),syntax_tree::DOUBLE_LITERAL,BEGIN_POSITION((yylocation_stack_[(1) - (1)])),END_POSITION((yylocation_stack_[(1) - (1)]))); }
    break;

  case 85:

/* Line 680 of lalr1.cc  */
#line 303 "parser.yy"
    { (yyval.an) = MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;



/* Line 680 of lalr1.cc  */
#line 1029 "parser.cc"
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
  const signed char Parser::yypact_ninf_ = -117;
  const short int
  Parser::yypact_[] =
  {
        83,    -3,   -32,   -32,    32,    36,    34,    40,  -117,  -117,
      11,     0,  -117,   -32,     6,    49,    83,    83,     8,    36,
       8,   -32,  -117,    54,    45,    60,  -117,    63,  -117,  -117,
    -117,    68,    65,    74,    62,  -117,    77,    78,   -32,    -1,
     -32,    79,   -32,    98,   104,   100,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,   -24,  -117,    20,  -117,   102,
       8,   -32,    90,    36,  -117,    76,  -117,  -117,  -117,  -117,
      89,  -117,    -5,   -21,  -117,    -5,  -117,    63,    -5,    -5,
      -5,    36,  -117,  -117,   -32,  -117,    80,   -32,    -5,    -5,
      -5,  -117,  -117,  -117,   150,    82,  -117,  -117,   114,    -5,
     178,  -117,   307,   213,    84,   120,   222,  -117,   121,   105,
     124,    96,   109,   187,    92,  -117,   122,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,   247,   123,    -5,  -117,  -117,    -5,    36,   101,
      80,   119,  -117,  -117,    63,    92,  -117,    92,  -117,  -117,
      92,    92,    92,    92,    92,   103,   103,  -117,  -117,   139,
      -5,    -5,    63,  -117,  -117,  -117,  -117,  -117,    -1,  -117,
    -117,   272,   297,   144,  -117,    63,    63,    63,  -117,  -117,
    -117,  -117
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     4,     0,     0,    12,    85,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     4,
       0,     0,     5,     0,     0,    79,     2,    21,     3,    10,
      11,     0,     0,     0,     0,    13,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,    23,    25,    26,    24,
      30,    31,    34,    35,    32,     0,    67,    28,    19,     0,
       0,     0,     0,     4,     7,     0,     8,    70,    73,    74,
      71,    80,     0,     0,    66,     0,    33,    21,     0,     0,
      42,     4,    18,    20,     0,    15,     0,     0,     0,     0,
       0,    62,    83,    84,     0,    60,    63,    61,    66,     0,
       0,    22,    27,    81,     0,     0,    43,    14,     0,     0,
      76,     0,     0,     0,    65,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,    68,    29,    42,     4,     0,
       0,     0,    78,    64,     0,    59,    46,    53,    48,    47,
      58,    57,    56,    55,    54,    51,    52,    50,    49,     0,
       0,     0,     0,    82,    44,    16,    72,    77,     0,    36,
      69,     0,     0,    40,    75,     0,     0,     0,    39,    37,
      38,    41
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -117,  -117,   -16,  -117,   117,  -117,    64,  -117,  -117,   -14,
    -117,    81,  -114,  -117,  -117,  -117,  -117,   141,  -117,  -117,
    -117,  -117,  -117,  -116,   -22,   -25,  -117,  -117,   -11,  -117,
    -117,  -117,    19,  -117,    -9,    27,  -117,    -2
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,     4,    14,    15,    22,    23,     5,     6,     7,    32,
      33,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,   178,   105,   106,    95,    56,    96,    66,   110,
      67,    68,   111,    69,    34,   104,    97,    98
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -67;
  const short int
  Parser::yytable_[] =
  {
        10,    11,    55,    35,    24,    65,    36,    78,    88,    31,
      99,    25,     8,    20,     9,   159,    25,    73,    25,    37,
      79,   164,   -17,    79,    18,    57,    19,    89,    21,    24,
     169,    71,    12,    80,    90,    26,    25,    70,    25,    13,
      74,     9,    91,    92,    93,     9,    82,    85,   173,    16,
      94,   -66,    55,   100,     9,    17,   102,   103,    25,    83,
      27,   179,   180,   181,   -66,   107,   113,   114,   115,    38,
      41,    42,    43,    39,    27,    57,    40,   132,   112,    59,
      29,    30,   108,    58,     1,    25,    -9,     2,     3,    60,
      61,    62,    72,    63,    -9,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     9,
     118,    75,   103,   120,   121,    77,    76,    81,    84,    55,
      86,   118,   165,    87,   120,   121,    79,   131,   109,   135,
     127,   128,   129,   130,   136,   139,   138,    55,   171,   172,
     140,   141,    57,   129,   130,   142,   168,   162,   144,   166,
      55,    55,    55,   170,   177,    64,    28,   174,   101,   167,
      57,   163,     0,     0,   116,     0,    70,   117,   118,   119,
       0,   120,   121,    57,    57,    57,     0,     0,     0,     0,
       0,     0,     0,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   133,     0,     0,   117,   118,   119,     0,   120,
     121,   143,     0,     0,   117,   118,   119,     0,   120,   121,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   134,
     117,   118,   119,     0,   120,   121,     0,     0,   137,   117,
     118,   119,     0,   120,   121,     0,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   117,   118,   119,     0,   120,   121,
     160,     0,   161,     0,     0,     0,     0,     0,     0,     0,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   117,
     118,   119,     0,   120,   121,     0,     0,     0,   175,     0,
       0,     0,     0,     0,     0,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   117,   118,   119,     0,   120,   121,
       0,     0,     0,   176,   117,   118,   119,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
     122,   123,   124,   125,   126,   127,   128,   129,   130
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         2,     3,    27,    19,    13,     6,    20,    31,    13,     1,
      31,    13,    15,    13,    46,   131,    18,    42,    20,    21,
      44,   137,    14,    44,    13,    27,    15,    32,    28,    38,
     144,    40,     0,    13,    39,    29,    38,    39,    40,     3,
      42,    46,    47,    48,    49,    46,    60,    63,   162,    15,
      72,    31,    77,    75,    46,    15,    78,    79,    60,    61,
      11,   175,   176,   177,    44,    81,    88,    89,    90,    15,
       7,     8,     9,    28,    11,    77,    16,    99,    87,    14,
      16,    17,    84,    15,     1,    87,     3,     4,     5,    15,
      28,    14,    13,    15,    11,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    46,
      18,    13,   134,    21,    22,    15,    12,    15,    28,   144,
      44,    18,   138,    34,    21,    22,    44,    13,    48,    45,
      38,    39,    40,    41,    14,    30,    15,   162,   160,   161,
      16,    45,   144,    40,    41,    36,    27,    24,    26,    48,
     175,   176,   177,    14,    10,    38,    15,   168,    77,   140,
     162,   134,    -1,    -1,    14,    -1,   168,    17,    18,    19,
      -1,    21,    22,   175,   176,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    14,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    14,    -1,    -1,    17,    18,    19,    -1,    21,    22,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    16,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    16,    17,
      18,    19,    -1,    21,    22,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    17,    18,    19,    -1,    21,    22,
      23,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    26,    17,    18,    19,    -1,    21,    22,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     1,     4,     5,    52,    57,    58,    59,    15,    46,
      88,    88,     0,     3,    53,    54,    15,    15,    13,    15,
      13,    28,    55,    56,    85,    88,    29,    11,    68,    57,
      57,     1,    60,    61,    85,    53,    60,    88,    15,    28,
      16,     7,     8,     9,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    76,    77,    88,    15,    14,
      15,    28,    14,    15,    55,     6,    79,    81,    82,    84,
      88,    85,    13,    76,    88,    13,    12,    15,    31,    44,
      13,    15,    60,    88,    28,    53,    44,    34,    13,    32,
      39,    47,    48,    49,    75,    76,    78,    87,    88,    31,
      75,    62,    75,    75,    86,    74,    75,    53,    88,    48,
      80,    83,    85,    75,    75,    75,    14,    17,    18,    19,
      21,    22,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    13,    75,    14,    16,    45,    14,    16,    15,    30,
      16,    45,    36,    14,    26,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    74,
      23,    25,    24,    86,    74,    53,    48,    83,    27,    63,
      14,    75,    75,    63,    79,    26,    26,    10,    73,    63,
      63,    63
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    51,    52,    53,    54,    54,    55,    55,    56,    57,
      57,    57,    57,    58,    58,    59,    59,    60,    60,    60,
      61,    62,    62,    63,    63,    64,    64,    65,    66,    66,
      67,    67,    67,    68,    69,    69,    70,    71,    71,    72,
      73,    73,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    77,    78,
      79,    79,    80,    81,    81,    82,    83,    83,    84,    85,
      85,    86,    86,    87,    87,    88
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     3,     2,     0,     2,     2,     3,     3,     0,
       3,     3,     2,     4,     7,     6,     9,     0,     3,     2,
       3,     0,     3,     1,     1,     1,     1,     3,     1,     4,
       1,     1,     1,     3,     1,     1,     6,     8,     8,     7,
       0,     2,     0,     1,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     2,     1,     1,     4,     4,
       1,     1,     3,     1,     1,     6,     1,     3,     4,     1,
       3,     1,     3,     1,     1,     1
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
  "TYPE", "DIV", "MOD", "TO", "THEN", "DOWNTO", "DO", "OF", "COLON", "DOT",
  "DOTDOT", "ASSIGN", "NOT", "NOTEQUAL", "LESS", "LESSOREQUAL", "MORE",
  "MOREOREQUAL", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "LEFTBRACE",
  "RIGHTBRACE", "LEFTBRACKET", "RIGHTBRACKET", "IDENT", "STRING_LITERAL",
  "INTEGER_LITERAL", "DOUBLE_LITERAL", "UMINUS", "$accept", "program",
  "block", "variable_declaration_part", "variable_declaration_list",
  "variable_declaration", "procedure_and_function_declaration",
  "procedure_declaration", "function_declaration", "formal_parameter_list",
  "formal_parameter_section", "statement_sequence", "statement",
  "simple_statement", "assignment_statement", "procedure_statement",
  "structured_statement", "compound_statement", "repetitive_statement",
  "while_statement", "for_statement", "if_statement", "else_expression",
  "actual_parameter_list", "expression", "variable", "indexed_variable",
  "function_designator", "type", "subrange_type", "structured_type",
  "array_type", "index_type_list", "collection_type", "identifier_list",
  "expression_list", "number", "ident_terminal", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        52,     0,    -1,    57,    53,    29,    -1,    54,    68,    -1,
      -1,     3,    55,    -1,    56,    15,    -1,    56,    15,    55,
      -1,    85,    28,    79,    -1,    -1,    58,    15,    57,    -1,
      59,    15,    57,    -1,     1,    15,    -1,     4,    88,    15,
      53,    -1,     4,    88,    13,    60,    14,    15,    53,    -1,
       5,    88,    28,    88,    15,    53,    -1,     5,    88,    13,
      60,    14,    28,    88,    15,    53,    -1,    -1,    61,    15,
      60,    -1,     1,    15,    -1,    85,    28,    88,    -1,    -1,
      63,    15,    62,    -1,    64,    -1,    67,    -1,    65,    -1,
      66,    -1,    76,    31,    75,    -1,    88,    -1,    88,    13,
      74,    14,    -1,    68,    -1,    69,    -1,    72,    -1,    11,
      62,    12,    -1,    70,    -1,    71,    -1,     7,    13,    75,
      14,    26,    63,    -1,     8,    76,    31,    75,    23,    75,
      26,    63,    -1,     8,    76,    31,    75,    25,    75,    26,
      63,    -1,     9,    13,    75,    14,    24,    63,    73,    -1,
      -1,    10,    63,    -1,    -1,    75,    -1,    75,    16,    74,
      -1,    39,    75,    -1,    75,    18,    75,    -1,    75,    22,
      75,    -1,    75,    21,    75,    -1,    75,    41,    75,    -1,
      75,    40,    75,    -1,    75,    38,    75,    -1,    75,    39,
      75,    -1,    75,    19,    75,    -1,    75,    37,    75,    -1,
      75,    36,    75,    -1,    75,    35,    75,    -1,    75,    34,
      75,    -1,    75,    33,    75,    -1,    75,    17,    75,    -1,
      76,    -1,    87,    -1,    47,    -1,    78,    -1,    13,    75,
      14,    -1,    32,    75,    -1,    88,    -1,    77,    -1,    76,
      44,    86,    45,    -1,    88,    13,    74,    14,    -1,    81,
      -1,    88,    -1,    48,    30,    48,    -1,    82,    -1,    84,
      -1,     6,    44,    83,    45,    27,    79,    -1,    80,    -1,
      80,    16,    83,    -1,    88,    34,    85,    36,    -1,    88,
      -1,    88,    16,    85,    -1,    75,    -1,    75,    16,    86,
      -1,    48,    -1,    49,    -1,    46,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     7,    10,    11,    14,    17,    21,    25,
      26,    30,    34,    37,    42,    50,    57,    67,    68,    72,
      75,    79,    80,    84,    86,    88,    90,    92,    96,    98,
     103,   105,   107,   109,   113,   115,   117,   124,   133,   142,
     150,   151,   154,   155,   157,   161,   164,   168,   172,   176,
     180,   184,   188,   192,   196,   200,   204,   208,   212,   216,
     220,   222,   224,   226,   228,   232,   235,   237,   239,   244,
     249,   251,   253,   257,   259,   261,   268,   270,   274,   279,
     281,   285,   287,   291,   293,   295
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   105,   105,   109,   113,   114,   118,   119,   123,   127,
     128,   129,   130,   134,   135,   139,   140,   144,   145,   146,
     150,   154,   155,   159,   160,   164,   165,   169,   173,   174,
     178,   179,   180,   184,   188,   189,   193,   197,   198,   202,
     206,   207,   211,   212,   213,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   241,   242,   246,   250,
     254,   255,   259,   270,   271,   275,   279,   280,   284,   288,
     289,   293,   294,   298,   299,   303
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
      45,    46,    47,    48,    49,    50
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 348;
  const int Parser::yynnts_ = 38;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 12;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 51;

  const unsigned int Parser::yyuser_token_number_max_ = 305;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


} // generated

/* Line 1056 of lalr1.cc  */
#line 1649 "parser.cc"


/* Line 1058 of lalr1.cc  */
#line 305 "parser.yy"



void generated::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
     errors.push_back(std::make_pair(m, std::make_pair(l.begin.line, l.begin.column)));
}

