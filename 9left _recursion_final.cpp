#include<iostream>
#include<string>
using namespace std;
int main()
{
	//A->Aa1|Aa2|Aa3|b1|b2|b3
	//then
	//A->b1 X|b2 X|b3 X
	//X->epsilon|a1 X|a2 X|a3 X 
	string s1;
	cout<<"Enter a production in single line separated by | ";
	getline(cin,s1);

	char start=s1[0];
	string s2;
	s2.push_back(start);
	s2.push_back('-');
	s2.push_back('>');
	string s3;
	s3.push_back('X');

   s3.push_back(' ');
   s3.push_back('-');

   s3.push_back('>');
   int flag=-1;
   bool flag1=0;//denote atleast on production pushed in s3 hence push | before pushing another
   bool flag2=0;//if already a production pushed  in s2 then put | befor next push
   for(int i=3;i<s1.size();)
   {
  	 if(!flag1 && !flag2 && s1[i]=='|')//in starting | comes like A->| then error
      cout<<"invalid productions";
  		else if(s1[i]==start && s1[i+1]=='|')
		{
			i++;
			flag=2;//A->A|..... type , we just neglect it 
		}
	 	else if(s1[i]==start && s1[i+1]!='|'&& i<s1.size())//left recursive part
		{
			if(flag1==1)
			s3.push_back('|');//already a production pushed in s3
			while(s1[i+1]!='|' && i<s1.size())//in A->Aa1, here a1 can be many chracter hence push it all part ofa1
			{
				i++;
				s3.push_back(s1[i]);
			}
			s3.push_back('X');
			if(i<s1.size())
				i++;
			flag1=1;//atlest one production pushed in s3
		}
		else if(s1[i]=='|')
		{
			i++;//first increment for |
			if(flag==2)//if A->A production comes then neglect it
				i++; //second increment for A
		}
	else if(s1[i]!=start && s1[i]!='|')//no left recursive part like A->b1|b2
	{
		if(flag2==1)//if already production has came before
			s2.push_back('|');
		while(s1[i]!='|' && i<s1.size())//push all part of b1 if b1 is of multi character
		{
			s2.push_back(s1[i]);
			i++;
		}
		s2.push_back('X');
		if(i<s1.size())
			i++;
		flag2=1;//atlest on production pushed in s2
	}



   }
   s2.push_back('\0');
   s3.push_back('\0');
   if(flag2&&flag1)
   {
   		cout<<"after removal of left recursion production is \n "<<s2<<endl;
   		cout<<s3<<"|epsilon";
   	}
   	else
   	{
   		cout<<"No left recursion or cannot be removed";
   	}



}

