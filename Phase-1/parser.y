%{
#include <stdio.h>
int yylex();
void yyerror(char * s );
%}

%token ID DIGIT ANDAND OROR EQUALEQUAL NOTEQUAL GREATERTHANEQUAL LESSTHANEQUAL
%token CHARLITERAL STRINGLITERAL INT BOOLEAN PLUSEQUAL MINUSEQUAL CLASS CONTINUE IF FOR
%token CALLOUT VOID COMMENTS NUMBER OX HEXNUMBER CHAR TRUE FALSE RETURN BREAK ELSE
%left '+' '-'
%left '*' '/'
%left ANDAND OROR '<' '>' LESSTHANEQUAL GREATERTHANEQUAL EQUALEQUAL NOTEQUAL

%%
program : CLASS ID '{' funcbody '}'

funcbody : | fielddecl funcbody | methoddecl funcbody

fielddecl : type var ';'

var : variable | var ',' variable

variable : ID | ID '[' int_literal ']'

methoddecl : type ID '(' arguments ')' block | VOID ID '(' arguments ')' block

arguments : | type ID | arguments ',' type ID

block : '{' vardecls statements '}'

vardecls : | vardecl | vardecls

vardecl : type varia ';'

varia : ID | varia ',' ID

type : INT | BOOLEAN

statements : | statement statements

statement : location assign_op expr ';'
		  | methodcall ';'
		  | IF '(' expr ')' block
		  | IF '(' expr ')' block ELSE block
		  | FOR ID '=' expr ',' expr block
		  | RETURN expr ';'
		  | RETURN ';'
		  | BREAK ';'
		  | CONTINUE ';'
		  | block

assign_op : '=' | PLUSEQUAL | MINUSEQUAL

methodcall : method_name '(' methodarguments ')'
		   | CALLOUT '(' string_literal ')'
		   | CALLOUT '(' string_literal ',' callout ')'

method_name : ID

callout : calloutarg | callout ',' calloutarg

calloutarg : expr | string_literal

methodarguments : | expr | methodarguments ',' expr 

expr :'(' expr ')'
	 |  expr '+' expr
	 |  expr '-' expr
	 |  expr '*' expr
	 |  expr '%' expr
	 |  expr '/' expr
	 |  expr '<' expr
	 |  expr '>' expr
	 |  '-' expr
	 |  '!' expr
	 |  literal
	 |  expr EQUALEQUAL expr
	 |  expr NOTEQUAL expr
	 |  expr GREATERTHANEQUAL expr
	 |  expr LESSTHANEQUAL expr
	 |  expr ANDAND expr
	 |  expr OROR expr
	 |  location

location : ID | ID '[' expr ']'

literal : int_literal | char_literal | bool_literal

int_literal : decimal_literal | hex_literal

decimal_literal : NUMBER

hex_literal : HEXNUMBER

bool_literal : TRUE | FALSE

char_literal : CHARLITERAL 

string_literal : STRINGLITERAL

%%

int main(int argc, char **argv)
{
	yyparse();
	printf("Parsing Over\n");
}


void yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}
