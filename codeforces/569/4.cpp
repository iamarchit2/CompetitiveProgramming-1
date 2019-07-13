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
#define sort(a) sort(a.begin(),a.end())
void print1D(vi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
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
		ll n,m;
		cin>>n>>m;
		vector<vi> a(n,vi(m));
		ll count=1;
		vpi b,ans;
		for(ll i=0;i<n;++i)
		{
			for(ll j=0;j<m;++j)
			{
				b.pb(mp(i,j));
				if(i!=0)
					b.pb(mp(-1*i,j));
				if(j!=0)
					b.pb(mp(i,-1*j));
				if(i!=0 && j!=0)
					b.pb(mp(-1*i,-1*j));
			}
		}
		vi c(b.size());
		c[0]=1;
		a[0][0]=1;
		ll x=0,y=0;
		ans.pb(mp(x+1,y+1));
		while(count<n*m)
		{

			ll i=0;
			// cout<<i<<" ";
			while(1)
			{
				if(c[i]==1)
				{
					i++;
					// cout<<i<<" ";
					continue;
				}
				if(x+b[i].f>=0 && x+b[i].f<n && y+b[i].s>=0 && y+b[i].s<m)
				{
					if(a[x+b[i].f][y+b[i].s]==0)
					{
						c[i]=1;
						a[x+b[i].f][y+b[i].s]=1;
						x+=b[i].f;
						y+=b[i].s;
						ans.pb(mp(x+1,y+1));
						count++;
						ll j=i+1;
						while(j<b.size() && b[i]==b[j])
						{
							c[j]=1;
							j++;
						}
						break;
					}
					
					
				}
				i++;
			}
		}
		// print1D(c);
		for(ll i=0;i<ans.size();++i)
		{
			cout<<ans[i].f<<" "<<ans[i].s<<endl;
		}
	}
}

