#include<iostream>
#include<string>

using namespace std;
int main()
{
	string s1;
	getline(cin,s1);
	cout<<"The string is "<<s1<<endl;
	int state=1;//intial state
	if(state==1)
	{
			if(s1[0]=='_'||(s1[0]>='a'&&s1[0]<='z')||(s1[0]>='A'&&s1[0]<='Z'))
			{
			    state=2;//go to next state
			}
		 	else
		 		state=4;//dump state
	}
  if(state==2)
  for(int i=1;i<s1.size();i++)
  {
		if((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z')||s1[i]>='0'&&s1[i]<='9')
		state=3;//final till condition satisfy remain at state 3
		else
		{
			state=4;
			break;
		}
  }
  if(state==3||state==2)
  cout<<"valid variable name, final state reached state = "<<state;
   else
  cout<<" Invalid  variable name, final state NOT reached state =  "<<state;
  return 0;
	
}
