#include<iostream>
#include<string>

using namespace std;
int main()
{
	string s1;
	getline(cin,s1);
	cout<<"The string is "<<s1<<endl;
	
	int state=1;
	if(state==1)
	{
	   if(s1[0]=='i')//ie check for int
	   		state=2;
	   else if(s1[0]=='f')//check for float
	   		state=3;
	   else if(s1[0]=='c')//check for char
	   		state=4;
	   else 
			state=24;//dump state
	}
	if(state==2)//int
	{
		if(s1[1]=='n'&&s1[2]=='t'&&s1[3]==' ')
		state=12;//variable type is int is conformed
		
		else 
		state=24;//dump state
	//	cout<<" at s1 state is "<<state<<endl;
	}
		else if(state==3)//float
	{
		if(s1[1]=='l'&&s1[2]=='o'&&s1[3]=='a'&&s1[4]=='t'&&s1[5]==' ')
		state=13;//variable type is float is confirmed
		else 
		state=24;//dump state
		//	cout<<" at s1 state is "<<state<<endl;
	}
			else if(state==4)//char
	{
		if(s1[1]=='h'&&s1[2]=='a'&&s1[3]=='r'&&s1[4]==' ')
		state=14;//variable type is char is confirmed
		else 
		state=24;//dump state
			cout<<"state is "<<state<<endl;
	}
//upto variable and space done	
		cout<<"state is "<<state<<endl;
 int pos=0;
 if(state==12)
 			pos=4;//int , ie search for variable name from pos 4
  if(state==13)
 			pos=6;//float
	 if(state==14)
 			pos=5;//char	 
		if(state==12||state==13||state==14)
		state=15;//go to a common state after knowing where
	//to start searching next character for variable name
	int i=0;	
if(state==15)
while(state==15)
{
//	cout<<"at pos s is "<<s1[pos]<<endl;
					 //for int

			if(s1[pos]=='_'||(s1[pos]>='a'&&s1[pos]<='z')||(s1[pos]>='A'&&s1[pos]<='Z'))
			{
			state=22;//first letter of variable
			//cout<<"hello first match"<<endl;
			}
		 	else
		 	state=24;//dump state
	//cout<<"state "<<state<<endl<<"pos = "<<pos<<endl;
  if(state==22)
  for( i=1;i<s1.size();i++)//other letter of variable name
  {
  	//	cout<<" at for loop start pos= "<<pos<<"s is "<<s1[pos+i]<<" i = " <<i<<" state is "<<state<<endl;

		if((s1[pos+i]>='a'&&s1[pos+i]<='z')||(s1[pos+i]>='A'&&s1[pos+i]<='Z')||s1[pos+i]>='0'&&s1[pos+i]<='9')
		state=23;//final
		
		else if(s1[pos+i]==',')//come out and again verify next variable
		{
		 state=15;//again iterate for variable name
		// cout<<"state is "<<state<<endl;
		 break;
		
		}
		else if (s1[pos+i]==';')
		{
			state=50;//final state ie strig end
			break;
		}
		else
		{
			state=24;
		//	cout<<"inside else of for llop"<<endl;
			break;
			
		}
	//	cout<<" at for loop end pos= "<<pos<<"s is "<<s1[pos+i]<<" i = " <<i<<" state is "<<state<<endl;

  }//for loop end
  	if(state==50||pos+i>=s1.size())//length of string over
  	{
  		
  		
  		break;
	  }
	
pos=pos+i+1;//pos+i is current location we at as i due to inner for loop
//hence to increment we do pos+i+1
//cout<<" at while loop end pos= "<<pos<<"s is "<<s1[pos+i]<<" i = " <<i<<" state is "<<state<<endl;

}//while loop end
  if(state==50)
  cout<<"valid variable name, final state reached , state = "<<state;
   else
  cout<<" Invalid variable name, final state NOT reached ,state =  "<<state;
  return 0;
	
}
