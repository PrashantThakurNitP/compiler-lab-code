
zero [0]
one [1]

%%
({zero}|{one})* printf("string matched");
.* printf("string did not matched");

%%
int main()
{yylex();
return 0;

}
int yywrap()
{
return 1;
}
