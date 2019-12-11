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
		if(s1[i]=='a'||s1[i]=='b'||s1[i]=='c'||s1[i]=='d')
          state=1;
      else
      {
      	state=2;
      	break;
      }
      	

	}
	if(state==1)
	cout<<"valid input"<<endl;
	else
	cout<<" not valid input"<<endl;
	
}
