#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n;
void input_sep(vector<string> &s1,vector<string> &fp,vector<string> &ft,vector<string> &fl)
{
 
	 cout<<"Enter terminal in capital letter   \n";
	for(int j=0;j<n;j++)
	{
		fflush(stdin);
		 string s2;
		 cin>>s2;
		 int init=3;//position in string
		 for(int i=3;i<s2.size();i++)
		 {
		 	string temp;
		 	//left hand side of production
		 	string temp3;//a single complete production
		 	
		 	if(i+1==s2.size()||s2[i+1]=='/')
		 	{
		 		string temp2=s2.substr(0,3);
		 		temp=s2.substr(init,i+1-init);
		 		temp3=temp2+temp;
		 		fp.push_back(temp3);
		 		init=i+2;
		 	}
		 	
		 }
		 
		 s1.push_back(s2);
		 ft[j].push_back(s2[0]);//contain left handside of every production vector for first
		 fl[j].push_back(s2[0]);//contain left handside of every production vector for follow
		
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
					
					ft[k].push_back(fp[i][3]);//first of ft[j][0]
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
					string temp4=ft[k].substr(1,ft[k].size()-1);//taking first of B

					          for(int u=0;u<n;u++)
								{
										if(ft[u][0]==fp[i][0])
										{
										   //ft[k].push_back(' ');
											ft[u]=ft[u]+temp4;
										}
								}	
				}
			}
		}
	}
}
void follow(vector<string> &fp,vector<string>&ft,vector<string>&fl)
{
   for(int i=0;i<fp.size();i++)//production
   {
   	 for(int j=0;j<fp[i].size();j++)//production string
   	 {
          if(/*fp[i][j-1]<='Z'&&fp[i][j-1]>='A'&&(*/fp[i][j]<='z' &&fp[i][j]>='a'||fp[i][j]=='{')//)
          	for(int k=0;k<n;k++)//finding where to append
          	{
          		if(k==0)
          			 fl[k].push_back('$');
          		if(fl[k][0]==fp[i][j-1])
          			 fl[k].push_back(fp[i][j]);//ie terminal fp[i][j] follow fp[i][j-1] then terminal is follow of  fp[i][j-1]
          	}
   	 }
   }
   for(int i=0;i<fp.size();i++)
   {
   	 for(int j=0;j<fp[i].size();j++)
   	 {
          if(fp[i][j-1]<='Z'&&fp[i][j-1]>='A'&&(fp[i][j]<='Z' &&fp[i][j]>='A'))
          	for(int k=0;k<ft.size();k++)//finding first of ft[k][0]
          	{
          		if(ft[k][0]==fp[i][j])
          		{//temp contain first of ft[k][0]
          			string temp=ft[k].substr(1,ft[k].size()-1);//find first of non terminal occuring to right of non terminal
          			for (int u= 0; u< fl.size(); ++u)
          			{
          				if(fl[u][0]==fp[i][j-1])
          					fl[u]=fl[u]+temp;//append follow found to already existing terminal
          			}
          			//fl[k].push_back(fp[i][j])//ie terminal fp[i][j] follow fp[i][j-1]
          		}
          	}
   	 }
   }
 for(int v=0;v<n;v++)
   for(int i=0;i<fp.size();i++)
   { // suppose A->aB is production *fp[i].end() is A and *fp[i].end() is B
   	//cout<<"fp end = "<<*(fp[i].end()-1)<<" fp start = "<<*fp[i].begin()<<endl;
   	 if(*(fp[i].end()-1)<='Z' && *(fp[i].end()-1)>='A'&&*fp[i].begin()<='Z' && *fp[i].begin()>='A')
   	 { 
   	 	
   	 	for(int u=0;u<fl.size();u++)
   	 	{   if(fl[u][0]==*fp[i].begin())
   	 		{
   	 		    string temp = fl[u].substr(1,fl[u].size()-1);//finding follow of A
   	 		
   	 		    for (int k = 0; k < fl.size(); ++k)
   	 		   {
   	 			 if(fl[k][0]==*(fp[i].end()-1))
   	 				fl[k]=fl[k]+temp;//subsiting follow of A to follow of B
   	 		   }
   	 	   } 
   	 	}
   	 }

   }

}
void print_first_follow(vector<string> &ft)
{
	for(int i=0;i<ft.size();i++)
	{
		sort(ft[i].begin()+1,ft[i].end());
		auto res=unique(ft[i].begin(),ft[i].end());
		ft[i]=string(ft[i].begin(),res);
	}
	for(int i=0;i<ft.size();i++)
	{
	   for(int j=0;j<ft[i].size();j++)
	   {        
	   	           if(j==1)
		                cout<<" { ";
		           cout<<ft[i][j];
	               if(j!=0 && j!=ft[i].size()-1)
	             		cout<<" , ";
	               if(j==0)
		                cout<<" = ";
		           if(j==ft[i].size()-1)
	                    cout<<" } ";
	   }
	   cout<<endl;
	   	

	}
}



void dis_p(vector<string> &s1,vector<string> &fp,int n)
{
	cout<<"{ is epsilon production\n";
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
	vector<string> fl(n);
    input_sep(s1,fp,ft,fl);
    dis_p(s1,fp,n);
	first(fp,ft);
	follow(fp,ft,fl);
	cout<<"First is as below"<<endl;
	print_first_follow(ft);
	cout<<"follow is as below"<<endl;
	print_first_follow(fl);
	
	
}
