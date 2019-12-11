digit [0-9]
E [E]
letter [a-zA-Z]
_ [_]


%%

({digit}+(.{digit}+)?((E(\+|\-))?{digit}+)?) printf(" Valid number\n ");
int|char|float|if|while|bool|double|for|return|switch|void|sizeof|goto|struct|union|continue|break|else|if|auto printf("valid keyword");
(_|{letter})(({letter}|{digit})*) printf("valid identifier");


.* printf("not valid number \n");
%%
int main()
{
yylex();
return 0;
}
int yywrap()
{
return 1;
}
