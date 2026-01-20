%option noyywrap
%{
#include <stdio.h>
long long v = 0, c = 0;
%}

%%
[AEIOUaeiou]     { v++; }
[A-Za-z]         { c++; }
\n               { return 0; }
.                ;
%%

int main() {
    printf("Enter the statement:\n");
    yylex();
    printf("Vowels = %lld\n", v);
    printf("Consonants = %lld\n", c);
    return 0;
}
