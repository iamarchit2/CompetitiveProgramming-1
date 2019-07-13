#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll t;
	cin>>t;
	vector<ll> v;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> a(n+1);
		for(ll i=0;i<n+1;++i)
		{
			cin>>a[i];
		}
		ll ans=n;
		for(ll i=1;i<n;)
		{
			if(a[i]+i+1==0)
			{
				ans=n-(i+1);
				i+=2;
			}
			else
			{
				i++;
			}
		}
		if(ans%2==0)
		{
			v.push_back(0);
		}
		else
		{
			v.push_back(1);
		}
	}
	for(ll i=0;i<v.size();++i)
	{
		cout<<"Case #"<<i+1<<": "<<v[i]<<endl;
		if(v[i]==1)
		{
			cout<<"0.0"<<endl;
		}
	}
}