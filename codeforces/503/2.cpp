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
	ll n,r;
	cin>>n>>r;
	vi a(n+1);
	vector<pi> p;
	for(ll i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			ll z=1;
			ll t=i-r+1;
			ll q=i+r-1;
			ll x=max(z,t);
			ll y=min(n,q);
			p.pb(mp(x,y));
		}
	}
	if(p.size()==0)
	{
		cout<<-1;
		exit(0);
	}
	// ll l=1;
	
	if(p[0].f!=1 || p[p.size()-1].s!=n)
	{
		cout<<-1;
		exit(0);
	}
	ll ans=0;
	r=0;
	for(ll i=0;i<p.size();++i)
	{
		if(i!=0 && p[i].f==p[i-1].f)
		{
			r=p[i].s;
			continue;
		}
		if(p[i].f==r+1)
		{
			ans++;
			r=p[i].s;
		}
		else if(p[i].f>r+1)
		{
			r=p[i-1].s;
			if(p[i].f>r+1)
			{
				cout<<-1;
				exit(0);
			}
			else
			{
				ans++;
			}
		}
		if(r==n)
			break;
	}
	if(r!=n)
	{
		ans++;
	}
	cout<<ans<<endl;
}