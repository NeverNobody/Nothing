%{
#include <stdio.h>
int count = 0;
%}

%option noyywrap

%%
a       { count++; }
[^\n]   { }
\n      { return 0; }
%%

int main() {
    printf("Enter the string:\n");
    yylex();
    printf("Number of a's = %d\n", count);
    return 0;
}
