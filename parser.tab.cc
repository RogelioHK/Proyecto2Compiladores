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
      case symbol_kind::S_arg: // arg
      case symbol_kind::S_param: // param
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_CARACTER: // CARACTER
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lista_args: // lista_args
      case symbol_kind::S_args: // args
      case symbol_kind::S_lista_params: // lista_params
      case symbol_kind::S_params: // params
        value.copy< vector<int> > (YY_MOVE (that.value));
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
      case symbol_kind::S_arg: // arg
      case symbol_kind::S_param: // param
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_CARACTER: // CARACTER
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_lista_args: // lista_args
      case symbol_kind::S_args: // args
      case symbol_kind::S_lista_params: // lista_params
      case symbol_kind::S_params: // params
        value.move< vector<int> > (YY_MOVE (s.value));
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
      case symbol_kind::S_arg: // arg
      case symbol_kind::S_param: // param
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_CARACTER: // CARACTER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lista_args: // lista_args
      case symbol_kind::S_args: // args
      case symbol_kind::S_lista_params: // lista_params
      case symbol_kind::S_params: // params
        value.YY_MOVE_OR_COPY< vector<int> > (YY_MOVE (that.value));
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
      case symbol_kind::S_arg: // arg
      case symbol_kind::S_param: // param
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_CARACTER: // CARACTER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lista_args: // lista_args
      case symbol_kind::S_args: // args
      case symbol_kind::S_lista_params: // lista_params
      case symbol_kind::S_params: // params
        value.move< vector<int> > (YY_MOVE (that.value));
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
      case symbol_kind::S_arg: // arg
      case symbol_kind::S_param: // param
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_CARACTER: // CARACTER
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_lista_args: // lista_args
      case symbol_kind::S_args: // args
      case symbol_kind::S_lista_params: // lista_params
      case symbol_kind::S_params: // params
        value.copy< vector<int> > (that.value);
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
      case symbol_kind::S_arg: // arg
      case symbol_kind::S_param: // param
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_CARACTER: // CARACTER
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_lista_args: // lista_args
      case symbol_kind::S_args: // args
      case symbol_kind::S_lista_params: // lista_params
      case symbol_kind::S_params: // params
        value.move< vector<int> > (that.value);
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
      case symbol_kind::S_arg: // arg
      case symbol_kind::S_param: // param
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_CARACTER: // CARACTER
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_lista_args: // lista_args
      case symbol_kind::S_args: // args
      case symbol_kind::S_lista_params: // lista_params
      case symbol_kind::S_params: // params
        yylhs.value.emplace< vector<int> > ();
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
  case 2: // programa: declaraciones
#line 70 "parser.yy"
    {
        driver.print();
        driver.translate();
    }
#line 804 "parser.tab.cc"
    break;

  case 6: // $@1: %empty
#line 85 "parser.yy"
    {
        driver.pushSymT(driver.symtab()); 
    }
#line 812 "parser.tab.cc"
    break;

  case 7: // $@2: %empty
#line 89 "parser.yy"
    {
        driver.pushLabel(driver.newLab());// final
        driver._label(yystack_[1].value.as < std::string > ());
    }
#line 821 "parser.tab.cc"
    break;

  case 8: // $@3: %empty
#line 94 "parser.yy"
    {
        driver.popSymT();
    }
#line 829 "parser.tab.cc"
    break;

  case 9: // declaracion: VOID $@1 ID LPAR $@2 lista_args RPAR LKEY decl_locales bloque_sentencias $@3 RKEY
#line 98 "parser.yy"
    {
        driver.addSym(yystack_[9].value.as < std::string > (), 4, "fun", yystack_[6].value.as < vector<int> > ());
        driver._label(driver.newLabel(driver.element(0)));
        driver.popLabel(); 
    }
#line 839 "parser.tab.cc"
    break;

  case 10: // $@4: %empty
#line 104 "parser.yy"
         {driver.setType(yystack_[0].value.as < int > ());}
#line 845 "parser.tab.cc"
    break;

  case 12: // $@5: %empty
#line 109 "parser.yy"
    {
        driver.pushSymT(driver.symtab());
    }
#line 853 "parser.tab.cc"
    break;

  case 13: // $@6: %empty
#line 113 "parser.yy"
    {
        driver.estructura(yystack_[0].value.as < std::string > ());
    }
#line 861 "parser.tab.cc"
    break;

  case 14: // decl2: LKEY $@5 body_struct RKEY ID $@6 PYC
#line 117 "parser.yy"
    {
        driver.addSym(yystack_[2].value.as < std::string > (), 5, "struct");   
    }
#line 869 "parser.tab.cc"
    break;

  case 15: // $@7: %empty
#line 122 "parser.yy"
    {
        driver.pushSymT(driver.symtab());
    }
#line 877 "parser.tab.cc"
    break;

  case 16: // $@8: %empty
#line 126 "parser.yy"
    {
        driver.estructura(yystack_[4].value.as < std::string > ());
    }
#line 885 "parser.tab.cc"
    break;

  case 17: // decl2: ID $@7 LKEY body_struct RKEY $@8 PYC
#line 130 "parser.yy"
    {
        driver.addSym(yystack_[6].value.as < std::string > (), 5, "struct");
    }
#line 893 "parser.tab.cc"
    break;

  case 20: // $@9: %empty
#line 143 "parser.yy"
    {
        driver.pushLabel(driver.newLab());// final
        driver.pushSymT(driver.symtab());
        driver._label(yystack_[0].value.as < std::string > ());
    }
#line 903 "parser.tab.cc"
    break;

  case 21: // decl1: ID $@9 LPAR lista_args RPAR LKEY decl_locales bloque_sentencias RETURN expresion PYC RKEY
#line 149 "parser.yy"
    {
        
        driver._return(yystack_[11].value.as < std::string > (), yystack_[2].value.as < Expresion > ());
        driver.popSymT();
        driver.addSym(yystack_[11].value.as < std::string > (), 4, "fun", yystack_[8].value.as < vector<int> > ());
        driver._label(driver.newLabel(driver.element(0)));
        driver.popLabel();
    }
#line 916 "parser.tab.cc"
    break;

  case 22: // tipo: INT
#line 160 "parser.yy"
        { yylhs.value.as < int > () = 0; }
#line 922 "parser.tab.cc"
    break;

  case 23: // tipo: FLOAT
#line 162 "parser.yy"
          { yylhs.value.as < int > () = 1; }
#line 928 "parser.tab.cc"
    break;

  case 24: // tipo: DOUBLE
#line 164 "parser.yy"
           { yylhs.value.as < int > () = 2; }
#line 934 "parser.tab.cc"
    break;

  case 25: // tipo: CHAR
#line 166 "parser.yy"
         { yylhs.value.as < int > () = 3; }
#line 940 "parser.tab.cc"
    break;

  case 26: // lista_var: lista_var COMA ID
#line 170 "parser.yy"
                     {
        driver.addSym(yystack_[0].value.as < std::string > (), driver.getType(), "variable");
    }
#line 948 "parser.tab.cc"
    break;

  case 27: // lista_var: ID
#line 174 "parser.yy"
      {
        driver.addSym(yystack_[0].value.as < std::string > (), driver.getType(), "variable");
    }
#line 956 "parser.tab.cc"
    break;

  case 28: // lista_args: args
#line 181 "parser.yy"
    {
        yylhs.value.as < vector<int> > () = yystack_[0].value.as < vector<int> > ();
    }
#line 964 "parser.tab.cc"
    break;

  case 29: // lista_args: %empty
#line 185 "parser.yy"
    {
        yylhs.value.as < vector<int> > () = vector<int>();
    }
#line 972 "parser.tab.cc"
    break;

  case 30: // args: args COMA arg
#line 192 "parser.yy"
    {
        yylhs.value.as < vector<int> > () = vector<int>();
        yylhs.value.as < vector<int> > () = yystack_[2].value.as < vector<int> > ();
        yylhs.value.as < vector<int> > ().push_back(yystack_[0].value.as < int > ());
    }
#line 982 "parser.tab.cc"
    break;

  case 31: // args: arg
#line 199 "parser.yy"
    {
        yylhs.value.as < vector<int> > () = vector<int>();
        yylhs.value.as < vector<int> > ().push_back(yystack_[0].value.as < int > ());
    }
#line 991 "parser.tab.cc"
    break;

  case 32: // arg: tipo ID
#line 207 "parser.yy"
    {
        driver.addSym(yystack_[0].value.as < std::string > (), yystack_[1].value.as < int > (), "param");
        yylhs.value.as < int > () = yystack_[1].value.as < int > ();
    }
#line 1000 "parser.tab.cc"
    break;

  case 37: // $@10: %empty
#line 224 "parser.yy"
         {driver.setType(yystack_[0].value.as < int > ());}
#line 1006 "parser.tab.cc"
    break;

  case 41: // $@11: %empty
#line 234 "parser.yy"
    {
        driver.pushLabel(driver.newLab());// next
        driver.pushLabel(driver.newLab());// label true
        driver.pushLabel(driver.newLab());// label false
        driver._if(yystack_[0].value.as < Expresion > ().dir, driver.newLabel(driver.element(1)));        
        driver._goto(driver.newLabel(driver.element(2)));
        driver._label(driver.newLabel(driver.element(1)));
    }
#line 1019 "parser.tab.cc"
    break;

  case 42: // $@12: %empty
#line 243 "parser.yy"
    {
        driver._goto(driver.newLabel(driver.element(0)));
        driver._label(driver.newLabel(driver.element(2)));
    }
#line 1028 "parser.tab.cc"
    break;

  case 43: // sentencia: IF LPAR expresion $@11 RPAR LKEY sentencias $@12 RKEY ELSE LKEY sentencias RKEY
#line 248 "parser.yy"
    {
        driver._label(driver.newLabel(driver.element(0)));
        driver.popLabel();
        driver.popLabel();
        driver.popLabel();
    }
#line 1039 "parser.tab.cc"
    break;

  case 44: // $@13: %empty
#line 256 "parser.yy"
    {
        driver.pushLabel(driver.newLab()); // begin
        driver.pushLabel(driver.newLab()); // true
        driver.pushLabel(driver.newLab()); // false
        driver._label(driver.newLabel(driver.element(2)));
    }
#line 1050 "parser.tab.cc"
    break;

  case 45: // $@14: %empty
#line 263 "parser.yy"
    {
        driver._if(yystack_[0].value.as < Expresion > ().dir, driver.newLabel(driver.element(1)));
        driver._goto(driver.newLabel(driver.element(0)));
        driver._label(driver.newLabel(driver.element(1)));        
    }
#line 1060 "parser.tab.cc"
    break;

  case 46: // sentencia: WHILE $@13 LPAR expresion $@14 RPAR LKEY sentencias RKEY
#line 269 "parser.yy"
    {
        driver._goto(driver.newLabel(driver.element(2)));
        driver._label(driver.newLabel(driver.element(0)));
        driver.popLabel();
        driver.popLabel();
        driver.popLabel();
    }
#line 1072 "parser.tab.cc"
    break;

  case 47: // $@15: %empty
#line 278 "parser.yy"
    {
        driver.pushLabel(driver.newLab()); // true
        driver.pushLabel(driver.newLab()); // false
        driver._label(driver.newLabel(driver.element(1)));
    }
#line 1082 "parser.tab.cc"
    break;

  case 48: // $@16: %empty
#line 284 "parser.yy"
    {
        driver._if(yystack_[0].value.as < Expresion > ().dir, driver.newLabel(driver.element(1)));
        driver._goto(driver.newLabel(driver.element(0)));      
    }
#line 1091 "parser.tab.cc"
    break;

  case 49: // sentencia: DO $@15 LKEY sentencias RKEY WHILE LPAR expresion $@16 RPAR PYC
#line 289 "parser.yy"
    {
        driver._label(driver.newLabel(driver.element(0)));
        driver.popLabel();
        driver.popLabel();
    }
#line 1101 "parser.tab.cc"
    break;

  case 50: // sentencia: ID ASIG expresion PYC
#line 296 "parser.yy"
    {
        driver.asig(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Expresion > ());
    }
#line 1109 "parser.tab.cc"
    break;

  case 51: // sentencia: ID NOT expresion PYC
#line 301 "parser.yy"
    {
        driver.negacion(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Expresion > ());
    }
#line 1117 "parser.tab.cc"
    break;

  case 52: // sentencia: PRINT LPAR expresion RPAR PYC
#line 306 "parser.yy"
    {
        driver.imprimir(yystack_[2].value.as < Expresion > ());
    }
#line 1125 "parser.tab.cc"
    break;

  case 53: // sentencia: SCAN LPAR ID RPAR PYC
#line 311 "parser.yy"
    {
        driver.ler(yystack_[2].value.as < std::string > ());
    }
#line 1133 "parser.tab.cc"
    break;

  case 54: // sentencia: BREAK PYC
#line 320 "parser.yy"
             {
        
        driver._goto(driver.newLabel(driver.element(0)));
    }
#line 1142 "parser.tab.cc"
    break;

  case 55: // expresion: expresion IGUAL expresion
#line 327 "parser.yy"
                              {yylhs.value.as < Expresion > ()=driver.igual(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 1148 "parser.tab.cc"
    break;

  case 56: // expresion: expresion DIFF expresion
#line 329 "parser.yy"
                             {yylhs.value.as < Expresion > ()=driver.distinto(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 1154 "parser.tab.cc"
    break;

  case 57: // expresion: expresion AND expresion
#line 331 "parser.yy"
                            {yylhs.value.as < Expresion > ()=driver.conjuncion(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 1160 "parser.tab.cc"
    break;

  case 58: // expresion: expresion OR expresion
#line 333 "parser.yy"
                           {yylhs.value.as < Expresion > ()=driver.disyuncion(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 1166 "parser.tab.cc"
    break;

  case 59: // expresion: expresion MAYORQUE expresion
#line 335 "parser.yy"
                                 {yylhs.value.as < Expresion > ()=driver.mayor_que(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 1172 "parser.tab.cc"
    break;

  case 60: // expresion: expresion MENORQUE expresion
#line 337 "parser.yy"
                                 {yylhs.value.as < Expresion > ()=driver.menor_que(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 1178 "parser.tab.cc"
    break;

  case 61: // expresion: expresion MAYORIGUAL expresion
#line 339 "parser.yy"
                                   {yylhs.value.as < Expresion > ()=driver.mayor_o_igual(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 1184 "parser.tab.cc"
    break;

  case 62: // expresion: expresion MENORIGUAL expresion
#line 341 "parser.yy"
                                   {yylhs.value.as < Expresion > ()=driver.menor_o_igual(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 1190 "parser.tab.cc"
    break;

  case 63: // expresion: expresion MAS expresion
#line 343 "parser.yy"
                            {yylhs.value.as < Expresion > ()=driver.mas(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 1196 "parser.tab.cc"
    break;

  case 64: // expresion: expresion MENOS expresion
#line 345 "parser.yy"
                             {yylhs.value.as < Expresion > ()=driver.menos(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 1202 "parser.tab.cc"
    break;

  case 65: // expresion: expresion MUL expresion
#line 347 "parser.yy"
                           {yylhs.value.as < Expresion > ()=driver.mul(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 1208 "parser.tab.cc"
    break;

  case 66: // expresion: expresion DIV expresion
#line 349 "parser.yy"
                           {yylhs.value.as < Expresion > ()=driver.div(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 1214 "parser.tab.cc"
    break;

  case 67: // expresion: LPAR expresion RPAR
#line 351 "parser.yy"
                       {yylhs.value.as < Expresion > ()=yystack_[1].value.as < Expresion > ();}
#line 1220 "parser.tab.cc"
    break;

  case 68: // expresion: NUMERO
#line 353 "parser.yy"
          {yylhs.value.as < Expresion > ()=driver.numero(yystack_[0].value.as < std::string > (), lexer.getType());}
#line 1226 "parser.tab.cc"
    break;

  case 69: // expresion: CARACTER
#line 355 "parser.yy"
            {yylhs.value.as < Expresion > ()=driver.caracter(yystack_[0].value.as < std::string > (), lexer.getType());}
#line 1232 "parser.tab.cc"
    break;

  case 70: // expresion: ID
#line 357 "parser.yy"
      {yylhs.value.as < Expresion > ()=driver.ident(yystack_[0].value.as < std::string > ());}
#line 1238 "parser.tab.cc"
    break;

  case 71: // expresion: ID LPAR lista_params RPAR
#line 359 "parser.yy"
                              {yylhs.value.as < Expresion > ()=driver.retorno(yystack_[3].value.as < std::string > (), yystack_[1].value.as < vector<int> > ());}
#line 1244 "parser.tab.cc"
    break;

  case 72: // expresion: ID PUNTO ID
#line 361 "parser.yy"
                {yylhs.value.as < Expresion > () = driver.retStruct(yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 1250 "parser.tab.cc"
    break;

  case 73: // lista_params: params
#line 366 "parser.yy"
    {
        yylhs.value.as < vector<int> > () = yystack_[0].value.as < vector<int> > ();
    }
#line 1258 "parser.tab.cc"
    break;

  case 74: // lista_params: %empty
#line 370 "parser.yy"
    {
        yylhs.value.as < vector<int> > () = vector<int>();
    }
#line 1266 "parser.tab.cc"
    break;

  case 75: // params: params COMA param
#line 377 "parser.yy"
    {
        yylhs.value.as < vector<int> > () = vector<int>();
        yylhs.value.as < vector<int> > () = yystack_[2].value.as < vector<int> > ();
        yylhs.value.as < vector<int> > ().push_back(yystack_[0].value.as < int > ());
    }
#line 1276 "parser.tab.cc"
    break;

  case 76: // params: param
#line 384 "parser.yy"
    {
        yylhs.value.as < vector<int> > () = vector<int>();
        yylhs.value.as < vector<int> > ().push_back(yystack_[0].value.as < int > ());
    }
#line 1285 "parser.tab.cc"
    break;

  case 77: // param: expresion
#line 392 "parser.yy"
    {
        yylhs.value.as < int > () = yystack_[0].value.as < Expresion > ().type;
    }
#line 1293 "parser.tab.cc"
    break;


#line 1297 "parser.tab.cc"

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









  const signed char Parser::yypact_ninf_ = -93;

  const signed char Parser::yytable_ninf_ = -21;

  const short
  Parser::yypact_[] =
  {
      39,   -93,   -93,   -93,   -93,   -93,     2,     7,    39,   -93,
     -93,    14,   -93,   -93,   -93,   -93,   -93,    26,     3,    30,
      15,    17,   -93,    -5,   -93,    15,    36,   -93,    15,   -93,
      19,   -93,    68,    15,    59,    80,    83,   -93,    15,   -93,
      91,    64,    76,   -93,   -93,   -93,   -93,    70,    67,   -93,
      92,    15,    89,    93,   -93,   101,    15,   -93,   -93,   -93,
      15,    56,    56,    66,    71,   -93,   -93,   102,    84,    90,
     -93,   119,   -93,   118,    18,    18,    18,    95,   115,   -93,
      18,   134,   120,   -93,    18,   -15,   -93,   -93,    18,   117,
     137,   197,    18,   119,   169,    99,   -93,   157,   140,    18,
     183,   -93,    18,    18,    18,    18,    18,    18,    18,    18,
      18,    18,    18,    18,   -93,   100,   197,    79,   138,   139,
     141,   -93,   197,   121,   142,   -93,   -93,    38,    38,    38,
      38,    38,    38,    38,    38,    61,    61,   -93,   -93,   143,
     123,   170,   -93,   -93,   -93,   -93,    18,   119,   160,   144,
     -93,   119,   119,    18,   161,    97,   197,   173,   -93,   168,
     164,   163,   119,   -93,   108,   -93
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    22,    23,    24,    25,     6,     0,     0,     2,     4,
      10,     0,    15,    12,     5,     1,     3,     0,     0,     0,
       0,    27,    11,     0,     7,     0,     0,    37,    18,    36,
       0,    19,     0,    29,     0,     0,     0,    35,    29,    26,
       0,     0,    28,    31,    16,    13,    27,     0,     0,    32,
       0,     0,     0,     0,    38,     0,     0,    30,    17,    14,
       0,    34,    34,     0,     0,    44,    47,     0,     0,     0,
       8,    33,    40,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,    39,     0,    70,    68,    69,     0,     0,
       0,    41,     0,     0,     0,     0,     9,     0,     0,    74,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,    45,     0,     0,     0,
       0,    72,    77,     0,    73,    76,    67,    59,    60,    61,
      62,    55,    56,    57,    58,    63,    64,    65,    66,     0,
       0,     0,    52,    53,    21,    71,     0,     0,     0,     0,
      75,    42,     0,     0,     0,     0,    48,     0,    46,     0,
       0,     0,     0,    49,     0,    43
  };

  const short
  Parser::yypgoto_[] =
  {
     -93,   -93,   -93,   214,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   211,   -93,   -93,    10,   201,   200,   -93,
     188,   178,   -47,   -17,   -93,   -92,   -71,   -93,   -93,   -93,
     -93,   -93,   -93,   -72,   -93,   -93,    96
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     7,     8,     9,    11,    33,    82,    17,    14,    20,
      53,    19,    52,    26,    22,    30,    27,    23,    41,    42,
      43,    70,    28,    29,    36,    71,    72,   115,   154,    77,
     140,    78,   159,   122,   123,   124,   125
  };

  const short
  Parser::yytable_[] =
  {
      83,   117,    89,    90,    91,    12,    98,    15,    94,    61,
      10,    37,    97,    62,    31,    32,   100,    18,    10,    13,
     116,    85,    86,    87,    99,     1,     2,     3,     4,    21,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,    24,    40,    37,    37,    83,    25,    40,     1,
       2,     3,     4,     5,    35,   151,   -20,    88,    38,    63,
     155,    40,    64,     6,    65,    66,     1,     2,     3,     4,
     164,    39,    67,   110,   111,   112,   113,    44,    68,    69,
      83,   156,    63,    45,    83,    64,    46,    65,    66,    54,
      32,    74,    75,    83,    49,    67,    51,   141,   112,   113,
      63,    68,    69,    64,    50,    65,    66,    55,    58,    56,
      76,    63,    59,    67,    64,   158,    65,    66,    60,    68,
      69,    79,    63,    80,    67,    64,   165,    65,    66,    81,
      68,    69,    93,    84,    92,    67,   101,    95,    96,   119,
     139,    68,    69,   121,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   142,   143,   144,
     147,   145,   146,   148,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   120,   152,   149,   157,
     160,   162,   163,   153,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   161,   118,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    16,   126,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    34,    47,    48,    57,
      73,     0,   150
  };

  const short
  Parser::yycheck_[] =
  {
      71,    93,    74,    75,    76,     3,    21,     0,    80,    56,
       0,    28,    84,    60,    19,    20,    88,     3,     8,    17,
      92,     3,     4,     5,    39,    10,    11,    12,    13,     3,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    39,    33,    61,    62,   117,    17,    38,    10,
      11,    12,    13,    14,    18,   147,    39,    39,    39,     3,
     152,    51,     6,    24,     8,     9,    10,    11,    12,    13,
     162,     3,    16,    35,    36,    37,    38,    18,    22,    23,
     151,   153,     3,     3,   155,     6,     3,     8,     9,    19,
      20,    25,    26,   164,     3,    16,    20,    18,    37,    38,
       3,    22,    23,     6,    40,     8,     9,    40,    19,    17,
      39,     3,    19,    16,     6,    18,     8,     9,    17,    22,
      23,    19,     3,    39,    16,     6,    18,     8,     9,    39,
      22,    23,    17,    15,    39,    16,    19,     3,    18,    40,
      40,    22,    23,     3,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    19,    19,    19,    18,
      17,    40,    20,    40,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    19,    17,     8,    18,
       7,    17,    19,    39,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    40,    40,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,     8,    40,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    25,    36,    38,    51,
      62,    -1,   146
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    10,    11,    12,    13,    14,    24,    42,    43,    44,
      57,    45,     3,    17,    49,     0,    44,    48,     3,    52,
      50,     3,    55,    58,    39,    17,    54,    57,    63,    64,
      56,    19,    20,    46,    54,    18,    65,    64,    39,     3,
      57,    59,    60,    61,    18,     3,     3,    58,    59,     3,
      40,    20,    53,    51,    19,    40,    17,    61,    19,    19,
      17,    63,    63,     3,     6,     8,     9,    16,    22,    23,
      62,    66,    67,    62,    25,    26,    39,    70,    72,    19,
      39,    39,    47,    67,    15,     3,     4,     5,    39,    74,
      74,    74,    39,    17,    74,     3,    18,    74,    21,    39,
      74,    19,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    19,    68,    74,    66,    40,    40,
      19,     3,    74,    75,    76,    77,    40,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    40,
      71,    18,    19,    19,    18,    40,    20,    17,    40,     8,
      77,    66,    17,    39,    69,    66,    74,    18,    18,    73,
       7,    40,    17,    19,    66,    18
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    41,    42,    43,    43,    44,    45,    46,    47,    44,
      48,    44,    50,    51,    49,    52,    53,    49,    54,    55,
      56,    55,    57,    57,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    62,    62,    63,    63,    65,    64,    66,
      66,    68,    69,    67,    70,    71,    67,    72,    73,    67,
      67,    67,    67,    67,    67,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    76,    77
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     0,     0,     0,    12,
       0,     3,     0,     0,     7,     0,     0,     7,     1,     2,
       0,    12,     1,     1,     1,     1,     3,     1,     1,     0,
       3,     1,     2,     1,     0,     2,     1,     0,     4,     2,
       1,     0,     0,    13,     0,     0,     9,     0,     0,    11,
       4,     4,     5,     5,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     4,     3,     1,     0,     3,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMERO",
  "CARACTER", "IF", "ELSE", "WHILE", "DO", "INT", "FLOAT", "DOUBLE",
  "CHAR", "VOID", "RETURN", "BREAK", "LKEY", "RKEY", "PYC", "COMA",
  "PUNTO", "PRINT", "SCAN", "STRUCT", "ASIG", "NOT", "MAYORQUE",
  "MENORQUE", "MAYORIGUAL", "MENORIGUAL", "IGUAL", "DIFF", "AND", "OR",
  "MAS", "MENOS", "MUL", "DIV", "LPAR", "RPAR", "$accept", "programa",
  "declaraciones", "declaracion", "$@1", "$@2", "$@3", "$@4", "decl2",
  "$@5", "$@6", "$@7", "$@8", "body_struct", "decl1", "$@9", "tipo",
  "lista_var", "lista_args", "args", "arg", "bloque_sentencias",
  "decl_locales", "decl_local", "$@10", "sentencias", "sentencia", "$@11",
  "$@12", "$@13", "$@14", "$@15", "$@16", "expresion", "lista_params",
  "params", "param", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    69,    69,    77,    78,    82,    85,    89,    94,    84,
     104,   104,   109,   113,   108,   122,   126,   121,   136,   140,
     143,   142,   160,   162,   164,   166,   170,   174,   180,   185,
     191,   198,   206,   214,   215,   219,   220,   224,   224,   228,
     229,   234,   243,   233,   256,   263,   255,   278,   284,   277,
     295,   300,   305,   310,   320,   327,   329,   331,   333,   335,
     337,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   365,   370,   376,   383,   391
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
    };
    // Last valid token kind.
    const int code_max = 295;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1780 "parser.tab.cc"

#line 397 "parser.yy"


void yy::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l <<" whith token "<<lexer.getVal()<< endl;
}
