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
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>

int main()
{
	ll n;
	cin>>n;
	vpi a(n+1);
	for(ll i=1;i<=n;++i)
	{
		cin>>a[i].f>>a[i].s;
	}
	vi b;
	b.pb(1);
	if(a[a[1].f].f==a[1].s || a[a[1].f].s==a[1].s)
	{
		ll i=1;
		b.pb(a[1].f);
		b.pb(a[1].s);
		while(1)
		{
			if(a[b[i]].f==b[i+1])
			{
				if(a[b[i]].s==1)
				{
					break;
				}
				b.pb(a[b[i]].s);
			}
			else
			{
				if(a[b[i]].f==1)
				{
					break;
				}
				b.pb(a[b[i]].f);
			}
			i++;
		}
	}
	else
	{
		ll i=1;
		b.pb(a[1].s);
		b.pb(a[1].f);
		while(1)
		{
			if(a[b[i]].f==b[i+1])
			{
				if(a[b[i]].s==1)
				{
					break;
				}
				b.pb(a[b[i]].s);
			}
			else
			{
				if(a[b[i]].f==1)
				{
					break;
				}
				b.pb(a[b[i]].f);
			}
			i++;
		}
	}
	for(ll i=0;i<b.size();++i)
	{
		cout<<b[i]<<" ";
	}
}