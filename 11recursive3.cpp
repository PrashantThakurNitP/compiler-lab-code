#include<iostream>
#include<string>
using namespace std;
int index1;
int E( char* s1)
{
   int a;
   if(s1[index1]=='e')
      return 1;
    else if(s1[index1]=='i')
       {
          index1++;
          a=E(s1);
          return a;         
       }
       else if(s1[index1]=='\0')
       return 1;
      else 
      {
      cout<<s1[index1];
       cout<<"\t error/n";
        return 0;
        }         
}
int main()
{
char s1[10];
cout<<"     Enter the string\t";
 cin>>s1;
index1++;
cout<<"\t";
for(int i=0;s1[i]!='\0';i++)
cout<<s1[i];
cout<<endl;
if(s1[0]=='+')
{
  int a=E(s1);
  if(a==1)
    cout<<"    accepted";
    else if (a==0)
    cout<<"    not accepted\n";
    else
    cout<<"    Error/n";
}
       else
     cout<<"    not valid\n";
}
