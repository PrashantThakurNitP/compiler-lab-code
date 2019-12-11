#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n;
void input_sep(vector<string> &s1,vector<string> &fp,vector<string> &ft)
{
 
	 cout<<"Enter terminal in capital letter   \n";
	for(int j=0;j<n;j++)
	{
		fflush(stdin);
		 string s2;
		 cin>>s2;
		
		 int init=3;//position in string
		 
		 //cout<<s2.size();
		 for(int i=3;i<s2.size();i++)
		 {
		 	
		 	string temp;
		 	//left hand side of production
		 	string temp3;//a single complete production
		 	
		 	if(i+1==s2.size()||s2[i+1]=='/')
		 	{
		 		
		 		//cout<<"inside if i= "<<i<<endl;
		 		string temp2=s2.substr(0,3);
		 		
		 		temp=s2.substr(init,i+1-init);
		 		
		 		temp3=temp2+temp;
		 		fp.push_back(temp3);
		 		
		 		init=i+2;
		 	   
		 		//cout<<"first part temp2= "<<temp2<<endl;
		 		//cout<<"second part temp= "<<temp<<endl;
		 		//cout<<"third part temp3= "<<temp3<<endl;
              

		 	}
		 	
		 }
		 
		 s1.push_back(s2);
		 ft[j].push_back(s2[0]);//contain left handside of every production
		// string temp5=" ---> ";
		 //ft[j]=ft[j]+temp5;
		// ft[j].push_back('-')
		 
	}
}

void first(vector<string> &fp,vector<string>&ft)
{
	 cout<<"inside input first\n";
	for(int i=0;i<fp.size();i++)
	{
		if(fp[i][3]<='z' && fp[i][3]>='a'||fp[i][3]=='{' )//reserve e for apsilon
		{
           
           //for(int u=2;u<ft)
			for(int k=0;k<n;k++)
			{
				if(ft[k][0]==fp[i][0])
				{
					//ft[k].push_back(' ');
					ft[k].push_back(fp[i][3]);//first of ft[j][0]
					cout<<"first of "<<ft[k][0]<<" is "<<fp[i][3]<<endl;

				}
			}
		}
		
	}
	for(int i=0;i<fp.size();i++)
	{

		if(fp[i][3]<='Z' && fp[i][3]>='A' && fp[i][3]!='e'&& fp[i][0]<='Z' && fp[i][0]>='A' )
		{
           

            for(int k=0;k<n;k++)
			{
				if(ft[k][0]==fp[i][3])//A->B then checking first of B; ft[k][0] is whose first is to be found
				{
					//ft[k].push_back(' ');
					string temp4=ft[k].substr(1,ft[k].size()-1);//taking first of B

					          for(int u=0;u<n;u++)
								{
										if(ft[u][0]==fp[i][0])
										{
										   //ft[k].push_back(' ');
											ft[u]=ft[u]+temp4;
										  //ft[u].push_back(fp[i][3]);//first of ft[j][0]
										     //cout<<"first of "<<ft[k][0]<<" is "<<fp[i][3]<<endl;

										}
								}

					//ft[k].push_back(fp[i][3]);//first of ft[j][0]
					//cout<<"first of "<<ft[k][0]<<" is "<<fp[i][3]<<endl;

				}
			}
		}

	}

}

void dis_p(vector<string> &s1,vector<string> &fp,int n)
{
	cout<<"inside disp production\n";
	for(int i=0;i<fp.size();i++)
		cout<<fp[i]<<endl;
}
int main()
{
	
	cout<<"Enter no of string";
	
	cin>>n;
    vector<string> s1;//original
	vector<string> fp;//original separarted productions
	vector<string> ft(n);//contain first with ft[i][0] contain whose first is to be calculated
   input_sep(s1,fp,ft);
   cout<<"before display";
   dis_p(s1,fp,n);
	first(fp,ft);
	cout<<"First is as below"<<endl;
	for(int i=0;i<ft.size();i++)
	{
	   for(int j=0;j<ft[i].size();j++)
	   {

	   	         if(j==1)
		         cout<<"{ "<<ft[i][j]<<" , ";
		         else if(j==0)
		         	cout<<ft[i][j]<<" = ";
	             else if(j==ft[i].size()-1)
	             	cout<<ft[i][j]<<" } ";
	             else
	             	cout<<ft[i][j]<<" , ";
	   }
	   cout<<endl;
	   	

	}
	
}
