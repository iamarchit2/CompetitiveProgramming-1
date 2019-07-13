#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		string a;
		cin>>a;
		ll temp=1;
		for(ll i=0;i<n/2;++i)
		{
			char x,y,p,q;
			x=a[i]-1,y=a[i]+1,p=a[n-1-i]-1,q=a[n-1-i]+1;
			if(a[i]=='a')
			{
				x=y='b';
			}
			if(a[n-1-i]=='a')
			{
				p=q='b';
			}
			if(a[i]=='z')
			{
				x=y='y';
			}
			if(a[n-1-i]=='z')
			{
				p=q='y';
			}
			if(x==p || x==q || y==p || y==q)
			{
				continue;
			}
			else
			{
				temp=0;
				break;
			}
		}
		if(temp)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}