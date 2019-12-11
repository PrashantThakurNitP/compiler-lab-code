//MINIMIZATION OF DFA
//WAP IN C++ TO MINIMIZE A DFA(INPUT TAKEN IN TABLE)
//PRASHANT THAKUR
//1706001
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int conv(char a )
{
	if(a=='A')
	  return 0;
	else if(a=='B')
	 return 1;
	 else if(a=='C')
	 return 2;
	 else if(a=='D')
	 return 3;
	 else if(a=='E')
	 return 4;
	 else if(a=='F')
	 return 5;
};
char back(int a )
{
	if(a==0)
	  return 'A';
	else if(a==1)
	 return 'B';
	 else if(a==2)
	 return 'C';
	 else if(a==3)
	 return 'D';
	 else if(a==4)
	 return 'E';
	 else if(a==5)
	 return 'F';
};
int main()
{

cout<<"Minimization of DFA 1706001"<<endl;
cout<<"Taking input from table stored "<<endl;
char dfa[6][2]={//store dfa
	{'B','C'},{'A','D'},{'E','F'},{'E','F'},{'E','F'},{'F','F'}
};
bool state[6][6]={//mark all state where one state is initial and one state is final
	
	{0,0,1,1,1,0}, {0,0,1,1,1,0}, {1,1,0,0,0,1}, {1,1,0,0,0,1}, {1,1,0,0,0,1}, {0,0,1,1,1,0},
	

};
cout<<"DFA table for given state and input is "<<endl;
  cout<<" ";
    for(int i=0;i<2;i++)
       cout<<" "<<i;
       cout<<endl;
	for(int i=0;i<6;i++)
	{  cout<<back(i)<<"|";
		for(int j=0;j<2;j++)
		{ cout<<back(dfa[i][j])<<" ";
		}
		cout<<endl;
    }
cout<<"Input table contain 1 if one state is final and another state is non-final"<<endl;
   //printing table
     cout<<" ";
    for(int i=0;i<6;i++)
       cout<<" "<<back(i);
       cout<<endl;
	for(int i=0;i<6;i++)
	{  cout<<back(i)<<" ";
		for(int j=0;j<6;j++)
		{ cout<<state[i][j]<<" ";
		}
		cout<<endl;
    }
for(int u=0;u<6;u++)
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(state[i][j]==0)
			{
				//for input 0
				char state1=dfa[i][0];//dfa[1][0] means dfa(B,0) output, let it be F
				char state2=dfa[j][0];//dfa[2][0] means dfa(C,0) output, let it be E
			//	cout<<" i,j "<<i<<" "<<j<<endl;
				
				int back1=conv(state1);//get index for state ie 5 for F
				int back2=conv(state2);//get index for state ie 4 for E
				
				if(state[back1][back2]==1)//if state[5][4]==1 mark state[i][j]=1
		   	
				 
				   { //cout<<i<<" "<<j<<endl; 
				   state[i][j]=1;  state[j][i]=1;// update state[i][j]=1 state[j][i]=1 
					   }	
				//doing same for input 1	   
			    char state3=dfa[i][1];//dfa[1][0] means dfa(B,1) output, let it be F
				char state4=dfa[j][1];//dfa[2][0] means dfa(C,1) output, let it be E
				int back3=conv(state3);//get index for state ie 5 for F
				int back4=conv(state4);//get index for state ie 4 for E
				
				if(state[back3][back4]==1)//if state[5][4]==1 mark state[i][j]=1
		   	
				 
				   { // cout<<i<<" "<<j<<endl; 
				   state[i][j]=1;  state[j][i]=1;// update state[i][j]=1 state[j][i]=1 
					   }			   
					  
			}
		}
	}
}

//printing output table table
//state which have 0 as input need to be merged
cout<<"Output table after minimization"<<endl;
     cout<<" ";
    for(int i=0;i<6;i++)
       cout<<" "<<back(i);
       cout<<endl;
	for(int i=0;i<6;i++)
	{  cout<<back(i)<<" ";
		for(int j=0;j<6;j++)
		{ cout<<state[i][j]<<" ";
		}
		cout<<endl;
    }
    cout<<"Merge those state whose row and colomn intersection contain 0"<<endl;
    cout<<"We will do  following for minimization "<<endl;
    	for(int i=0;i<6;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(state[i][j]==0)
			 cout<<"Merge state "<<back(i)<<" and "<<back(j)<<endl;
		}
	}
   

}
