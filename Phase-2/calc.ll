%{

#include <string>
#include "scanner.h"

/* import the parser's token type into a local typedef */
typedef decaf::Parser::token_type token_type;
typedef decaf::Parser::token token;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */

#define yyterminate() return token::END
#define YY_NO_UNISTD_H

int lineno = 0;

%}

/*** Flex Declarations and Options ***/
/* =============================== */

/* enable c++ scanner class generation */
/* =================================== */
%option c++

/* change the name of the scanner class. results in "decafFlexLexer" */
/* ================================================================= */
%option prefix="decaf"

/* the manual says "somewhat more optimized" */
/* ========================================= */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */ 
/* =============================================================== */
%option debug

%option yylineno

/* no support for include files is planned */
/* ======================================= */
%option yywrap nounput 

/* enables the use of start condition stacks */
/* ========================================= */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
/* ===================================================================== */
%{
    #define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%% /*** Regular Expressions Part ***/


 /* code to place at the beginning of yylex() */
 /* ========================================= */
%{
    // reset location
    yylloc->step();
%}

"class"			              {yylval->sval = new std::string(yytext); return token::CLASS;}
"Program"                     {yylval->sval = new std::string(yytext); return token::PROGRAM;}
"callout"                     {yylval->sval = new std::string(yytext); return token::CALLOUT;}
"void"			              {yylval->sval = new std::string(yytext); return token::VOID;}
"boolean"                     {yylval->sval = new std::string(yytext); return token::BOOLEAN;}
"int"                         {yylval->sval = new std::string(yytext); return token::INT;}
"for"			              {yylval->sval = new std::string(yytext); return token::FOR;}
"if"                          {yylval->sval = new std::string(yytext); return token::IF;}
"else"                        {yylval->sval = new std::string(yytext); return token::ELSE;}
"continue"                    {yylval->sval = new std::string(yytext); return token::CONTINUE;}
"break"			              {yylval->sval = new std::string(yytext); return token::BREAK;}
"true"				          {yylval->sval = new std::string(yytext); return token::TRUE;}
"false"				          {yylval->sval = new std::string(yytext); return token::FALSE;}
"return"			          {yylval->sval = new std::string(yytext); return token::RETURN;}
[a-zA-Z]([a-zA-Z]|[0-9])*     {yylval->sval = new std::string(yytext); return token::ID;}
[0-9]+          	          {yylval->ival = std::atoi(yytext); return token::NUM;}
0x([0-9][a-fA-F])+            {yylval->ival = std::atoi(yytext); return token::HEX;}
"("					          {yylval->sval = new std::string(yytext); return token::LB;}
")"					          {yylval->sval = new std::string(yytext); return token::RB;}
"{"					          {yylval->sval = new std::string(yytext); return token::LFB;}
"}"					          {yylval->sval = new std::string(yytext); return token::RFB;}
"["					          {yylval->sval = new std::string(yytext); return token::LSB;}
"]"					          {yylval->sval = new std::string(yytext); return token::RSB;}
"!"					          {yylval->sval = new std::string(yytext); return token::NOT;}
"+"					          {yylval->sval = new std::string(yytext); return token::PLUS;}
"-"					          {yylval->sval = new std::string(yytext); return token::MINUS;}
"*"					          {yylval->sval = new std::string(yytext); return token::MUL;}
"/"					          {yylval->sval = new std::string(yytext); return token::DIV;}
"%"					          {yylval->sval = new std::string(yytext); return token::MOD;}
"<"					          {yylval->sval = new std::string(yytext); return token::LT;}
">"					          {yylval->sval = new std::string(yytext); return token::GT;}
"="					          {yylval->sval = new std::string(yytext); return token::EQ;}
"=="				          {yylval->sval = new std::string(yytext); return token::EQEQ;}
">="				          {yylval->sval = new std::string(yytext); return token::GTEQ;}
"<="				          {yylval->sval = new std::string(yytext); return token::LTEQ;}
"!="				          {yylval->sval = new std::string(yytext); return token::NOTEQ;}
"+="				          {yylval->sval = new std::string(yytext); return token::PLUSEQ;}
"-="				          {yylval->sval = new std::string(yytext); return token::MINUSEQ;}
"&&"				          {yylval->sval = new std::string(yytext); return token::AND;}
"||"				          {yylval->sval = new std::string(yytext); return token::OR;}
","					          {yylval->sval = new std::string(yytext); return token::COMMA;}
";"					          {yylval->sval = new std::string(yytext); return token::SEMICOL;}
"'"(\\n|\\t|\\'|\\\\|\\\"|[^\\"'])"'"   {yylval->sval = new std::string(yytext); return token::CHARLIT;}
\"(\\n|\\t|\\'|\\\\|\\\"|[^\\"'])*\"   {yylval->sval = new std::string(yytext); return token::STRLIT;}


 /* gobble up white-spaces */
 /* ====================== */
[ \t\r]+    {
                yylloc->step();
            }

 /* gobble up end-of-lines */
 /* ====================== */
\n          {
                yylloc->lines(yyleng);
                yylloc->step();
                return token::EOL;
            }

 /* pass all other characters up to bison */
 /* ===================================== */
.           {
                return static_cast<token_type>(*yytext);
            }


%% /*** Additional Code ***/
   /* ================== */

namespace decaf {

Scanner::Scanner(std::istream* in,std::ostream* out): decafFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}

/* This implementation of DecafFlexLexer::yylex() is required to fill the
 * vtable of the class DecafFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int decafFlexLexer::yylex()
{
    std::cerr << "in decafFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int decafFlexLexer::yywrap()
{
    return 1;
}
