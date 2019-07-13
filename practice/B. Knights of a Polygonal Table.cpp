#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n,k;
	cin>>n>>k;
	vector<ll> ans(n);
	vector<pair<pair<ll,ll>,ll> > a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].f.f;
		a[i].s=i;
	}
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].f.s;
	}
	sort(a.begin(),a.end());
	ans[a[0].s]=a[0].f.s;
	ll i;
	multiset<ll> z;
	z.insert(a[0].f.s);
	for( i=1;i<=k && i<n;++i)
	{
		ans[a[i].s]=ans[a[i-1].s]+a[i].f.s;
		z.insert(a[i].f.s);
	}
	while(i<n)
	{
		ans[a[i].s]=ans[a[i-1].s]+a[i].f.s-*(z.begin());
		z.erase(z.begin());
		z.insert(a[i].f.s);
		i++;
	}
	for(ll i=0;i<n;++i)
	{
		cout<<ans[i]<<" ";
	}
}