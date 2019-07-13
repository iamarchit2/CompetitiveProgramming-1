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
	ll n,m;
	cin>>n>>m;
	vector<pi> a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].f;
	}
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].s;
		a[i].f=a[i].f*a[i].s;
	}
	sort(a.begin(), a.end());
	ll x,st=0,end=a[n-1].f;
	while(1)
	{
		x=(st+end)/2;
		ll bal=m;
		for(ll i=0;i<n;++i)
		{
			if(x>=a[i].f)
				continue;
			else
			{
				bal-=(a[i].f-x)/a[i].s+((a[i].f-x)%a[i].s!=0);
			}
		}
		if(bal==0)
		{
			cout<<x<<endl;
			break;
		}
		else if(bal<0)
		{
			st=x;
		}
		else
		{
			end=x;
		}
	}
}