//******** 3_adress_mode***********************//
//**********1706001****************************//
//******PRASHANT THAKUR************************//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int top(char c)//for comparing precedence of operator
{
  if(c=='+')
  	return 1;
  else if(c=='-')
  	return 1;
  else if(c=='*')
  	return 2;
  else if(c=='/')
  	return 2;
  else if(c=='$')
  	return 0;
  else 
  {
  	return -1;//if character ie operand
  }
  	
  
  };
  
int main()
{
   vector<char>operand;
   operand.push_back('$');
   vector<char>optr;
   optr.push_back('$');
   int index=0;
   char t='t';
   cout<<"Enter the  RHS of expression y = "<<endl;
   string input;
   getline(cin,input);
 cout<<"OUTPUT IS "<<endl;
  int pos1=0;//operand
  int pos2=0;//operator
  input.push_back('$');
   for(int i=0;i<input.size()+2;)
   {
 
    if(top(input[i])==-1)
   	 {
   	 	//it is operand;
   	 	operand.push_back(input[i]);
   	 	pos1++;
   	 	i++;
		}

	else//it is operator
	{
			if(top(input[i]) >top(optr[pos2]) )//input has higher precedence then push input into stack
			{
			//	cout<<"input has higher precedence "<<endl;
				optr.push_back(input[i]);
				pos2++;
				i++;
			}
			else//pop top two input from stack
			{
			
				char a1=operand[pos1];
				operand.pop_back();
				pos1--;
				char a2=operand[pos1];
				operand.pop_back();
				pos1--;
			
				int b2;
				if(optr[pos2]=='+')
				{ 
                  cout<<"\t";
				   cout<<char(t+index)<<"= "<<a2<<" + "<<a1<<endl;
				}
				else if(optr[pos2]=='-')
				{
					 cout<<"\t";  cout<<char(t+index)<<"= "<<a2<<" - "<<a1<<endl;
				}
			    else if(optr[pos2]=='*')
				{
				      cout<<"\t";	 cout<<char(t+index)<<"= "<<a2<<" * "<<a1<<endl;
				}
				else if(optr[pos2]=='/')
				{
					   cout<<"\t"; cout<<char(t+index )<<" = "<<a2<<" / "<<a1<<endl;
				}
				optr.pop_back();//top of operator is pooped
				pos2--;
		
				operand.push_back(char(t+index));
				pos1++;
			
			index++;//	next new variable will be used starting from t like t,u,v,w
			}
		}
	}	
cout<<"\t y = "<<char(t+index-2)<<endl;
}
