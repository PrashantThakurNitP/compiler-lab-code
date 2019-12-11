a [a]
b [b]
c [c]
d [d]
f [f]
e [e]
%%
((a{b}*c)|(def)+|({a}*{d}+e))+ printf("string matched\n");
.* printf("string not matched\n");
%%
int main()
{
yylex();//main entry point for lex program
return 0;
}
int yywrap()//input is exhausted ie end of file
{
return 1;
}
//output
//lex 7third.l
//cc lex.yy.c -lfl//source code is written to output file called lex.yy.c  it contain defination to yylex()
//./a.out
//cc -ll used to acess library