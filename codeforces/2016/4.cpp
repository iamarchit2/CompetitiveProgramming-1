#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<=b ; i++)
#define mp make_pair
#define INF 1000000000000000000
#define mod 1000000007
#define pi pair<ll,ll>
#define vi vector<ll>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,d,dm;
		cin>>n>>m>>d>>dm;
		vector<vi> a(n+1);
		if(m<n*d || m>n*dm)
		{
			cout<<"-1"<<endl;
			continue;
		}
		d=m/n;
		ll e=m%n;
		for(ll i=1;i<=n;++i)
		{
			ll k=i+1;
			for(ll j=1;j<=d;++j)
			{
				if(k==n+1)
					k=1;
				a[i].pb(k);
				// a[k].pb(i);
				k++;
				
			}
		}
		for(ll i=1;i<=e;++i)
		{
			a[i].pb(i);
			// a[i+n].pb(i);
		}
		for(ll i=1;i<=n;++i)
		{
			for(ll j=0;j<a[i].size();++j)
			{
				cout<<i<<" "<<a[i][j]<<endl;
			}
		}
	}
}