#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<b ; i++)
#define mp make_pair
#define INF 1000000000000000000
#define mod 998244353 
#define pi pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>
void print1D(vi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
}
void print2D(vector<vi> a)
{
	for(ll i=0;i<a.size();++i)
	{
		for(ll j=0;j<a[i].size();++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t=1;
	// cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vi a(n),b(n),c(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		for(ll i=0;i<n;++i)
		{
			cin>>b[i];
		}
		for(ll i=0;i<n;++i)
		{
			c[i]=a[i]*(i+1)*(n-i);
		}
		sort(c.begin(), c.end());
		sort(b.begin(), b.end());
		ll ans=0;
		for(ll i=0;i<n;++i)
		{
			ans=(ans%mod+c[i]%mod*b[n-i-1]%mod)%mod;
		}
		cout<<ans<<endl;
	}
}

