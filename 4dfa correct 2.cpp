#include<iostream>
#include<string>
using namespace std;
int main()
{
	
   
int repeat=1;
char r1;
do{
   
  
   int state=1;
   fflush(stdin);
   string s;
   getline(cin,s);
   //int state=1;
   for(int i=0;i<s.size();i++)
   {
   	cout<<"state is"<<state<<" s is "<<s[i]<<endl;
   	if(state==1&&s[i]=='a')
   	   state=2;
      else if(state==1&&s[i]=='d')
         state=7;
   		else if(state==1&&s[i]=='a')
   	  state=4;
   	  	else if(state==2&&s[i]=='a')
   	  state=3;
   	  else if(state==2&&s[i]=='b')
   	  state=2;
   	  	else if(state==2&&s[i]=='c')
   	  state=4;
   	  else if(state==2 &&s[i]=='d')
   	  state=5;
   	   else if(state==3&&s[i]=='a')
   	  state=3;
   	   else if(state==3 &&s[i]=='d')
   	  state=5;
   	  //
   	   else if(state==4&&s[i]=='a')
   	  state=2;
   	  // else if(state==4&&s[i]=='d')
   	  //state=2;
   	   else if(state==4&&s[i]=='d')
   	  state=7;
   	   else if(state==5&&s[i]=='d')
   	  state=5;
   	   else if(state==5&&s[i]=='e')
   	  state=6;
   	   else if(state==6&&s[i]=='a')
   	  state=2;
   	   else if(state==6&&s[i]=='d')
   	  state=7;

      else if(state==7&&s[i]=='d')
        state=5;
     else if(state==7&&s[i]=='e')
        state=8;
     else if(state==8&&s[i]=='a')
        state=2;
     else if(state==8&&s[i]=='f')
        state=9;

     else if(state==9&&s[i]=='a')
        state=2;
     else if(state==9&&s[i]=='d')
        state=7;
     //else if(state==8&&s[i]=='f')
      //  state=9;
   	  
   	  else
   	   state=10;
   	
      }//for ends
      if(state==4||state==6||state==8||state==9)
         cout<<"accepted"<<endl;
      else 
         cout<<"not accepted"<<endl;

      cout<<"enter y to repeat else n"<<endl;
        fflush(stdin);
      cin>>r1;
      if(r1=='Y'||r1=='y')
         repeat=1;
      else
         repeat=0;
    
 string t;
   getline(cin,t);//useless
	}while(repeat);
	//if(state==3||state==5||state==6)
	////cout<<"accepted"<<endl;
	//else
	//cout<<"not accepted"<<endl;
}
