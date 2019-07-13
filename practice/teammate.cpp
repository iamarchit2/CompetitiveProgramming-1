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
#define vpi vector<pi>
int main()
{
	ll t;
	cin>>t;
	gcd_extended(2,mod,&inv,&y);
	while(t--)
	{
		ll n;
		cin>>n;
		vi a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		sort(a.begin(),a.end(),greater<ll>());
		vpi p;
		p.pb(mp(a[0],1));
		for(ll i=1;i<n;++i)
		{
			if(a[i]==p[p.size()-1].f)
				p[p.size()-1].s++;
			else
				p.pb(mp(a[i],1));
		}
		ll ans=1;
		for(ll i=0;i<p.size();i++)
		{
			if(p[i].s%2==0)
			{
				for(ll j=1;j<p[i].s;j=j+2)
					ans=(ans*j)%mod;
			}
			else
			{
				for(ll j=1;j<p[i].s;j=j+2)
					ans=(ans*j)%mod;
				ans=(ans*p[i+1].s)%mod;
				p[i+1].s--;
			}
		}
		cout<<ans<<endl;
	}
}