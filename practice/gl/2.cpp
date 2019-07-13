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
void print1D(vpi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i].s<<" ";
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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vpi a,b,c,d;
		ll temp;
		for(ll i=0;i<n;++i)
		{
			cin>>temp;
			if(i%2==0)
				a.pb(mp(temp,i));
			else
				b.pb(mp(temp,i));
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		ll asum=a[a.size()-1].f,bsum=b[b.size()-1].f,aans=0,bans=0;
		c.pb(mp(a[a.size()-1].s,a[a.size()-1].f));
		d.pb(mp(b[b.size()-1].s,b[b.size()-1].f));
		for(ll i=a.size()-2;i>=0;--i)
		{
			if((asum+a[i].f)<=asum)
			{
				// cout<<aans<<" ";
				break;
			}
			else
			{
				asum+=a[i].f;
				c.pb(mp(a[i].s,a[i].f));
			}
		}
		sort(c.begin(), c.end());
		// print1D(c);
		for(ll j=0,k=1;j<c.size();++j,k*=10)
		{
			aans+=k*c[j].s;
		}
		for(ll i=b.size()-2;i>=0;--i)
		{
			if((bsum+b[i].f)<=bsum)
			{
				// cout<<bans<<" ";
				break;
			}
			else
			{
				bsum+=b[i].f;
				d.pb(mp(b[i].s,b[i].f));
			}
		}
		sort(d.begin(), d.end());
		for(ll j=0,k=1;j<d.size();++j,k*=10)
		{
			bans+=k*d[j].s;
		}
		if(asum>bsum)
		{
			cout<<aans<<endl;
		}
		else if(bsum>asum)
		{
			cout<<bans<<endl;
		}
		else
		{
			cout<<max(aans,bans)<<endl;
		}
	}
}
