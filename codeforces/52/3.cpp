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
	ll n,k;
	cin>>n>>k;
	vi a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	ll sum=0;
	for(ll i=1;i<n;++i)
	{
		a[i]-=a[0];
		sum+=a[i];
	}
	a[0]=0;
	vector<pi> b;
	b.pb(make_pair(a[0],1));
	for(ll i=1;i<n;++i)
	{
		if(a[i]==b[b.size()-1].f)
		{
			b[b.size()-1].s++;
		}
		else
		{
			b.pb(mp(a[i],1));
		}
	}
	vi c(b.size());
	c[b.size()-1]=b[b.size()-1].s;
	for(ll i=b.size()-2;i>=0;--i)
	{
		c[i]=c[i+1]+b[i].s;
	}
	// cout<<c[0];
	
	ll h=a[a.size()-1]-1;
	ll ans=0;
	ll x=0;
	ll y=c.size()-1;
	while(h>=0)
	{

		x+=c[y];
		// cout<<h<<" "<<x<<endl;
		if(x>k)
		{
			ans++;
			x=0;
		}
		else
		{
			if(h==b[y-1].f)
				y--;
			h--;
		}
	}
	if(x!=0)
		ans++;
	cout<<ans;

	// ll ans=1,x=1;;
	// while(sum>k)
	// {
	// 	sum-=(b[x].f-b[x-1].f)*c[x];
	// 	ans++;
	// 	x++;
	// }
	// cout<<ans;
}