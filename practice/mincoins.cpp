#include<bits/stdc++.h>
using namespace std;
#define ll long long
int flag=0;
ll count(ll v,vector<ll> &c)
{
	
	if(v==0)
	{
		flag=1;
		return 0;
	}
	ll res=100000;
	for(int i=0;i<c.size();++i)
	{
		if(c[i]<=v)
		{
			res=min(res,1+count(v-c[i],c));
		}
	}
	if(flag==1)
		return res;
	else 
		return -1;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,v;
		cin>>v>>n;
		vector<ll> c(n);
		for(ll i=0;i<n;++i)
		{
			cin>>c[i];
		}
		ll ctr=count(v,c);
		cout<<ctr<<endl;
	}
}