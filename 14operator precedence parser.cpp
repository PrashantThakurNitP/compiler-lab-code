#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//two or more language accept same operator precedenc
//hence it accept i++
int top(char c)
{
  if(c=='+')
  	return 0;
  else if(c=='-')
  	return 1;
  else if(c=='*')
  	return 2;
  else if(c=='i')
  	return 3;
  else if(c=='$')
  	return 4;
  else 
  {
  	cout<<"ERROR IN top fn";
  	return -1;
  }
  	
  
  };
  
 int main()
 {
 	char a[5][5]={
  	{'>','>','<','<','>'},
  	{'>','>','<','<','>'},
  	{'>','>','>','<','>'},
  	{'>','>','>','-','>'},
  	{'<','<','<','<','-'},
  };
 	vector<char> stk;
 	stk.push_back('$');
 	cout<<"Enter string    ";
 	string inp;
 	cin>>inp;
 	inp.push_back('$');
 	for(int i=0;i<inp.size();)
 	{
 		char tp=*(stk.end()-1);
 		char ip=inp[i];
 		cout<<" stack top is "<<tp<<" input is "<<ip<<endl;

 		if(tp=='$'&&ip=='$')
 		{
 			cout<<"Accepted"<<endl;
 			break;
 		}
 		else if(a[top(ip)][top(tp)]=='>')//input precedence is more hence push
 		{
             stk.push_back(inp[i]);
             i++;
 		}
 		else if(a[top(ip)][top(tp)]=='<')//input precedence is less than stack hence pop
 		{
 			stk.pop_back();
 			
 		}
 		else if(a[top(ip)][top(tp)]=='-')//error canot compare
 		{
 			cout<<"ERROR in productin"<<endl;
 			break;
 		}
 	}

 }
