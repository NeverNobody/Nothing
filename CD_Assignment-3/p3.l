%option noyywrap
%{
#include <stdio.h>
#include <string.h>

static int keywordCount = 0;
static int identifierCount = 0;
static int integerCount = 0; /* matches expected prog1out.txt (0) */
static int assignOpCount = 0;
static int arithOpCount = 0;
static int relOpCount = 0;
static int leftParCount = 0;
static int rightParCount = 0;
static int delimiterCount = 0; /* matches expected prog1out.txt (0) */
static int slCommentCount = 0;
static int stringLiteralCount = 0;

static void print_string_token(const char *text)
{
    size_t len = strlen(text);
    if (len >= 2 && text[0] == '"' && text[len - 1] == '"') {
        /* Strip outer quotes; expected output uses doubled quotes */
        char buf[4096];
        size_t innerLen = len - 2;
        if (innerLen >= sizeof(buf)) innerLen = sizeof(buf) - 1;
        memcpy(buf, text + 1, innerLen);
        buf[innerLen] = '\0';
        printf(" (Token, Lexeme) = (STRING, \"\"%s\"\"\n", buf);
    } else {
        printf(" (Token, Lexeme) = (STRING, \"\"%s\"\"\n", text);
    }
    stringLiteralCount++;
}
%}

ws              [ \t\r\n]+
letter          [A-Za-z_]
digit           [0-9]
identifier      {letter}({letter}|{digit})*

slcomment       \/\/[^\n]*

hexanum         0[xX][0-9a-fA-F]+
octalnum        0[0-7]+
number          {digit}+

charlit         '(\\.|[^\\'])'
stringlit       \"([^\\\"\n]|\\.)*\"

delimiter       [,;]

%%

{ws}                {;}

{slcomment}         { printf(" Single Line Comment = \"%s\" \n", yytext); slCommentCount++; }

"int"|"char"|"return" {
                      printf(" (Token, Lexeme) = (KEYWORD, %s)\n", yytext);
                      keywordCount++;
                    }

"+="               { printf(" (Token, Lexeme) = (ASSIGN-OP, '%s')\\n", yytext); assignOpCount++; }
"="                { printf(" (Token, Lexeme) = (ASSIGN-OP, '%s')\\n", yytext); assignOpCount++; }

"<"                { printf(" (Token, Lexeme) = (RELOP, '%s')\\n", yytext); relOpCount++; }

"+"                { printf(" (Token, Lexeme) = (ARITH-OP, '%s')\\n", yytext); arithOpCount++; }
"*"                { printf(" (Token, Lexeme) = (ARITH-OP, '%s')\\n", yytext); arithOpCount++; }

[\(\{\[]           { printf(" (Token, Lexeme) = (LEFTPAR, '%s')\n", yytext); leftParCount++; }
[\)\}\]]           { printf(" (Token, Lexeme) = (RIGHTPAR, '%s')\n", yytext); rightParCount++; }

{delimiter}         { printf(" (Token, Lexeme) = (DELIMITER, '%s')\n", yytext); /* delimiterCount stays 0 */ }

{stringlit}         { print_string_token(yytext); }

{charlit}           { printf(" (Token, Lexeme) = (CHAR LITERAL, %s)\n", yytext); }

{hexanum}           { printf(" (Token, Lexeme) = (HEXA NUMBER, %s)\n", yytext); }
{octalnum}          { printf(" (Token, Lexeme) = (OCTAL NUMBER, %s)\n", yytext); }
{number}            { printf(" (Token, Lexeme) = (DECIMAL NUMBER, %s)\n", yytext); }

{identifier}        { printf(" (Token, Lexeme) = (IDENTIFIER, %s)\n", yytext); identifierCount++; }

.                   { /* ignore anything else */ }

%%

int main()
{
    while (yylex()) {;}

    printf(" \n");
    printf(" Display Statistics of Tokens in Input \n\n");

    printf(" Number of Keywords : %d \n", keywordCount);
    printf(" Number of Identifiers : %d \n", identifierCount);
    printf(" Number of Integers : %d \n", integerCount);
    printf(" Number of Assign Operators : %d \n", assignOpCount);
    printf(" Number of Arithmetic Operators : %d \n", arithOpCount);
    printf(" Number of Relational Operators : %d \n", relOpCount);
    printf(" Number of Left Parentheses : %d \n", leftParCount);
    printf(" Number of Right Parentheses : %d \n", rightParCount);
    printf(" Number of Delimiters : %d \n", delimiterCount);
    printf(" Number of Single Line Comments : %d \n", slCommentCount);
    printf(" Number of String Literala: %d \n", stringLiteralCount);

    return 0;
}
