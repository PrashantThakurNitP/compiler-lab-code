a [a]
b [b]
c [c]
d [d]
%%
((a|b)*(c|d)*)+|a{b}*{c}*d printf("string matched\n");
.* printf("string not matched\n");
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
