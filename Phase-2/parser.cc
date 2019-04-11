// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Take the name prefix into account.
#define yylex   decaflex

// First part of user declarations.
#line 1 "calc.yy" // lalr1.cc:404
 /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>
#include "ast.h"
#include "scanner.h"
#include "driver.h"


#line 49 "parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.h"

// User implementation prologue.
#line 140 "calc.yy" // lalr1.cc:412


/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


#line 72 "parser.cc" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace decaf {
#line 158 "parser.cc" // lalr1.cc:479

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
              // Fall through.
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


  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
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
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 49 "calc.yy" // lalr1.cc:741
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}

#line 537 "parser.cc" // lalr1.cc:741

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 165 "calc.yy" // lalr1.cc:859
    { (yylhs.value.pronode) = new ProgramNode((yystack_[1].value.functionnode)); driver.ast.pRoot = (yylhs.value.pronode);}
#line 647 "parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 167 "calc.yy" // lalr1.cc:859
    {(yylhs.value.functionnode) = new FuncNode();}
#line 653 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 168 "calc.yy" // lalr1.cc:859
    {(yylhs.value.functionnode) = (yystack_[0].value.functionnode);(yylhs.value.functionnode)->push_back((yystack_[1].value.fieldnode));}
#line 659 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 169 "calc.yy" // lalr1.cc:859
    {(yylhs.value.functionnode) = (yystack_[0].value.functionnode);(yylhs.value.functionnode)->push_back((yystack_[1].value.method_declnode));}
#line 665 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 171 "calc.yy" // lalr1.cc:859
    { (yylhs.value.fieldnode) = new FieldDecNode(*(yystack_[2].value.sval),(yystack_[1].value.varsnode),";");}
#line 671 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 172 "calc.yy" // lalr1.cc:859
    { (yylhs.value.fieldnode) = new FieldDecNode(*(yystack_[2].value.sval),(yystack_[1].value.varsnode),";");}
#line 677 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 174 "calc.yy" // lalr1.cc:859
    {(yylhs.value.method_declnode) = new MthdNode(*(yystack_[5].value.sval),*(yystack_[4].value.sval),(yystack_[2].value.argumentnode),(yystack_[0].value.block));}
#line 683 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 175 "calc.yy" // lalr1.cc:859
    {(yylhs.value.method_declnode) = new MthdNode(*(yystack_[5].value.sval),*(yystack_[4].value.sval),(yystack_[2].value.argumentnode),(yystack_[0].value.block));}
#line 689 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 176 "calc.yy" // lalr1.cc:859
    {(yylhs.value.method_declnode) = new MthdNode(*(yystack_[5].value.sval),*(yystack_[4].value.sval),(yystack_[2].value.argumentnode),(yystack_[0].value.block));}
#line 695 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 178 "calc.yy" // lalr1.cc:859
    {(yylhs.value.argumentnode) = new ArgNode();}
#line 701 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 179 "calc.yy" // lalr1.cc:859
    {(yylhs.value.argumentnode) = new ArgNode(*(yystack_[1].value.sval),*(yystack_[0].value.sval));}
#line 707 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 180 "calc.yy" // lalr1.cc:859
    {(yylhs.value.argumentnode) = new ArgNode(*(yystack_[1].value.sval),*(yystack_[0].value.sval));}
#line 713 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 181 "calc.yy" // lalr1.cc:859
    {(yylhs.value.argumentnode) = new ArgNode(*(yystack_[1].value.sval),*(yystack_[0].value.sval));(yylhs.value.argumentnode)->push_back((yystack_[3].value.argumentnode));}
#line 719 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 182 "calc.yy" // lalr1.cc:859
    {(yylhs.value.argumentnode) = new ArgNode(*(yystack_[1].value.sval),*(yystack_[0].value.sval));(yylhs.value.argumentnode)->push_back((yystack_[3].value.argumentnode));}
#line 725 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 184 "calc.yy" // lalr1.cc:859
    {(yylhs.value.block) = new BlockASTnode((yystack_[2].value.vardeclsnode),(yystack_[1].value.statementsnode));}
#line 731 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 186 "calc.yy" // lalr1.cc:859
    {(yylhs.value.vardeclsnode) = new VarDecsnode();}
#line 737 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 187 "calc.yy" // lalr1.cc:859
    {(yystack_[0].value.vardeclsnode)->push_back((yystack_[1].value.vardeclnode));(yylhs.value.vardeclsnode) = (yystack_[0].value.vardeclsnode);}
#line 743 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 189 "calc.yy" // lalr1.cc:859
    {(yylhs.value.vardeclnode) = new VarDeclNode(*(yystack_[2].value.sval),(yystack_[1].value.varinode),";");}
#line 749 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 190 "calc.yy" // lalr1.cc:859
    {(yylhs.value.vardeclnode) = new VarDeclNode(*(yystack_[2].value.sval),(yystack_[1].value.varinode),";");}
#line 755 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 193 "calc.yy" // lalr1.cc:859
    { (yylhs.value.varsnode) = new VarsNode();(yylhs.value.varsnode)->push_back((yystack_[0].value.varnode));}
#line 761 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 194 "calc.yy" // lalr1.cc:859
    { (yylhs.value.varsnode) = (yystack_[2].value.varsnode);(yylhs.value.varsnode)->push_back((yystack_[0].value.varnode));}
#line 767 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 197 "calc.yy" // lalr1.cc:859
    { (yylhs.value.varnode) = new VarNode(*(yystack_[0].value.sval));}
#line 773 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 198 "calc.yy" // lalr1.cc:859
    { (yylhs.value.varnode) = new VarNode(*(yystack_[3].value.sval),(yystack_[1].value.intnode));}
#line 779 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 201 "calc.yy" // lalr1.cc:859
    { (yylhs.value.varinode) = new VariaNode();(yylhs.value.varinode)->push_back(*(yystack_[0].value.sval));}
#line 785 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 202 "calc.yy" // lalr1.cc:859
    { (yylhs.value.varinode) = (yystack_[2].value.varinode);(yylhs.value.varinode)->push_back(*(yystack_[0].value.sval));}
#line 791 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 205 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statenode) = new Statement((yystack_[0].value.statlocnode));}
#line 797 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 206 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statenode) = new Statement((yystack_[0].value.methodstatnode));}
#line 803 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 207 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statenode) = new Statement((yystack_[0].value.ifnode));}
#line 809 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 208 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statenode) = new Statement((yystack_[0].value.ifelsenode));}
#line 815 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 209 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statenode) = new Statement((yystack_[0].value.fornode));}
#line 821 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 210 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statenode) = new Statement((yystack_[0].value.returnnode));}
#line 827 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 211 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statenode) = new Statement((yystack_[0].value.termnode));}
#line 833 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 212 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statenode) = new Statement((yystack_[0].value.blocknode));}
#line 839 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 214 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statlocnode) = new StLocationNode((yystack_[3].value.locationnode),*(yystack_[2].value.sval),(yystack_[1].value.expnode));}
#line 845 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 215 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statlocnode) = new StLocationNode((yystack_[3].value.locationnode),*(yystack_[2].value.sval),(yystack_[1].value.expnode));}
#line 851 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 216 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statlocnode) = new StLocationNode((yystack_[3].value.locationnode),*(yystack_[2].value.sval),(yystack_[1].value.expnode));}
#line 857 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 218 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodstatnode) = new MStNode((yystack_[1].value.methodcallnode));}
#line 863 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 219 "calc.yy" // lalr1.cc:859
    {(yylhs.value.ifnode) = new IfNode((yystack_[2].value.expnode),(yystack_[0].value.block));}
#line 869 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 220 "calc.yy" // lalr1.cc:859
    {(yylhs.value.ifelsenode) = new IfElseNode((yystack_[4].value.expnode),(yystack_[2].value.block),(yystack_[0].value.block));}
#line 875 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 221 "calc.yy" // lalr1.cc:859
    {(yylhs.value.fornode) = new ForAst(*(yystack_[5].value.sval),(yystack_[3].value.expnode),(yystack_[1].value.expnode),(yystack_[0].value.block));}
#line 881 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 222 "calc.yy" // lalr1.cc:859
    {(yylhs.value.returnnode) = new ReturnNode((yystack_[1].value.expnode));}
#line 887 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 223 "calc.yy" // lalr1.cc:859
    {(yylhs.value.termnode) = new StTerminateNode(*(yystack_[1].value.sval));}
#line 893 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 224 "calc.yy" // lalr1.cc:859
    {(yylhs.value.termnode) = new StTerminateNode(*(yystack_[1].value.sval));}
#line 899 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 225 "calc.yy" // lalr1.cc:859
    {(yylhs.value.termnode) = new StTerminateNode(*(yystack_[1].value.sval));}
#line 905 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 226 "calc.yy" // lalr1.cc:859
    {(yylhs.value.blocknode) = new BlockNode((yystack_[0].value.block));}
#line 911 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 227 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statementsnode) = new StNode();}
#line 917 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 228 "calc.yy" // lalr1.cc:859
    {(yylhs.value.statementsnode) = (yystack_[0].value.statementsnode);(yylhs.value.statementsnode)->push_back((yystack_[1].value.statenode));}
#line 923 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 230 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodcallnode) = new MethodCallNode((yystack_[3].value.methodnode),(yystack_[1].value.methodargnode));}
#line 929 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 231 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodcallnode) = new MethodCallNode(*(yystack_[5].value.sval),(yystack_[3].value.stringnode),(yystack_[1].value.calloutnode));}
#line 935 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 232 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodcallnode) = new MethodCallNode(*(yystack_[3].value.sval),(yystack_[1].value.stringnode));}
#line 941 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 234 "calc.yy" // lalr1.cc:859
    {(yylhs.value.method_declnode) = new MthdNode(*(yystack_[5].value.sval),*(yystack_[4].value.sval),(yystack_[2].value.argumentnode),(yystack_[0].value.block));}
#line 947 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 235 "calc.yy" // lalr1.cc:859
    {(yylhs.value.method_declnode) = new MthdNode(*(yystack_[5].value.sval),*(yystack_[4].value.sval),(yystack_[2].value.argumentnode),(yystack_[0].value.block));}
#line 953 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 236 "calc.yy" // lalr1.cc:859
    {(yylhs.value.method_declnode) = new MthdNode(*(yystack_[5].value.sval),*(yystack_[4].value.sval),(yystack_[2].value.argumentnode),(yystack_[0].value.block));}
#line 959 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 238 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodnode) = new MethodNode(*(yystack_[0].value.sval));}
#line 965 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 240 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodargnode) = new MethodArgNode();}
#line 971 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 241 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodargnode) = new MethodArgNode();(yylhs.value.methodargnode)->push_back((yystack_[0].value.expnode));}
#line 977 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 242 "calc.yy" // lalr1.cc:859
    {(yylhs.value.methodargnode) = (yystack_[2].value.methodargnode);(yylhs.value.methodargnode)->push_back((yystack_[0].value.expnode));}
#line 983 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 244 "calc.yy" // lalr1.cc:859
    { (yylhs.value.calloutnode) = new CalloutNode();(yylhs.value.calloutnode)->push_back((yystack_[0].value.calloutargnode));}
#line 989 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 245 "calc.yy" // lalr1.cc:859
    { (yylhs.value.calloutnode) = (yystack_[2].value.calloutnode);(yylhs.value.calloutnode)->push_back((yystack_[0].value.calloutargnode));}
#line 995 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 247 "calc.yy" // lalr1.cc:859
    {(yylhs.value.calloutargnode) = new CalloutArgNode((yystack_[0].value.expnode));}
#line 1001 "parser.cc" // lalr1.cc:859
    break;

  case 62:
#line 248 "calc.yy" // lalr1.cc:859
    {(yylhs.value.calloutargnode) = new CalloutArgNode((yystack_[0].value.stringnode));}
#line 1007 "parser.cc" // lalr1.cc:859
    break;

  case 63:
#line 251 "calc.yy" // lalr1.cc:859
    { (yylhs.value.locationnode) = new Locnode(*(yystack_[0].value.sval));}
#line 1013 "parser.cc" // lalr1.cc:859
    break;

  case 64:
#line 252 "calc.yy" // lalr1.cc:859
    { (yylhs.value.locationnode) = new Locnode(*(yystack_[3].value.sval),(yystack_[1].value.expnode));}
#line 1019 "parser.cc" // lalr1.cc:859
    break;

  case 65:
#line 254 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr((yystack_[0].value.locationnode)); }
#line 1025 "parser.cc" // lalr1.cc:859
    break;

  case 66:
#line 255 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr((yystack_[0].value.astnode));}
#line 1031 "parser.cc" // lalr1.cc:859
    break;

  case 67:
#line 256 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr((yystack_[0].value.methodcallnode));}
#line 1037 "parser.cc" // lalr1.cc:859
    break;

  case 68:
#line 257 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new BinaryASTnode("+", (yystack_[2].value.expnode), (yystack_[0].value.expnode))); }
#line 1043 "parser.cc" // lalr1.cc:859
    break;

  case 69:
#line 258 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new BinaryASTnode("-", (yystack_[2].value.expnode), (yystack_[0].value.expnode))); }
#line 1049 "parser.cc" // lalr1.cc:859
    break;

  case 70:
#line 259 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new BinaryASTnode("*", (yystack_[2].value.expnode), (yystack_[0].value.expnode))); }
#line 1055 "parser.cc" // lalr1.cc:859
    break;

  case 71:
#line 260 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new BinaryASTnode("%", (yystack_[2].value.expnode), (yystack_[0].value.expnode))); }
#line 1061 "parser.cc" // lalr1.cc:859
    break;

  case 72:
#line 261 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new BinaryASTnode("/", (yystack_[2].value.expnode), (yystack_[0].value.expnode))); }
#line 1067 "parser.cc" // lalr1.cc:859
    break;

  case 73:
#line 262 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new BinaryASTnode("<", (yystack_[2].value.expnode), (yystack_[0].value.expnode))); }
#line 1073 "parser.cc" // lalr1.cc:859
    break;

  case 74:
#line 263 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new BinaryASTnode(">", (yystack_[2].value.expnode), (yystack_[0].value.expnode))); }
#line 1079 "parser.cc" // lalr1.cc:859
    break;

  case 75:
#line 264 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new BinaryASTnode("<=", (yystack_[2].value.expnode), (yystack_[0].value.expnode))); }
#line 1085 "parser.cc" // lalr1.cc:859
    break;

  case 76:
#line 265 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new BinaryASTnode(">=", (yystack_[2].value.expnode), (yystack_[0].value.expnode))); }
#line 1091 "parser.cc" // lalr1.cc:859
    break;

  case 77:
#line 266 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new BinaryASTnode("==", (yystack_[2].value.expnode), (yystack_[0].value.expnode))); }
#line 1097 "parser.cc" // lalr1.cc:859
    break;

  case 78:
#line 267 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new BinaryASTnode("!=", (yystack_[2].value.expnode), (yystack_[0].value.expnode))); }
#line 1103 "parser.cc" // lalr1.cc:859
    break;

  case 79:
#line 268 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new BinaryASTnode("&&", (yystack_[2].value.expnode), (yystack_[0].value.expnode))); }
#line 1109 "parser.cc" // lalr1.cc:859
    break;

  case 80:
#line 269 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new BinaryASTnode("||", (yystack_[2].value.expnode), (yystack_[0].value.expnode))); }
#line 1115 "parser.cc" // lalr1.cc:859
    break;

  case 81:
#line 270 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new UnaryOPNode("-", (yystack_[0].value.expnode))); }
#line 1121 "parser.cc" // lalr1.cc:859
    break;

  case 82:
#line 271 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr(new UnaryOPNode("!", (yystack_[0].value.expnode))); }
#line 1127 "parser.cc" // lalr1.cc:859
    break;

  case 83:
#line 272 "calc.yy" // lalr1.cc:859
    { (yylhs.value.expnode) = new Expr((yystack_[1].value.expnode));}
#line 1133 "parser.cc" // lalr1.cc:859
    break;

  case 84:
#line 274 "calc.yy" // lalr1.cc:859
    {(yylhs.value.astnode) = (yystack_[0].value.intnode);}
#line 1139 "parser.cc" // lalr1.cc:859
    break;

  case 85:
#line 275 "calc.yy" // lalr1.cc:859
    {(yylhs.value.astnode) = (yystack_[0].value.boolnode);}
#line 1145 "parser.cc" // lalr1.cc:859
    break;

  case 86:
#line 276 "calc.yy" // lalr1.cc:859
    {(yylhs.value.astnode) = (yystack_[0].value.charnode);}
#line 1151 "parser.cc" // lalr1.cc:859
    break;

  case 87:
#line 278 "calc.yy" // lalr1.cc:859
    {(yylhs.value.intnode) = new IntLitNode((yystack_[0].value.ival));}
#line 1157 "parser.cc" // lalr1.cc:859
    break;

  case 88:
#line 279 "calc.yy" // lalr1.cc:859
    {(yylhs.value.intnode) = new IntLitNode((yystack_[0].value.ival));}
#line 1163 "parser.cc" // lalr1.cc:859
    break;

  case 89:
#line 281 "calc.yy" // lalr1.cc:859
    {(yylhs.value.boolnode) = new BoolLitNODe(true);}
#line 1169 "parser.cc" // lalr1.cc:859
    break;

  case 90:
#line 282 "calc.yy" // lalr1.cc:859
    {(yylhs.value.boolnode) = new BoolLitNODe(false);}
#line 1175 "parser.cc" // lalr1.cc:859
    break;

  case 91:
#line 284 "calc.yy" // lalr1.cc:859
    {(yylhs.value.charnode) = new CharLitNode(*(yystack_[0].value.sval));}
#line 1181 "parser.cc" // lalr1.cc:859
    break;

  case 92:
#line 286 "calc.yy" // lalr1.cc:859
    {(yylhs.value.stringnode)=new StrLitNode(*(yystack_[0].value.sval));}
#line 1187 "parser.cc" // lalr1.cc:859
    break;


#line 1191 "parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
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
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -65;

  const signed char Parser::yytable_ninf_ = -56;

  const short int
  Parser::yypact_[] =
  {
      -6,     4,    13,    17,   -65,    37,     7,    30,    50,    52,
      37,    37,    -7,    54,   -65,    10,    61,    55,   -65,   -65,
     -65,    77,   101,   -65,    68,    77,   -65,    77,    78,    82,
     -15,   -65,   -65,    94,    97,   -65,     3,     6,   -65,   -65,
     105,    96,   -65,   105,   105,    98,   -65,   111,   112,   -65,
     -65,   115,   115,    66,    98,   -65,   -65,   -65,    87,    91,
     110,   119,   116,   113,   124,    67,    73,   -65,    66,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   120,   125,   123,
     -27,   -65,   -65,   121,   -65,   133,   129,   104,   -65,   -65,
     -65,   -65,   -65,   104,   -65,   104,   104,   -65,   -65,   197,
     -65,   -65,   -65,   -65,   104,   -65,   -65,   -65,   104,   104,
     104,   104,   -65,   -65,    12,   104,   136,   158,   304,   289,
     -65,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   178,    21,   289,   216,   235,   254,
     -65,     2,   272,   105,   -65,   304,   304,   316,   316,   126,
     126,   289,   126,   126,   126,   126,   126,   126,   -65,   -65,
     104,   -65,   -65,   -65,    22,   -65,   289,   -65,   104,   155,
     289,   -65,     2,   114,   105,   -65,   -65,   -65
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     3,     0,     0,     0,     0,
       3,     3,    23,     0,    21,    23,     0,     0,     2,     4,
       5,    11,     0,     6,     0,    11,     7,    11,     0,     0,
       0,    87,    88,     0,    23,    22,     0,     0,    12,    13,
       0,     0,    24,     0,     0,    17,     8,     0,     0,     9,
      10,     0,     0,    47,    17,    14,    15,    25,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    46,    47,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,     0,
       0,    18,    19,     0,    20,     0,     0,     0,    45,    44,
      89,    90,    91,     0,    43,     0,     0,    67,    65,     0,
      66,    84,    85,    86,     0,    48,    16,    38,    56,     0,
       0,     0,    26,    92,     0,     0,     0,     0,    81,    82,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,     0,     0,
      51,     0,     0,     0,    83,    68,    69,    70,    72,    73,
      74,    71,    77,    78,    76,    75,    79,    80,    64,    49,
       0,    35,    36,    37,     0,    59,    61,    62,     0,    39,
      58,    50,     0,     0,     0,    60,    41,    40
  };

  const short int
  Parser::yypgoto_[] =
  {
     -65,   -65,   117,   -65,   -65,    85,   -40,    86,   -65,   160,
     147,   134,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   108,   -48,   -65,   -65,   -65,     5,   -42,   -64,   -65,
     156,   -65,   -65,   102
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     2,     9,    10,    11,    30,    67,    53,    54,    13,
      14,    58,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    97,    79,   135,   164,   165,    98,   166,   100,
     101,   102,   103,   167
  };

  const short int
  Parser::yytable_[] =
  {
      46,    99,     1,    49,    50,    78,    31,    32,   109,    60,
       3,    80,    40,     4,   110,   111,    41,    90,    91,    21,
      78,    22,    66,   116,    92,   113,    80,    12,    93,   117,
      43,   118,   119,    44,    41,    95,    25,    41,    22,   140,
     134,     5,    96,   141,   136,   137,   138,   139,   159,   171,
      15,   142,   160,   172,     6,     7,     8,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      17,    31,    32,    60,    60,    61,    62,    18,    63,    64,
      65,    27,    90,    91,    23,    24,    66,    66,    34,    92,
      45,    26,    24,    93,    28,    29,   170,    94,    38,   -55,
      95,   104,    39,   169,   173,    31,    32,    96,    31,    32,
      36,    60,    37,    47,    48,    51,    52,    82,    83,    90,
      91,    84,    83,    42,    66,    22,    92,    19,    20,    45,
      93,    55,    56,   176,   177,    57,    85,    95,    45,    86,
      81,   112,    87,    88,    96,   106,   121,   122,   123,   108,
     124,   125,   126,   127,    89,   107,   113,   128,   129,   130,
     131,   132,   133,   143,   115,   127,   174,    16,   121,   122,
     123,    35,   124,   125,   126,   127,   105,   175,    33,   128,
     129,   130,   131,   132,   133,   144,    59,   114,     0,     0,
     121,   122,   123,     0,   124,   125,   126,   127,     0,     0,
       0,   128,   129,   130,   131,   132,   133,   158,     0,     0,
     121,   122,   123,     0,   124,   125,   126,   127,     0,     0,
       0,   128,   129,   130,   131,   132,   133,   120,     0,   121,
     122,   123,     0,   124,   125,   126,   127,     0,     0,     0,
     128,   129,   130,   131,   132,   133,   161,     0,   121,   122,
     123,     0,   124,   125,   126,   127,     0,     0,     0,   128,
     129,   130,   131,   132,   133,   162,     0,   121,   122,   123,
       0,   124,   125,   126,   127,     0,     0,     0,   128,   129,
     130,   131,   132,   133,   163,     0,   121,   122,   123,     0,
     124,   125,   126,   127,     0,     0,     0,   128,   129,   130,
     131,   132,   133,   168,   121,   122,   123,     0,   124,   125,
     126,   127,     0,     0,     0,   128,   129,   130,   131,   132,
     133,   121,   122,   123,     0,   124,   125,   126,   127,     0,
       0,     0,   128,   129,   130,   131,   132,   133,   123,     0,
     124,   125,   126,   127,     0,     0,     0,   128,   129,   130,
     131,   132,   133,   125,   126,   127,     0,     0,     0,   128,
     129,   130,   131,   132,   133
  };

  const short int
  Parser::yycheck_[] =
  {
      40,    65,     8,    43,    44,    53,     4,     5,    35,     7,
       6,    53,    27,     0,    41,    42,    31,    15,    16,    26,
      68,    28,    20,    87,    22,    23,    68,    20,    26,    93,
      27,    95,    96,    27,    31,    33,    26,    31,    28,    27,
     104,    24,    40,    31,   108,   109,   110,   111,    27,    27,
      20,   115,    31,    31,    17,    18,    19,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      20,     4,     5,     7,     7,     9,    10,    25,    12,    13,
      14,    26,    15,    16,    30,    31,    20,    20,    20,    22,
      24,    30,    31,    26,    17,    18,   160,    30,    20,    26,
      33,    28,    20,   143,   168,     4,     5,    40,     4,     5,
      25,     7,    27,    17,    18,    17,    18,    30,    31,    15,
      16,    30,    31,    29,    20,    28,    22,    10,    11,    24,
      26,    20,    20,   173,   174,    20,    26,    33,    24,    20,
      54,    20,    26,    30,    40,    25,    32,    33,    34,    26,
      36,    37,    38,    39,    30,    30,    23,    43,    44,    45,
      46,    47,    48,    27,    35,    39,    11,     7,    32,    33,
      34,    24,    36,    37,    38,    39,    68,   172,    22,    43,
      44,    45,    46,    47,    48,    27,    52,    85,    -1,    -1,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    29,    -1,    -1,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    30,    -1,    32,
      33,    34,    -1,    36,    37,    38,    39,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    30,    -1,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    30,    -1,    32,    33,    34,
      -1,    36,    37,    38,    39,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    30,    -1,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    32,    33,    34,    -1,    36,    37,    38,    39,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    37,    38,    39,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     8,    50,     6,     0,    24,    17,    18,    19,    51,
      52,    53,    20,    58,    59,    20,    58,    20,    25,    51,
      51,    26,    28,    30,    31,    26,    30,    26,    17,    18,
      54,     4,     5,    79,    20,    59,    54,    54,    20,    20,
      27,    31,    29,    27,    27,    24,    55,    17,    18,    55,
      55,    17,    18,    56,    57,    20,    20,    20,    60,    60,
       7,     9,    10,    12,    13,    14,    20,    55,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      76,    56,    30,    31,    30,    26,    20,    26,    30,    30,
      15,    16,    22,    26,    30,    33,    40,    71,    76,    77,
      78,    79,    80,    81,    28,    70,    25,    30,    26,    35,
      41,    42,    20,    23,    82,    35,    77,    77,    77,    77,
      30,    32,    33,    34,    36,    37,    38,    39,    43,    44,
      45,    46,    47,    48,    77,    73,    77,    77,    77,    77,
      27,    31,    77,    27,    27,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    29,    27,
      31,    30,    30,    30,    74,    75,    77,    82,    31,    55,
      77,    27,    31,    77,    11,    75,    55,    55
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    49,    50,    51,    51,    51,    52,    52,    53,    53,
      53,    54,    54,    54,    54,    54,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    62,    63,    64,
      65,    66,    67,    68,    68,    68,    69,    70,    70,    71,
      71,    71,    53,    53,    53,    72,    73,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    80,
      80,    81,    82
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     5,     0,     2,     2,     3,     3,     6,     6,
       6,     0,     2,     2,     4,     4,     4,     0,     2,     3,
       3,     1,     3,     1,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     2,     5,
       7,     7,     3,     2,     2,     2,     1,     0,     2,     4,
       6,     4,     6,     6,     6,     1,     0,     1,     3,     1,
       3,     1,     1,     1,     4,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "$undefined", "EOL", "NUM", "HEX", "PROGRAM", "CALLOUT",
  "CLASS", "FOR", "IF", "ELSE", "CONTINUE", "BREAK", "RETURN", "TRUE",
  "FALSE", "INT", "BOOLEAN", "VOID", "ID", "CHAR", "CHARLIT", "STRLIT",
  "LFB", "RFB", "LB", "RB", "LSB", "RSB", "SEMICOL", "COMMA", "PLUS",
  "MINUS", "MUL", "EQ", "DIV", "LT", "GT", "MOD", "NOT", "PLUSEQ",
  "MINUSEQ", "EQEQ", "NOTEQ", "GTEQ", "LTEQ", "AND", "OR", "$accept",
  "program", "function", "field_decl", "method_decl", "arguments", "block",
  "var_declarations", "var_declaration", "var", "variable", "vars",
  "statement", "statement1", "statement2", "statement3", "statement4",
  "statement5", "statement6", "statement7", "statement8", "statements",
  "method_call", "method_name", "method_arg", "callout", "calloutarg",
  "location", "expr", "literal", "int_literal", "bool_literal",
  "char_literal", "string_literal", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   165,   165,   167,   168,   169,   171,   172,   174,   175,
     176,   178,   179,   180,   181,   182,   184,   186,   187,   189,
     190,   193,   194,   197,   198,   201,   202,   205,   206,   207,
     208,   209,   210,   211,   212,   214,   215,   216,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   230,
     231,   232,   234,   235,   236,   238,   240,   241,   242,   244,
     245,   247,   248,   251,   252,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   274,   275,   276,   278,   279,   281,
     282,   284,   286
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
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
    const unsigned int user_token_number_max_ = 303;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // decaf
#line 1772 "parser.cc" // lalr1.cc:1167
#line 288 "calc.yy" // lalr1.cc:1168


void decaf::Parser::error(const Parser::location_type& l,
			    		  const std::string& m)
{
    driver.error(l, m);
}
