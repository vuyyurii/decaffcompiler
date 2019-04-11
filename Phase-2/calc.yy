%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>
#include "ast.h"
#include "scanner.h"
#include "driver.h"

%}

/*** yacc/bison Declarations ***/
/* =========================== */

/* Require bison 2.3 or later */
/* =========================== */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
 /* ================================================================ */
%debug

/* start symbol is named "start" */
/* ============================ */
%start program

/* write out a header file containing the token defines */
/* ==================================================== */
%defines

/* use newer C++ skeleton file */
/* =========================== */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
/* ============================== */
%name-prefix="decaf"

/* set the parser's class identifier */
/* ================================= */
%define "parser_class_name" "Parser"

/* keep track of the current position within the input */
/* =================================================== */
%locations

%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
 /* ===================================================================== */
%parse-param { class Driver& driver }

/* verbose error messages */
/* ===================== */
%error-verbose

%union
{
	int ival;
	std::string *sval;
    class ASTnode* astnode;
    class FieldDecNode* fieldnode;
	class ProgramNode* pronode;
	class CalloutArgNode* calloutargnode;
	class CalloutNode* calloutnode;
	class MethodArgNode* methodargnode;
	class ArgNode* argumentnode;
	class MethodCallNode* methodcallnode;
	class MethodNode* methodnode;
	class MthdNode* method_declnode;
	class FuncNode* functionnode;
	class Statement* statenode;
	class StTerminateNode* termnode;
	class BlockNode* blocknode;
	class StNode* statementsnode;
	class BlockASTnode* block;
	class Expr* expnode;
	class StrLitNode* stringnode;
	class StLocationNode* statlocnode;
	class MStNode* methodstatnode;
	class UnaryOPNode* unarynode;
	class Locnode* locationnode;
	class VarNode* varnode;
	class VarsNode* varsnode;
	class VariaNode* varinode;
	class VarDeclNode* vardeclnode;
	class VarDecsnode* vardeclsnode;
	class BoolLitNODe* boolnode;
	class CharLitNode* charnode;
	class IntLitNode* intnode;
	class IfNode* ifnode;
	class IfElseNode* ifelsenode;
	class ForAst* fornode;
	class ReturnNode* returnnode;
}

%type <astnode> literal
%type <pronode> program
%type <calloutargnode> calloutarg
%type <calloutnode> callout
%type <methodargnode> method_arg
%type <block> block
%type <method_declnode> method_decl
%type <functionnode> function
%type <locationnode> location
%type <vardeclnode> var_declaration
%type <vardeclsnode> var_declarations
%type <varinode> vars 
%type <fieldnode> field_decl
%type <expnode> expr
%type <varnode> variable
%type <varsnode> var
%type <methodnode> method_name
%type <stringnode> string_literal
%type <argumentnode> arguments
%type <methodcallnode> method_call
%type <statementsnode> statements
%type <statenode> statement
%type <statlocnode> statement1
%type <methodstatnode> statement2
%type <ifnode> statement3
%type <ifelsenode> statement4
%type <fornode> statement5
%type <returnnode> statement6
%type <termnode> statement7
%type <blocknode> statement8
%type <boolnode> bool_literal
%type <charnode> char_literal
%type <intnode> int_literal

//%destructor { delete $$; } expr

%{

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}
%token END 0
%token EOL
%token<ival> NUM HEX
%token<sval> PROGRAM CALLOUT CLASS FOR IF ELSE CONTINUE BREAK RETURN TRUE FALSE 
%token<sval> INT BOOLEAN VOID 
%token<sval> ID CHAR CHARLIT STRLIT
%token<sval> LFB RFB LB RB LSB RSB SEMICOL COMMA 
%token<sval> PLUS MINUS MUL EQ DIV LT GT MOD NOT PLUSEQ MINUSEQ 
%token<sval> EQEQ NOTEQ GTEQ LTEQ AND OR 

%left PLUS MINUS
%left MUL DIV
%left AND OR LT GT LTEQ GTEQ EQEQ NOTEQ

%%

program    : CLASS PROGRAM LFB function RFB 			   { $$ = new ProgramNode($4); driver.ast.pRoot = $$;}

function   : 											   {$$ = new FuncNode();}
		   | field_decl function 						   {$$ = $2;$$->push_back($1);}
		   | method_decl function						   {$$ = $2;$$->push_back($1);}

field_decl : INT var SEMICOL							   { $$ = new FieldDecNode(*$1,$2,";");}
		   | BOOLEAN var SEMICOL						   { $$ = new FieldDecNode(*$1,$2,";");}

method_decl: INT ID LB arguments RB block				   {$$ = new MthdNode(*$1,*$2,$4,$6);}
		   | BOOLEAN ID LB arguments RB block			   {$$ = new MthdNode(*$1,*$2,$4,$6);}
		   | VOID ID LB arguments RB block				   {$$ = new MthdNode(*$1,*$2,$4,$6);}

arguments  : 											   {$$ = new ArgNode();}
		   | INT ID										   {$$ = new ArgNode(*$1,*$2);}
		   | BOOLEAN ID									   {$$ = new ArgNode(*$1,*$2);}
		   | arguments COMMA INT ID						   {$$ = new ArgNode(*$3,*$4);$$->push_back($1);}
		   | arguments COMMA BOOLEAN ID					   {$$ = new ArgNode(*$3,*$4);$$->push_back($1);}

block      : LFB var_declarations statements RFB		   {$$ = new BlockASTnode($2,$3);}

var_declarations : 					                       {$$ = new VarDecsnode();}	
		 		 | var_declaration var_declarations        {$2->push_back($1);$$ = $2;}

var_declaration : INT vars SEMICOL 						   {$$ = new VarDeclNode(*$1,$2,";");}
				| BOOLEAN vars SEMICOL  				   {$$ = new VarDeclNode(*$1,$2,";");}
				;

var        : variable 									    { $$ = new VarsNode();$$->push_back($1);}
	       | var COMMA variable							    { $$ = $1;$$->push_back($3);}
	       ;

variable   : ID 										    { $$ = new VarNode(*$1);}
		   | ID LSB int_literal RSB						    { $$ = new VarNode(*$1,$3);}
		   ;

vars       : ID 										    { $$ = new VariaNode();$$->push_back(*$1);}
	       | vars COMMA ID								    { $$ = $1;$$->push_back(*$3);}
	       ;

statement  : statement1										{$$ = new Statement($1);}
		   |statement2										{$$ = new Statement($1);}
		   |statement3										{$$ = new Statement($1);}
		   |statement4										{$$ = new Statement($1);}
		   |statement5										{$$ = new Statement($1);}
		   |statement6										{$$ = new Statement($1);}
		   |statement7										{$$ = new Statement($1);}
		   |statement8										{$$ = new Statement($1);}

statement1 :location EQ expr SEMICOL						{$$ = new StLocationNode($1,*$2,$3);}
		   | location PLUSEQ expr SEMICOL					{$$ = new StLocationNode($1,*$2,$3);}
		   | location MINUSEQ expr SEMICOL					{$$ = new StLocationNode($1,*$2,$3);}

statement2 :method_call SEMICOL								{$$ = new MStNode($1);}
statement3 :IF LB expr RB block								{$$ = new IfNode($3,$5);}
statement4 :IF LB expr RB block ELSE block					{$$ = new IfElseNode($3,$5,$7);}
statement5 :FOR ID EQ expr COMMA expr block					{$$ = new ForAst(*$2,$4,$6,$7);}
statement6 :RETURN expr SEMICOL								{$$ = new ReturnNode($2);}
statement7 :RETURN SEMICOL									{$$ = new StTerminateNode(*$1);}
		   | BREAK SEMICOL									{$$ = new StTerminateNode(*$1);}
		   | CONTINUE SEMICOL								{$$ = new StTerminateNode(*$1);}
statement8 :block											{$$ = new BlockNode($1);}
statements : 												{$$ = new StNode();}
		   | statement statements							{$$ = $2;$$->push_back($1);}

method_call: method_name LB method_arg RB					{$$ = new MethodCallNode($1,$3);}
		   | CALLOUT LB string_literal COMMA callout RB		{$$ = new MethodCallNode(*$1,$3,$5);}
		   | CALLOUT LB string_literal RB					{$$ = new MethodCallNode(*$1,$3);}

method_decl: INT ID LB arguments RB block					{$$ = new MthdNode(*$1,*$2,$4,$6);}
		   | BOOLEAN ID LB arguments RB block				{$$ = new MthdNode(*$1,*$2,$4,$6);}
		   | VOID ID LB arguments RB block					{$$ = new MthdNode(*$1,*$2,$4,$6);}

method_name: ID												{$$ = new MethodNode(*$1);}

method_arg : 												{$$ = new MethodArgNode();}
		   | expr 											{$$ = new MethodArgNode();$$->push_back($1);}
		   | method_arg COMMA expr							{$$ = $1;$$->push_back($3);}

callout    : calloutarg 									{ $$ = new CalloutNode();$$->push_back($1);}
		   | callout COMMA calloutarg						{ $$ = $1;$$->push_back($3);}

calloutarg : expr 											{$$ = new CalloutArgNode($1);}
		   | string_literal									{$$ = new CalloutArgNode($1);}


location   : ID 											{ $$ = new Locnode(*$1);}
		   | ID LSB expr RSB								{ $$ = new Locnode(*$1,$3);}

expr       : location										{ $$ = new Expr($1); }
	       | literal										{ $$ = new Expr($1);}
	       | method_call									{ $$ = new Expr($1);}
	       | expr PLUS expr									{ $$ = new Expr(new BinaryASTnode("+", $1, $3)); }
	       | expr MINUS expr								{ $$ = new Expr(new BinaryASTnode("-", $1, $3)); }
	       | expr MUL expr									{ $$ = new Expr(new BinaryASTnode("*", $1, $3)); }
	 	   | expr MOD expr									{ $$ = new Expr(new BinaryASTnode("%", $1, $3)); }
	 	   | expr DIV expr									{ $$ = new Expr(new BinaryASTnode("/", $1, $3)); }
	 	   | expr LT expr									{ $$ = new Expr(new BinaryASTnode("<", $1, $3)); }
	 	   | expr GT expr									{ $$ = new Expr(new BinaryASTnode(">", $1, $3)); }
	 	   | expr LTEQ expr									{ $$ = new Expr(new BinaryASTnode("<=", $1, $3)); }
	 	   | expr GTEQ expr									{ $$ = new Expr(new BinaryASTnode(">=", $1, $3)); }
	 	   | expr EQEQ expr									{ $$ = new Expr(new BinaryASTnode("==", $1, $3)); }
	 	   | expr NOTEQ expr								{ $$ = new Expr(new BinaryASTnode("!=", $1, $3)); }
	 	   | expr AND expr									{ $$ = new Expr(new BinaryASTnode("&&", $1, $3)); }
	 	   | expr OR expr									{ $$ = new Expr(new BinaryASTnode("||", $1, $3)); }
	 	   | MINUS expr										{ $$ = new Expr(new UnaryOPNode("-", $2)); }
	 	   | NOT expr										{ $$ = new Expr(new UnaryOPNode("!", $2)); }
	 	   | LB expr RB										{ $$ = new Expr($2);}

literal    :int_literal										{$$ = $1;}
		   |bool_literal									{$$ = $1;}
		   |char_literal									{$$ = $1;}

int_literal: NUM 											{$$ = new IntLitNode($1);}
 		   | HEX											{$$ = new IntLitNode($1);}

bool_literal   : TRUE 										{$$ = new BoolLitNODe(true);}
			   | FALSE										{$$ = new BoolLitNODe(false);}

char_literal   : CHARLIT									{$$ = new CharLitNode(*$1);}

string_literal : STRLIT 									{$$=new StrLitNode(*$1);}

%%

void decaf::Parser::error(const Parser::location_type& l,
			    		  const std::string& m)
{
    driver.error(l, m);
}
