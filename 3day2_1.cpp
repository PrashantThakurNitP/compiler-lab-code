#include<iostream>
using namespace std;
int main()
{
	string s1;
	getline(cin,s1);
	cout<<"string is "<<s1<<endl;
	int state =1;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]=='0'||s1[i]=='1')
          state=1;
        else 
        	state=2;
	}
	if(state==1)
	cout<<"valid input"<<endl;
	else
	cout<<" not valid input"<<endl;
	
}
