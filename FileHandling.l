%option noyywrap
%{
#include <stdio.h>
%}

%%
[A-Za-z0-9_]+    { printf("%s\n", yytext); }
.|\n             ;
%%

int main() {
    freopen("input.txt", "r", stdin);
    yylex();
    return 0;
}
