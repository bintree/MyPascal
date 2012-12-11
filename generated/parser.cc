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
#define MAKE_TERMINAL_NODE(A, B) new syntax_tree::Terminal(A,syntax_tree::OTHER,BEGIN_POSITION(B),END_POSITION(B))
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
#line 109 "parser.yy"
    { (yyval.an)=new syntax_tree::Program(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].vn),(yysemantic_stack_[(3) - (2)].an),END_POSITION((yylocation_stack_[(3) - (2)]))); result = (yyval.an); }
    break;

  case 3:

/* Line 680 of lalr1.cc  */
#line 113 "parser.yy"
    { (yyval.an)=new syntax_tree::Block(BEGIN_POSITION((yylocation_stack_[(2) - (1)])),(yysemantic_stack_[(2) - (1)].vn),(yysemantic_stack_[(2) - (2)].an),END_POSITION((yylocation_stack_[(2) - (2)]))); }
    break;

  case 4:

/* Line 680 of lalr1.cc  */
#line 117 "parser.yy"
    { (yyval.vn)=new std::vector<syntax_tree::AbstractNode*>(); }
    break;

  case 5:

/* Line 680 of lalr1.cc  */
#line 118 "parser.yy"
    { (yyval.vn)=(yysemantic_stack_[(2) - (2)].vn); }
    break;

  case 6:

/* Line 680 of lalr1.cc  */
#line 122 "parser.yy"
    { (yyval.vn)=new std::vector<syntax_tree::AbstractNode*>();(yyval.vn)->push_back((yysemantic_stack_[(2) - (1)].an)); }
    break;

  case 7:

/* Line 680 of lalr1.cc  */
#line 123 "parser.yy"
    { (yysemantic_stack_[(3) - (3)].vn)->push_back((yysemantic_stack_[(3) - (1)].an));(yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); }
    break;

  case 8:

/* Line 680 of lalr1.cc  */
#line 127 "parser.yy"
    { (yyval.an)=new syntax_tree::VariableDeclaration(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].vn),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 9:

/* Line 680 of lalr1.cc  */
#line 131 "parser.yy"
    { (yyval.vn)=new std::vector< syntax_tree::AbstractNode* >(); }
    break;

  case 10:

/* Line 680 of lalr1.cc  */
#line 132 "parser.yy"
    { (yysemantic_stack_[(3) - (3)].vn)->push_back((yysemantic_stack_[(3) - (1)].an)); (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); }
    break;

  case 11:

/* Line 680 of lalr1.cc  */
#line 133 "parser.yy"
    { (yysemantic_stack_[(3) - (3)].vn)->push_back((yysemantic_stack_[(3) - (1)].an)); (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); }
    break;

  case 12:

/* Line 680 of lalr1.cc  */
#line 134 "parser.yy"
    { yyerrok; }
    break;

  case 13:

/* Line 680 of lalr1.cc  */
#line 138 "parser.yy"
    { (yyval.an)=new syntax_tree::ProcedureDeclaration(BEGIN_POSITION((yylocation_stack_[(4) - (2)])),(yysemantic_stack_[(4) - (2)].an),(yysemantic_stack_[(4) - (4)].an),new std::vector< syntax_tree::AbstractNode* >(),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 14:

/* Line 680 of lalr1.cc  */
#line 139 "parser.yy"
    { (yyval.an)=new syntax_tree::ProcedureDeclaration(BEGIN_POSITION((yylocation_stack_[(7) - (2)])),(yysemantic_stack_[(7) - (2)].an),(yysemantic_stack_[(7) - (7)].an),(yysemantic_stack_[(7) - (4)].vn),END_POSITION((yylocation_stack_[(7) - (7)]))); }
    break;

  case 15:

/* Line 680 of lalr1.cc  */
#line 143 "parser.yy"
    { (yyval.an)=new syntax_tree::FunctionDeclaration(BEGIN_POSITION((yylocation_stack_[(6) - (1)])),(yysemantic_stack_[(6) - (2)].an),NEW_NODE_VECTOR,(yysemantic_stack_[(6) - (4)].an),(yysemantic_stack_[(6) - (6)].an),END_POSITION((yylocation_stack_[(6) - (6)]))); }
    break;

  case 16:

/* Line 680 of lalr1.cc  */
#line 144 "parser.yy"
    { (yyval.an)=new syntax_tree::FunctionDeclaration(BEGIN_POSITION((yylocation_stack_[(9) - (1)])),(yysemantic_stack_[(9) - (2)].an),(yysemantic_stack_[(9) - (4)].vn),(yysemantic_stack_[(9) - (7)].an),(yysemantic_stack_[(9) - (9)].an),END_POSITION((yylocation_stack_[(9) - (9)]))); }
    break;

  case 17:

/* Line 680 of lalr1.cc  */
#line 148 "parser.yy"
    { (yyval.vn)=NEW_NODE_VECTOR; }
    break;

  case 18:

/* Line 680 of lalr1.cc  */
#line 149 "parser.yy"
    { (yysemantic_stack_[(3) - (3)].vn)->push_back((yysemantic_stack_[(3) - (1)].an)); (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); }
    break;

  case 19:

/* Line 680 of lalr1.cc  */
#line 150 "parser.yy"
    { yyerrok; }
    break;

  case 20:

/* Line 680 of lalr1.cc  */
#line 154 "parser.yy"
    { (yyval.an)=new syntax_tree::FormalParameterSection(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].vn),(yysemantic_stack_[(3) - (3)].an), END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 21:

/* Line 680 of lalr1.cc  */
#line 158 "parser.yy"
    { (yyval.vn)=new std::vector<syntax_tree::AbstractNode*>(); }
    break;

  case 22:

/* Line 680 of lalr1.cc  */
#line 159 "parser.yy"
    { (yysemantic_stack_[(3) - (3)].vn)->push_back((yysemantic_stack_[(3) - (1)].an)); (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); }
    break;

  case 23:

/* Line 680 of lalr1.cc  */
#line 163 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 24:

/* Line 680 of lalr1.cc  */
#line 164 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 25:

/* Line 680 of lalr1.cc  */
#line 168 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 26:

/* Line 680 of lalr1.cc  */
#line 169 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 27:

/* Line 680 of lalr1.cc  */
#line 173 "parser.yy"
    { (yyval.an)=new syntax_tree::AssignmentStatement(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 28:

/* Line 680 of lalr1.cc  */
#line 177 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 29:

/* Line 680 of lalr1.cc  */
#line 178 "parser.yy"
    { (yyval.an)=new syntax_tree::ProcedureStatement(BEGIN_POSITION((yylocation_stack_[(4) - (1)])),(yysemantic_stack_[(4) - (1)].an),(yysemantic_stack_[(4) - (3)].vn),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 30:

/* Line 680 of lalr1.cc  */
#line 182 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 31:

/* Line 680 of lalr1.cc  */
#line 183 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 32:

/* Line 680 of lalr1.cc  */
#line 184 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 33:

/* Line 680 of lalr1.cc  */
#line 188 "parser.yy"
    { (yyval.an)=new syntax_tree::CompoundStatement(BEGIN_POSITION((yylocation_stack_[(3) - (1)])), (yysemantic_stack_[(3) - (2)].vn), END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 34:

/* Line 680 of lalr1.cc  */
#line 192 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 35:

/* Line 680 of lalr1.cc  */
#line 193 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 36:

/* Line 680 of lalr1.cc  */
#line 197 "parser.yy"
    { (yyval.an)=new syntax_tree::WhileStatement(BEGIN_POSITION((yylocation_stack_[(6) - (1)])),(yysemantic_stack_[(6) - (3)].an),(yysemantic_stack_[(6) - (6)].an),END_POSITION((yylocation_stack_[(6) - (6)]))); }
    break;

  case 37:

/* Line 680 of lalr1.cc  */
#line 201 "parser.yy"
    { (yyval.an)=new syntax_tree::ForStatement(BEGIN_POSITION((yylocation_stack_[(8) - (1)])),(yysemantic_stack_[(8) - (2)].an),(yysemantic_stack_[(8) - (4)].an),(yysemantic_stack_[(8) - (6)].an),(yysemantic_stack_[(8) - (8)].an),END_POSITION((yylocation_stack_[(8) - (8)]))); }
    break;

  case 38:

/* Line 680 of lalr1.cc  */
#line 202 "parser.yy"
    { (yyval.an)=new syntax_tree::ForStatement(BEGIN_POSITION((yylocation_stack_[(8) - (1)])),(yysemantic_stack_[(8) - (2)].an),(yysemantic_stack_[(8) - (4)].an),(yysemantic_stack_[(8) - (6)].an),(yysemantic_stack_[(8) - (8)].an),END_POSITION((yylocation_stack_[(8) - (8)]))); }
    break;

  case 39:

/* Line 680 of lalr1.cc  */
#line 206 "parser.yy"
    { (yyval.an)=new syntax_tree::IfStatement(BEGIN_POSITION((yylocation_stack_[(7) - (1)])),(yysemantic_stack_[(7) - (3)].an), (yysemantic_stack_[(7) - (6)].an), (yysemantic_stack_[(7) - (7)].an),END_POSITION((yylocation_stack_[(7) - (7)])) ); }
    break;

  case 40:

/* Line 680 of lalr1.cc  */
#line 210 "parser.yy"
    { (yyval.an)=NULL; }
    break;

  case 41:

/* Line 680 of lalr1.cc  */
#line 211 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(2) - (2)].an); }
    break;

  case 42:

/* Line 680 of lalr1.cc  */
#line 215 "parser.yy"
    { (yyval.vn)=new std::vector<syntax_tree::AbstractNode*>(); }
    break;

  case 43:

/* Line 680 of lalr1.cc  */
#line 216 "parser.yy"
    { (yyval.vn)=NEW_NODE_VECTOR; (yyval.vn)->push_back((yysemantic_stack_[(1) - (1)].an)); }
    break;

  case 44:

/* Line 680 of lalr1.cc  */
#line 217 "parser.yy"
    { (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); (yysemantic_stack_[(3) - (3)].vn)->push_back((yysemantic_stack_[(3) - (1)].an)); }
    break;

  case 45:

/* Line 680 of lalr1.cc  */
#line 221 "parser.yy"
    { (yyval.an)=new syntax_tree::UnaryOperator(BEGIN_POSITION((yylocation_stack_[(2) - (1)])),(yysemantic_stack_[(2) - (1)].an),(yysemantic_stack_[(2) - (2)].an),END_POSITION((yylocation_stack_[(2) - (2)]))); }
    break;

  case 46:

/* Line 680 of lalr1.cc  */
#line 222 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 47:

/* Line 680 of lalr1.cc  */
#line 223 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (2)].an),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 48:

/* Line 680 of lalr1.cc  */
#line 227 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 49:

/* Line 680 of lalr1.cc  */
#line 228 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (2)].an),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 50:

/* Line 680 of lalr1.cc  */
#line 232 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 51:

/* Line 680 of lalr1.cc  */
#line 233 "parser.yy"
    { (yyval.an)=new syntax_tree::BinaryOperator(BEGIN_POSITION((yylocation_stack_[(3) - (1)])),(yysemantic_stack_[(3) - (1)].an),(yysemantic_stack_[(3) - (2)].an),(yysemantic_stack_[(3) - (3)].an),END_POSITION((yylocation_stack_[(3) - (3)]))); }
    break;

  case 52:

/* Line 680 of lalr1.cc  */
#line 237 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 53:

/* Line 680 of lalr1.cc  */
#line 238 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 54:

/* Line 680 of lalr1.cc  */
#line 239 "parser.yy"
    { (yyval.an)=new syntax_tree::Terminal((yysemantic_stack_[(1) - (1)].s),syntax_tree::STRING_LITERAL,BEGIN_POSITION((yylocation_stack_[(1) - (1)])),END_POSITION((yylocation_stack_[(1) - (1)]))); }
    break;

  case 55:

/* Line 680 of lalr1.cc  */
#line 240 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 56:

/* Line 680 of lalr1.cc  */
#line 241 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(3) - (2)].an); }
    break;

  case 57:

/* Line 680 of lalr1.cc  */
#line 242 "parser.yy"
    { (yyval.an)=new syntax_tree::UnaryOperator(BEGIN_POSITION((yylocation_stack_[(2) - (1)])),MAKE_TERMINAL_NODE((yysemantic_stack_[(2) - (1)].s), (yylocation_stack_[(2) - (1)])),(yysemantic_stack_[(2) - (2)].an),END_POSITION((yylocation_stack_[(2) - (2)]))); }
    break;

  case 58:

/* Line 680 of lalr1.cc  */
#line 246 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 59:

/* Line 680 of lalr1.cc  */
#line 247 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 60:

/* Line 680 of lalr1.cc  */
#line 248 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 61:

/* Line 680 of lalr1.cc  */
#line 249 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 62:

/* Line 680 of lalr1.cc  */
#line 250 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 63:

/* Line 680 of lalr1.cc  */
#line 251 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 64:

/* Line 680 of lalr1.cc  */
#line 255 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 65:

/* Line 680 of lalr1.cc  */
#line 256 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)]));}
    break;

  case 66:

/* Line 680 of lalr1.cc  */
#line 257 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 67:

/* Line 680 of lalr1.cc  */
#line 261 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 68:

/* Line 680 of lalr1.cc  */
#line 262 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 69:

/* Line 680 of lalr1.cc  */
#line 263 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 70:

/* Line 680 of lalr1.cc  */
#line 264 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 71:

/* Line 680 of lalr1.cc  */
#line 265 "parser.yy"
    { (yyval.an)=MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 72:

/* Line 680 of lalr1.cc  */
#line 269 "parser.yy"
    { (yyval.an)=new syntax_tree::Variable(BEGIN_POSITION((yylocation_stack_[(1) - (1)])),(yysemantic_stack_[(1) - (1)].an),END_POSITION((yylocation_stack_[(1) - (1)]))); }
    break;

  case 73:

/* Line 680 of lalr1.cc  */
#line 270 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 74:

/* Line 680 of lalr1.cc  */
#line 274 "parser.yy"
    { (yyval.an)=new syntax_tree::IndexedVariable(BEGIN_POSITION((yylocation_stack_[(4) - (1)])),(yysemantic_stack_[(4) - (1)].an),(yysemantic_stack_[(4) - (3)].vn),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 75:

/* Line 680 of lalr1.cc  */
#line 278 "parser.yy"
    { (yyval.an)=new syntax_tree::FunctionDesignator(BEGIN_POSITION((yylocation_stack_[(4) - (1)])),(yysemantic_stack_[(4) - (1)].an),(yysemantic_stack_[(4) - (3)].vn),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 76:

/* Line 680 of lalr1.cc  */
#line 282 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 77:

/* Line 680 of lalr1.cc  */
#line 283 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 78:

/* Line 680 of lalr1.cc  */
#line 287 "parser.yy"
    { 
	(yyval.an)=new syntax_tree::SubrangeType(
		BEGIN_POSITION((yylocation_stack_[(3) - (1)])),
		new syntax_tree::Terminal((yysemantic_stack_[(3) - (1)].s),syntax_tree::INTEGER_LITERAL,BEGIN_POSITION((yylocation_stack_[(3) - (1)])),END_POSITION((yylocation_stack_[(3) - (1)]))),
		new syntax_tree::Terminal((yysemantic_stack_[(3) - (3)].s),syntax_tree::INTEGER_LITERAL,BEGIN_POSITION((yylocation_stack_[(3) - (3)])),END_POSITION((yylocation_stack_[(3) - (3)]))),
		END_POSITION((yylocation_stack_[(3) - (3)]))
	); }
    break;

  case 79:

/* Line 680 of lalr1.cc  */
#line 297 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 80:

/* Line 680 of lalr1.cc  */
#line 298 "parser.yy"
    { (yyval.an)=(yysemantic_stack_[(1) - (1)].an); }
    break;

  case 81:

/* Line 680 of lalr1.cc  */
#line 302 "parser.yy"
    { (yyval.an)=new syntax_tree::ArrayType(BEGIN_POSITION((yylocation_stack_[(6) - (1)])),(yysemantic_stack_[(6) - (3)].vn),(yysemantic_stack_[(6) - (6)].an), END_POSITION((yylocation_stack_[(6) - (6)]))); }
    break;

  case 82:

/* Line 680 of lalr1.cc  */
#line 306 "parser.yy"
    { (yyval.vn)=NEW_NODE_VECTOR; (yyval.vn)->push_back((yysemantic_stack_[(1) - (1)].an)); }
    break;

  case 83:

/* Line 680 of lalr1.cc  */
#line 307 "parser.yy"
    { (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); (yyval.vn)->push_back((yysemantic_stack_[(3) - (1)].an)); }
    break;

  case 84:

/* Line 680 of lalr1.cc  */
#line 311 "parser.yy"
    { (yyval.an)=new syntax_tree::CollectionType(BEGIN_POSITION((yylocation_stack_[(4) - (1)])),(yysemantic_stack_[(4) - (1)].an),(yysemantic_stack_[(4) - (3)].vn),END_POSITION((yylocation_stack_[(4) - (4)]))); }
    break;

  case 85:

/* Line 680 of lalr1.cc  */
#line 315 "parser.yy"
    { (yyval.vn)=NEW_NODE_VECTOR; (yyval.vn)->push_back((yysemantic_stack_[(1) - (1)].an)); }
    break;

  case 86:

/* Line 680 of lalr1.cc  */
#line 316 "parser.yy"
    { (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); (yyval.vn)->push_back((yysemantic_stack_[(3) - (1)].an)); }
    break;

  case 87:

/* Line 680 of lalr1.cc  */
#line 320 "parser.yy"
    { (yyval.vn)=NEW_NODE_VECTOR; (yyval.vn)->push_back((yysemantic_stack_[(1) - (1)].an)); }
    break;

  case 88:

/* Line 680 of lalr1.cc  */
#line 321 "parser.yy"
    { (yyval.vn)=(yysemantic_stack_[(3) - (3)].vn); (yyval.vn)->push_back((yysemantic_stack_[(3) - (1)].an)); }
    break;

  case 89:

/* Line 680 of lalr1.cc  */
#line 325 "parser.yy"
    { (yyval.an) = new syntax_tree::Terminal((yysemantic_stack_[(1) - (1)].s),syntax_tree::INTEGER_LITERAL,BEGIN_POSITION((yylocation_stack_[(1) - (1)])),END_POSITION((yylocation_stack_[(1) - (1)]))); }
    break;

  case 90:

/* Line 680 of lalr1.cc  */
#line 326 "parser.yy"
    { (yyval.an) = new syntax_tree::Terminal((yysemantic_stack_[(1) - (1)].s),syntax_tree::DOUBLE_LITERAL,BEGIN_POSITION((yylocation_stack_[(1) - (1)])),END_POSITION((yylocation_stack_[(1) - (1)]))); }
    break;

  case 91:

/* Line 680 of lalr1.cc  */
#line 330 "parser.yy"
    { (yyval.an) = MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 92:

/* Line 680 of lalr1.cc  */
#line 331 "parser.yy"
    { (yyval.an) = MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;

  case 93:

/* Line 680 of lalr1.cc  */
#line 335 "parser.yy"
    { (yyval.an) = MAKE_TERMINAL_NODE((yysemantic_stack_[(1) - (1)].s), (yylocation_stack_[(1) - (1)])); }
    break;



/* Line 680 of lalr1.cc  */
#line 1084 "parser.cc"
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
       105,    -3,   -19,   -19,    30,    32,    29,    48,  -114,  -114,
      54,    15,  -114,   -19,    39,    60,   105,   105,     7,    32,
       7,   -19,  -114,    66,    58,    91,  -114,    53,  -114,  -114,
    -114,    96,    98,   100,    89,  -114,   104,   106,   -19,    -1,
     -19,   107,   -19,   109,   111,   113,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,   -22,  -114,    11,  -114,   114,
       7,   -19,   103,    32,  -114,    75,  -114,  -114,  -114,  -114,
      92,  -114,    41,   -11,  -114,    41,  -114,    53,    41,    41,
      41,    32,  -114,  -114,   -19,  -114,    84,   -19,    41,     2,
    -114,  -114,  -114,  -114,  -114,   119,    67,    86,    73,    93,
    -114,  -114,     2,   122,    41,   124,  -114,  -114,   120,    94,
     126,   125,  -114,   127,   115,   128,   101,   116,   129,  -114,
     130,  -114,  -114,  -114,  -114,  -114,  -114,     2,  -114,  -114,
    -114,     2,  -114,  -114,  -114,  -114,  -114,     2,  -114,    41,
      49,   131,    41,  -114,  -114,    41,    32,   110,    84,   132,
    -114,  -114,    53,  -114,  -114,  -114,   137,    41,    41,    53,
    -114,  -114,  -114,  -114,  -114,    -1,  -114,  -114,   134,   135,
     143,  -114,    53,    53,    53,  -114,  -114,  -114,  -114
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     4,     0,     0,    12,    93,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     4,
       0,     0,     5,     0,     0,    85,     2,    21,     3,    10,
      11,     0,     0,     0,     0,    13,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,    23,    25,    26,    24,
      30,    31,    34,    35,    32,     0,    73,    28,    19,     0,
       0,     0,     0,     4,     7,     0,     8,    76,    79,    80,
      77,    86,     0,     0,    72,     0,    33,    21,     0,     0,
      42,     4,    18,    20,     0,    15,     0,     0,     0,     0,
      91,    92,    54,    89,    90,     0,    46,    48,    50,    52,
      55,    53,     0,    72,     0,     0,    22,    27,    87,     0,
       0,    43,    14,     0,     0,    82,     0,     0,     0,    57,
       0,    58,    59,    60,    61,    62,    63,     0,    66,    64,
      65,     0,    71,    69,    70,    67,    68,     0,    45,    42,
       0,     0,     0,    74,    29,    42,     4,     0,     0,     0,
      84,    56,     0,    47,    49,    51,     0,     0,     0,     0,
      88,    44,    16,    78,    83,     0,    36,    75,     0,     0,
      40,    81,     0,     0,     0,    39,    37,    38,    41
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -114,  -114,   -16,  -114,   136,  -114,    40,  -114,  -114,   -14,
    -114,    77,   -76,  -114,  -114,  -114,  -114,   147,  -114,  -114,
    -114,  -114,  -114,  -113,   -65,   -61,    27,    76,  -114,  -114,
    -114,   -25,  -114,  -114,     1,  -114,  -114,  -114,    19,  -114,
      -9,    26,  -114,  -114,    -2
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,     4,    14,    15,    22,    23,     5,     6,     7,    32,
      33,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,   175,   110,   111,    96,    97,    98,   127,   131,
     137,    99,    56,   100,    66,   115,    67,    68,   116,    69,
      34,   109,   101,   102,   103
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -73;
  const short int
  Parser::yytable_[] =
  {
        10,    11,    55,    35,    24,    65,    36,    95,    31,    78,
     105,    25,     8,   107,   108,    88,    25,    73,    25,    37,
     104,   -17,    79,   118,    80,    57,   156,     9,    20,    24,
      12,    71,   161,    79,    89,    13,    25,    70,    25,   140,
      74,   138,   -72,    21,    16,     9,    82,    85,     9,    92,
      93,    94,    55,     9,    88,   -72,    29,    30,    25,    83,
      41,    42,    43,    17,    27,   112,   153,    18,    26,    19,
     154,    27,   157,    89,   158,    57,   166,   108,   117,    90,
      91,    38,   113,   170,   121,    25,    39,     9,    92,    93,
      94,   132,   168,   169,   133,   134,   176,   177,   178,     9,
     122,   123,   124,   125,   126,   128,     1,    40,    -9,     2,
       3,    58,    59,   135,   136,    60,    -9,    61,    62,    86,
      72,    63,    75,    76,   129,   130,    87,    55,    77,    81,
     162,    84,   114,   120,    55,   139,   142,    79,   141,   143,
     144,   145,   146,   151,   148,   147,   149,    55,    55,    55,
      57,   167,   150,   174,   106,   159,   152,    57,   163,   165,
     172,   173,    28,    70,   155,   119,   171,   164,   160,     0,
      57,    57,    57,     0,    64
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         2,     3,    27,    19,    13,     6,    20,    72,     1,    31,
      75,    13,    15,    78,    79,    13,    18,    42,    20,    21,
      31,    14,    44,    88,    13,    27,   139,    46,    13,    38,
       0,    40,   145,    44,    32,     3,    38,    39,    40,   104,
      42,   102,    31,    28,    15,    46,    60,    63,    46,    47,
      48,    49,    77,    46,    13,    44,    16,    17,    60,    61,
       7,     8,     9,    15,    11,    81,   127,    13,    29,    15,
     131,    11,    23,    32,    25,    77,   152,   142,    87,    38,
      39,    15,    84,   159,    17,    87,    28,    46,    47,    48,
      49,    18,   157,   158,    21,    22,   172,   173,   174,    46,
      33,    34,    35,    36,    37,    19,     1,    16,     3,     4,
       5,    15,    14,    40,    41,    15,    11,    28,    14,    44,
      13,    15,    13,    12,    38,    39,    34,   152,    15,    15,
     146,    28,    48,    14,   159,    13,    16,    44,    14,    45,
      14,    16,    15,    14,    16,    30,    45,   172,   173,   174,
     152,    14,    36,    10,    77,    24,    26,   159,    48,    27,
      26,    26,    15,   165,   137,    89,   165,   148,   142,    -1,
     172,   173,   174,    -1,    38
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     1,     4,     5,    51,    56,    57,    58,    15,    46,
      94,    94,     0,     3,    52,    53,    15,    15,    13,    15,
      13,    28,    54,    55,    90,    94,    29,    11,    67,    56,
      56,     1,    59,    60,    90,    52,    59,    94,    15,    28,
      16,     7,     8,     9,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    81,    82,    94,    15,    14,
      15,    28,    14,    15,    54,     6,    84,    86,    87,    89,
      94,    90,    13,    81,    94,    13,    12,    15,    31,    44,
      13,    15,    59,    94,    28,    52,    44,    34,    13,    32,
      38,    39,    47,    48,    49,    74,    75,    76,    77,    81,
      83,    92,    93,    94,    31,    74,    61,    74,    74,    91,
      73,    74,    52,    94,    48,    85,    88,    90,    74,    77,
      14,    17,    33,    34,    35,    36,    37,    78,    19,    38,
      39,    79,    18,    21,    22,    40,    41,    80,    75,    13,
      74,    14,    16,    45,    14,    16,    15,    30,    16,    45,
      36,    14,    26,    75,    75,    76,    73,    23,    25,    24,
      91,    73,    52,    48,    88,    27,    62,    14,    74,    74,
      62,    84,    26,    26,    10,    72,    62,    62,    62
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    50,    51,    52,    53,    53,    54,    54,    55,    56,
      56,    56,    56,    57,    57,    58,    58,    59,    59,    59,
      60,    61,    61,    62,    62,    63,    63,    64,    65,    65,
      66,    66,    66,    67,    68,    68,    69,    70,    70,    71,
      72,    72,    73,    73,    73,    74,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78,    79,    79,    79,    80,    80,    80,
      80,    80,    81,    81,    82,    83,    84,    84,    85,    86,
      86,    87,    88,    88,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    94
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     3,     2,     0,     2,     2,     3,     3,     0,
       3,     3,     2,     4,     7,     6,     9,     0,     3,     2,
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
  "TYPE", "DIV", "MOD", "TO", "THEN", "DOWNTO", "DO", "OF", "COLON", "DOT",
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
        51,     0,    -1,    56,    52,    29,    -1,    53,    67,    -1,
      -1,     3,    54,    -1,    55,    15,    -1,    55,    15,    54,
      -1,    90,    28,    84,    -1,    -1,    57,    15,    56,    -1,
      58,    15,    56,    -1,     1,    15,    -1,     4,    94,    15,
      52,    -1,     4,    94,    13,    59,    14,    15,    52,    -1,
       5,    94,    28,    94,    15,    52,    -1,     5,    94,    13,
      59,    14,    28,    94,    15,    52,    -1,    -1,    60,    15,
      59,    -1,     1,    15,    -1,    90,    28,    94,    -1,    -1,
      62,    15,    61,    -1,    63,    -1,    66,    -1,    64,    -1,
      65,    -1,    81,    31,    74,    -1,    94,    -1,    94,    13,
      73,    14,    -1,    67,    -1,    68,    -1,    71,    -1,    11,
      61,    12,    -1,    69,    -1,    70,    -1,     7,    13,    74,
      14,    26,    62,    -1,     8,    81,    31,    74,    23,    74,
      26,    62,    -1,     8,    81,    31,    74,    25,    74,    26,
      62,    -1,     9,    13,    74,    14,    24,    62,    72,    -1,
      -1,    10,    62,    -1,    -1,    74,    -1,    74,    16,    73,
      -1,    93,    75,    -1,    75,    -1,    75,    78,    75,    -1,
      76,    -1,    76,    79,    75,    -1,    77,    -1,    77,    80,
      76,    -1,    81,    -1,    92,    -1,    47,    -1,    83,    -1,
      13,    74,    14,    -1,    32,    77,    -1,    17,    -1,    33,
      -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,    38,
      -1,    39,    -1,    19,    -1,    40,    -1,    41,    -1,    21,
      -1,    22,    -1,    18,    -1,    94,    -1,    82,    -1,    81,
      44,    91,    45,    -1,    94,    13,    73,    14,    -1,    86,
      -1,    94,    -1,    48,    30,    48,    -1,    87,    -1,    89,
      -1,     6,    44,    88,    45,    27,    84,    -1,    85,    -1,
      85,    16,    88,    -1,    94,    34,    90,    36,    -1,    94,
      -1,    94,    16,    90,    -1,    74,    -1,    74,    16,    91,
      -1,    48,    -1,    49,    -1,    38,    -1,    39,    -1,    46,
      -1
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
     150,   151,   154,   155,   157,   161,   164,   166,   170,   172,
     176,   178,   182,   184,   186,   188,   190,   194,   197,   199,
     201,   203,   205,   207,   209,   211,   213,   215,   217,   219,
     221,   223,   225,   227,   229,   234,   239,   241,   243,   247,
     249,   251,   258,   260,   264,   269,   271,   275,   277,   281,
     283,   285,   287,   289
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   109,   109,   113,   117,   118,   122,   123,   127,   131,
     132,   133,   134,   138,   139,   143,   144,   148,   149,   150,
     154,   158,   159,   163,   164,   168,   169,   173,   177,   178,
     182,   183,   184,   188,   192,   193,   197,   201,   202,   206,
     210,   211,   215,   216,   217,   221,   222,   223,   227,   228,
     232,   233,   237,   238,   239,   240,   241,   242,   246,   247,
     248,   249,   250,   251,   255,   256,   257,   261,   262,   263,
     264,   265,   269,   270,   274,   278,   282,   283,   287,   297,
     298,   302,   306,   307,   311,   315,   316,   320,   321,   325,
     326,   330,   331,   335
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
      45,    46,    47,    48,    49
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 174;
  const int Parser::yynnts_ = 45;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 12;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 50;

  const unsigned int Parser::yyuser_token_number_max_ = 304;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


} // generated

/* Line 1056 of lalr1.cc  */
#line 1674 "parser.cc"


/* Line 1058 of lalr1.cc  */
#line 337 "parser.yy"



void generated::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
     errors.push_back(std::make_pair(m, std::make_pair(l.begin.line, l.begin.column)));
}

