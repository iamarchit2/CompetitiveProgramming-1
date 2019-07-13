#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 

int main()
{
	ull t;
	cin>>t;
	while(t--)
	{
		ull n,m,flag=0;
		cin>>n>>m;
		vector<string> a(n);
		for(ull i=0;i<n;++i)
		{
			cin>>a[i];
		}
	
		ull ctr=0;
		for(ull i=0;i<n-1;++i)
		{
			for(ull j=0;j<a[i].size();++j)
			{
				for(ull k=0;k<a[i+1].size();++k)
				{
					if(a[i][j]==a[i+1][k])
					{
						ctr++;
						flag=1;
						break;
					}
				}
				if(flag==1)
					break;
			}
		}
		cout<<ctr<<endl;
		if(ctr<=m)
		{
			cout<<"Welcome to a world without rules"<<endl;
		}
		else
		{
			cout<<"Very poor choice of words"<<endl;
		}

	}
}