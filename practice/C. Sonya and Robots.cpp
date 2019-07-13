#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	unordered_map<ll,ll> b,count;
	ll unique=0;
	ll ans=0;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
		count[a[i]]++;
		if(b[a[i]]==0)
		{
			b[a[i]]=1;
			unique++;
		}
	}
	for(ll i=0;i<n;++i)
	{
		count[a[i]]--;
		if(count[a[i]]==0)
			unique--;
		if(b[a[i]]==1)
		{
			b[a[i]]=0;
			ans+=unique;
		}
	}
	cout<<ans;
}