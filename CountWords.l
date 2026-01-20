%option noyywrap
%{
#include <stdio.h>
long long words = 0;
%}

%%
[A-Za-z0-9_]+    { words++; }
\n               { return 0; }
[ \t]+           ;
.                ;
%%

int main() {
    printf("Enter the statement:\n");
    yylex();
    printf("Number of words = %lld\n", words);
    return 0;
}
