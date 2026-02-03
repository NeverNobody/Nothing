%option noyywrap
%{
#include <stdio.h>
%}

ws           [ \t\n]+
digit        [0-9]
octalnum     0[0-7]+
hexanum      0[xX][0-9a-fA-F]+
bitstring    0[bB][01]+
exponent     [eE][+-]?{digit}+
float1       {digit}+\.{digit}*({exponent})?
float2       \.{digit}+({exponent})?
float3       {digit}+({exponent})
charlit      '\\?.'
delimiter    ,|;
number       {digit}+

%%
{ws}           {;}
{float1}       {printf(" (Token, Lexeme) = (FLOAT, %s)\n", yytext); return 10;}
{float2}       {printf(" (Token, Lexeme) = (FLOAT, %s)\n", yytext); return 10;}
{float3}       {printf(" (Token, Lexeme) = (FLOAT, %s)\n", yytext); return 10;}
{hexanum}      {printf(" (Token, Lexeme) = (HEXA NUMBER, %s)\n", yytext); return 8;}
{bitstring}    {printf(" (Token, Lexeme) = (BIT STRING, %s)\n", yytext); return 9;}
{octalnum}     {printf(" (Token, Lexeme) = (OCTAL NUMBER, %s)\n", yytext); return 3;}
{number}       {printf(" (Token, Lexeme) = (DECIMAL NUMBER, %s)\n", yytext); return 2;}
{charlit}      {printf(" (Token, Lexeme) = (CHAR LITERAL, %s)\n", yytext); return 11;}
{delimiter}    {printf(" (Token, Lexeme) = (DELIMITER, '%s')\n", yytext); return 5;}
.              {/* ignore unknowns */}
%%
int main()
{ while(yylex()); 
  return 0;
}
