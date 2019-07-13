#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int main()
{
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n),b(m),c;
	unordered_map<ll,ll> u;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for(ll j=0;j<m;++j)
	{
		cin>>b[j];
		u[b[j]]=1;
	}
	for(ll i=0;i<n;++i)
	{
		if(u[a[i]]==1)
		{
			cout<<a[i]<<" ";
		}
	}
}