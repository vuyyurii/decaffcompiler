%{
#include <stdio.h>
#include "parser.tab.h"
extern int yylex();
int lineno = 0;
%}

alpha [a-zA-Z]
digit [0-9]
comments "//".*
id {alpha}({alpha}|{digit})*
number {digit}{digit}*
hexnumber 0x({digit}[a-fA-F])({digit}[a-fA-F])*
character (\\n|\\t|\\'|\\\\|\\\"|[^\\"'])
char (')
stringliteral ["]({alpha}|{character})*["]
charliteral {char}{character}{char}

%%
"int"				{return INT;}
"boolean"			{return BOOLEAN;}
"class"			    {return CLASS;}
"true"				{return TRUE;}
"false"				{return FALSE;}
"for"			    {return FOR;}
"if"			    {return IF;}
"else"			    {return ELSE;}
"break"			    {return BREAK;}
"continue"			{return CONTINUE;}
"void"			    {return VOID;}
"callout"			{return CALLOUT;}
"return"			{return RETURN;}
{id}                return ID;
{number}          	return NUMBER;
{hexnumber}         return HEXNUMBER;
{charliteral}       return CHARLITERAL;
{stringliteral}	    return STRINGLITERAL;
"+"					{return '+';}
"-"					{return '-';}
"*"					{return '*';}
"%"					{return '%';}
"/"					{return '/';}
","					{return ',';}
";"					{return ';';}
"("					{return '(';}
")"					{return ')';}
"["					{return '[';}
"]"					{return ']';}
"{"					{return '{';}
"}"					{return '}';}
">"					{return '>';}
"!"					{return '!';}
"="					{return '=';}
"\""				{return '"';}
"'"					{return '\'';}
"+="				{return PLUSEQUAL;}
"-="				{return MINUSEQUAL;}
">="				{return GREATERTHANEQUAL;}
"=="				{return EQUALEQUAL;}
"<"					{return '<';}
"<="				{return LESSTHANEQUAL;}
"&&"				{return ANDAND;}
"||"				{return OROR;}
"!="				{return NOTEQUAL;}
{comments}			return COMMENTS;
[ \t]				{ }
\n		     		{++lineno;}
.					{ printf("Line No %d: Unrecognized Character\n", lineno); }

%%

