// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 31 "parser.yy"

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "Driver.hpp"
#include "Lexer.hpp"

#undef yylex
#define yylex lexer.yylex

#line 58 "parser.tab.cc"


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


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
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
    while (false)
# endif


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
      *yycdebug_ << '\n';                       \
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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 150 "parser.tab.cc"

  /// Build a parser object.
  Parser::Parser (Lexer  &lexer_yyarg, Driver  &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg),
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_expresion: // expresion
        value.copy< Expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_expresion: // expresion
        value.move< Expresion > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expresion: // expresion
        value.YY_MOVE_OR_COPY< Expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expresion: // expresion
        value.move< Expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expresion: // expresion
        value.copy< Expresion > (that.value);
        break;

      case symbol_kind::S_tipo: // tipo
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expresion: // expresion
        value.move< Expresion > (that.value);
        break;

      case symbol_kind::S_tipo: // tipo
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
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

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
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

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_expresion: // expresion
        yylhs.value.emplace< Expresion > ();
        break;

      case symbol_kind::S_tipo: // tipo
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // programa: declaraciones sentencias
#line 68 "parser.yy"
    {
        driver.print();
        driver.translate();
    }
#line 734 "parser.tab.cc"
    break;

  case 5: // $@1: %empty
#line 80 "parser.yy"
         {driver.setType(yystack_[0].value.as < int > ());}
#line 740 "parser.tab.cc"
    break;

  case 7: // tipo: INT
#line 84 "parser.yy"
        { yylhs.value.as < int > ()= 0;}
#line 746 "parser.tab.cc"
    break;

  case 8: // tipo: FLOAT
#line 86 "parser.yy"
          {yylhs.value.as < int > ()=1;}
#line 752 "parser.tab.cc"
    break;

  case 9: // lista_var: lista_var COMA ID
#line 90 "parser.yy"
                     {
        driver.addSym(yystack_[0].value.as < std::string > (), driver.getType(), "variable");
    }
#line 760 "parser.tab.cc"
    break;

  case 10: // lista_var: ID
#line 94 "parser.yy"
      {
        driver.addSym(yystack_[0].value.as < std::string > (), driver.getType(), "variable");
    }
#line 768 "parser.tab.cc"
    break;

  case 13: // $@2: %empty
#line 106 "parser.yy"
    {
        driver.pushLabel(driver.newLab());// next
        driver.pushLabel(driver.newLab());// label true
        driver.pushLabel(driver.newLab());// label false
        driver._if(yystack_[0].value.as < Expresion > ().dir, driver.newLabel(driver.element(1)));        
        driver._goto(driver.newLabel(driver.element(0)));
        driver._label(driver.newLabel(driver.element(1)));
    }
#line 781 "parser.tab.cc"
    break;

  case 14: // $@3: %empty
#line 115 "parser.yy"
    {
        driver._goto(driver.newLabel(driver.element(2)));
        driver._label(driver.newLabel(driver.element(0)));
    }
#line 790 "parser.tab.cc"
    break;

  case 15: // sentencia: IF LPAR expresion $@2 RPAR LKEY sentencias $@3 RKEY ELSE LKEY sentencias RKEY
#line 120 "parser.yy"
    {
        driver._label(driver.newLabel(driver.element(2)));
        driver.popLabel();
        driver.popLabel();
        driver.popLabel();
    }
#line 801 "parser.tab.cc"
    break;

  case 16: // $@4: %empty
#line 128 "parser.yy"
    {
        driver.pushLabel(driver.newLab()); // begin
        driver.pushLabel(driver.newLab()); // true
        driver.pushLabel(driver.newLab()); // false
    }
#line 811 "parser.tab.cc"
    break;

  case 17: // $@5: %empty
#line 134 "parser.yy"
    {
        driver._label(driver.newLabel(driver.element(2)));
        driver._if(yystack_[0].value.as < Expresion > ().dir, driver.newLabel(driver.element(1)));
        driver._goto(driver.newLabel(driver.element(0)));
        driver._label(driver.newLabel(driver.element(1)));        
    }
#line 822 "parser.tab.cc"
    break;

  case 18: // sentencia: WHILE $@4 LPAR expresion $@5 RPAR LKEY sentencias RKEY
#line 141 "parser.yy"
    {
        driver._goto(driver.newLabel(driver.element(2)));
        driver.popLabel();
        driver.popLabel();
        driver.popLabel();
    }
#line 833 "parser.tab.cc"
    break;

  case 19: // sentencia: ID ASIG expresion PYC
#line 149 "parser.yy"
    {
        driver.asig(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Expresion > ());
    }
#line 841 "parser.tab.cc"
    break;

  case 20: // sentencia: ID NOT expresion PYC
#line 154 "parser.yy"
    {
        driver.negacion(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Expresion > ());
    }
#line 849 "parser.tab.cc"
    break;

  case 21: // expresion: expresion IGUAL expresion
#line 160 "parser.yy"
                              {yylhs.value.as < Expresion > ()=driver.igual(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 855 "parser.tab.cc"
    break;

  case 22: // expresion: expresion DIFF expresion
#line 162 "parser.yy"
                             {yylhs.value.as < Expresion > ()=driver.distinto(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 861 "parser.tab.cc"
    break;

  case 23: // expresion: expresion AND expresion
#line 164 "parser.yy"
                            {yylhs.value.as < Expresion > ()=driver.conjuncion(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 867 "parser.tab.cc"
    break;

  case 24: // expresion: expresion OR expresion
#line 166 "parser.yy"
                           {yylhs.value.as < Expresion > ()=driver.disyuncion(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 873 "parser.tab.cc"
    break;

  case 25: // expresion: expresion MAYORQUE expresion
#line 168 "parser.yy"
                                 {yylhs.value.as < Expresion > ()=driver.mayor_que(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 879 "parser.tab.cc"
    break;

  case 26: // expresion: expresion MENORQUE expresion
#line 170 "parser.yy"
                                 {yylhs.value.as < Expresion > ()=driver.menor_que(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 885 "parser.tab.cc"
    break;

  case 27: // expresion: expresion MAYORIGUAL expresion
#line 172 "parser.yy"
                                   {yylhs.value.as < Expresion > ()=driver.mayor_o_igual(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 891 "parser.tab.cc"
    break;

  case 28: // expresion: expresion MENORIGUAL expresion
#line 174 "parser.yy"
                                   {yylhs.value.as < Expresion > ()=driver.menor_o_igual(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 897 "parser.tab.cc"
    break;

  case 29: // expresion: expresion MAS expresion
#line 176 "parser.yy"
                            {yylhs.value.as < Expresion > ()=driver.mas(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 903 "parser.tab.cc"
    break;

  case 30: // expresion: expresion MENOS expresion
#line 178 "parser.yy"
                             {yylhs.value.as < Expresion > ()=driver.menos(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 909 "parser.tab.cc"
    break;

  case 31: // expresion: expresion MUL expresion
#line 180 "parser.yy"
                           {yylhs.value.as < Expresion > ()=driver.mul(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 915 "parser.tab.cc"
    break;

  case 32: // expresion: expresion DIV expresion
#line 182 "parser.yy"
                           {yylhs.value.as < Expresion > ()=driver.div(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 921 "parser.tab.cc"
    break;

  case 33: // expresion: LPAR expresion RPAR
#line 184 "parser.yy"
                       {yylhs.value.as < Expresion > ()=yystack_[1].value.as < Expresion > ();}
#line 927 "parser.tab.cc"
    break;

  case 34: // expresion: NUMERO
#line 186 "parser.yy"
          {yylhs.value.as < Expresion > ()=driver.numero(yystack_[0].value.as < std::string > (), lexer.getType());}
#line 933 "parser.tab.cc"
    break;

  case 35: // expresion: ID
#line 188 "parser.yy"
      {yylhs.value.as < Expresion > ()=driver.ident(yystack_[0].value.as < std::string > ());}
#line 939 "parser.tab.cc"
    break;


#line 943 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
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
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char Parser::yypact_ninf_ = -58;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      -5,   -58,   -58,     8,    98,   -58,   -58,   -58,    -3,   -14,
     -58,   -58,   105,   -58,    12,     2,     2,     2,   -11,   -58,
     -58,    20,   -58,   -58,     2,    19,    47,    73,     2,   -58,
      31,    59,   -58,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   -58,    24,    73,   -58,   -58,
      89,    89,    89,    89,    89,    89,    89,    89,    34,    34,
     -58,   -58,    48,    58,   105,    92,   105,   105,    93,    44,
     103,   -58,   101,   105,    45,   -58
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     7,     8,     0,     0,     4,     5,     1,     0,     0,
      16,     3,     2,    12,     0,     0,     0,     0,     0,    11,
      10,     0,    35,    34,     0,     0,     0,    13,     0,     6,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,     0,    17,     9,    33,
      25,    26,    27,    28,    21,    22,    23,    24,    29,    30,
      31,    32,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    18,     0,     0,     0,    15
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -58,   -58,   -58,   113,   -58,   -58,   -58,   -57,   -12,   -58,
     -58,   -58,   -58,   -15
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     3,     4,     5,    14,     6,    21,    12,    13,    46,
      68,    18,    63,    25
  };

  const signed char
  Parser::yytable_[] =
  {
      19,    26,    27,     1,     2,    22,    23,    66,     7,    31,
      69,    15,    16,    47,    17,    20,    74,    28,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      24,    32,    29,    30,    48,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     8,     8,     9,
       9,    10,    10,    62,    19,    71,    75,    19,    64,    45,
      43,    44,    19,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    65,    49,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     8,    67,     9,    70,    10,     1,     2,     8,    72,
       9,    73,    10,    41,    42,    43,    44,    11
  };

  const signed char
  Parser::yycheck_[] =
  {
      12,    16,    17,     8,     9,     3,     4,    64,     0,    24,
      67,    14,    15,    28,    28,     3,    73,    28,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      28,    12,    12,    13,     3,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     3,     3,     5,
       5,     7,     7,    29,    66,    11,    11,    69,    10,    12,
      26,    27,    74,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    29,    29,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     3,    10,     5,    11,     7,     8,     9,     3,     6,
       5,    10,     7,    24,    25,    26,    27,     4
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     8,     9,    31,    32,    33,    35,     0,     3,     5,
       7,    33,    37,    38,    34,    14,    15,    28,    41,    38,
       3,    36,     3,     4,    28,    43,    43,    43,    28,    12,
      13,    43,    12,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    12,    39,    43,     3,    29,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    29,    42,    10,    29,    37,    10,    40,    37,
      11,    11,     6,    10,    37,    11
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    30,    31,    32,    32,    34,    33,    35,    35,    36,
      36,    37,    37,    39,    40,    38,    41,    42,    38,    38,
      38,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     2,     1,     0,     4,     1,     1,     3,
       1,     2,     1,     0,     0,    13,     0,     0,     9,     4,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMERO", "IF",
  "ELSE", "WHILE", "INT", "FLOAT", "LKEY", "RKEY", "PYC", "COMA", "ASIG",
  "NOT", "MAYORQUE", "MENORQUE", "MAYORIGUAL", "MENORIGUAL", "IGUAL",
  "DIFF", "AND", "OR", "MAS", "MENOS", "MUL", "DIV", "LPAR", "RPAR",
  "$accept", "programa", "declaraciones", "declaracion", "$@1", "tipo",
  "lista_var", "sentencias", "sentencia", "$@2", "$@3", "$@4", "$@5",
  "expresion", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    67,    67,    75,    76,    80,    80,    84,    86,    90,
      94,   100,   101,   106,   115,   105,   128,   134,   127,   148,
     153,   160,   162,   164,   166,   168,   170,   172,   174,   176,
     178,   180,   182,   184,   186,   188
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
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
      25,    26,    27,    28,    29
    };
    // Last valid token kind.
    const int code_max = 284;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1351 "parser.tab.cc"

#line 193 "parser.yy"



void yy::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l <<" whith token "<<lexer.getVal()<< endl;
}
