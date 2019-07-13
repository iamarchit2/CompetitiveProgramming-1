#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n,m;
	cin>>n>>m;
	vector<ll> a(m);
	for(ll i=0;i<m;++i)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	ll ans=LLONG_MAX;
	for(ll i=0,j=n-1;j<m;++j,++i)
	{
		ans=min(ans,a[j]-a[i]);
	}
	cout<<ans<<endl;
}