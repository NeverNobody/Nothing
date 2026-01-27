%{
#include <stdio.h>
int aa = 0, ab = 0, nota = 0;
%}

%option noyywrap

%%
"aa"        { aa++; }
"ab"        { ab++; }
"a"         { }
[^a\n]      { nota++; }
\n          { return 0; }
%%

int main() {
    printf("Enter the string:\n");
    yylex();
    printf("aa count = %d\n", aa);
    printf("ab count = %d\n", ab);
    printf("not having 'a' chars = %d\n", nota);
    return 0;
}
