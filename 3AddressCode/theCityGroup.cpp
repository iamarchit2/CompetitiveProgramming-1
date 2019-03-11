#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<b ; i++)
#define mp make_pair
#define INF 1000000000000000000
#define mod 1000000007
#define pi pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vpi(n);
		vi k(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i].f>>a[i].s;
		}
		for(ll i=0;i<n;++i)
		{
			cin>>k[i];
		}
		vi d(n);
		for(ll i=0;i<n;++i)
		{
			for(ll j=0;j<n;++j)
			{
				d[i]+=abs(a[i].f-a[j].f)+abs(a[i].s-a[j].s);
			}
		}
		sort(d.begin(), d.end());
		sort(k.begin(), k.end());
		ll ans=0;
		for(ll i=0;i<n;++i)
		{
			ans+=(d[i]*k[n-1-i]);
		}
		cout<<ans<<endl;
	}
}