#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
	ll t;cin>>t;
	ll ctr=1;
	while(t--)
	{
		ll n,ctr1=0,ctr2=0;
		cin>>n;
		string x=to_string(n);
		x='0'+x;
		string y=x,z=x;
		for(int i=0;i<x.size();++i)
		{
			if(x[i]%2==1)
			{
				y[i]--;z[i]++;int k=i;
				while(z[k]==':')
				{
					z[k]='0';
					k--;
					z[k]+=2;
				}
				for(int j=i+1;j<x.size();++j)
				{
					y[j]='8';
					z[j]='0';
				}
				break;
			}	
		}
		ll a=stoi(x);
		ll b=stoi(y);		
		ll c=stoi(z);
		ctr1=a-b;
		ctr2=c-a;
		cout<<"Case #"<<ctr<<": "<<min(ctr1,ctr2)<<endl;
		ctr++;
	}
} 