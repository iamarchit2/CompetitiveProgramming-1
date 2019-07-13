#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	char c[21];
	vector<int> a(10),b(10);
	
	while(cin.getline(c,21))
	{
		
        
		int k=0;
		for(int i=0;i<20;++i)
		{
			a[k]=c[i]-48;
			b[k]=c[++i]-48;
			k++;
		}
		int x,y;
		int flaga=0,flagb=0,flag=0;
		x=count(a.begin(),a.begin()+5,1);
		y=count(b.begin(),b.begin()+5,1);
		//cout<<x<<" "<<y<<endl;
		
	    if(x>y)
		{

			flaga=flagb=flag=0;
			cout<<"TEAM-A ";
			for(int i=0;i<5;++i)
			{
				if(a[i]==1)
					flaga++;
				if(5-i+flagb-flaga<0)
				{
					cout<<2*i+1<<endl;
					flag=1;
					break;
				}
				if(b[i]==1)
					flagb++;
				if(4-i+flagb-flaga<0)
				{
					cout<<2*i+2<<endl;
					flag=1;
					break;
				}
			}
		}
		else if(x<y)
		{
			flaga=flagb=flag=0;
			cout<<"TEAM-B ";
			for(int i=0;i<5;++i)
			{
				if(a[i]==1)
					flaga++;
				if(4-i+flaga-flagb<0)
				{
					cout<<2*i+1<<endl;
					flag=1;
					break;
				}
				if(b[i]==1)
					flagb++;
				if(4-i+flaga-flagb<0)
				{
					cout<<2*i+2<<endl;
					flag=1;
					break;
				}
			}
		}
		else if(x==y)
		{
			

			for(int i=5;i<10;++i)
			{
				flaga=flagb=0;
				if(a[i]==1)
					flaga=1;
				if(b[i]==1)
					flagb=1;
				if(flaga==1 && flagb==0)
					{ 
						cout<<"TEAM-A "<<2+2*i<<endl;
						flag=1;
				        break;
                    }
				else if(flaga==0 && flagb==1)
					{
						cout<<"TEAM-B "<<2+2*i<<endl;
						flag=1;
						break;
					}
			}
			if(flag==0)
				cout<<"TIE"<<endl;
		}
	}
}