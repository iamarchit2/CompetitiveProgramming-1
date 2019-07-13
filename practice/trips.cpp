#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	vector<vector<ll> > g(n+1);
	vector<ll> a(n+1);
	ll ans=0;
	for(ll i=0;i<m;++i)
	{
		ll x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
		if(a[x]==1 && a[y]==1)
		{
			cout<<ans<<endl;
			continue;
		}
		if(ans==0)
		{
			if(g[x].size()>=k && g[y].size()>=k)
			{
				unordered_map<ll,ll> m;
				for(ll j=0;j<g[x].size();++j)
				{
					m[g[x][j]]=1;
				}
				vector<ll> common;
				for(ll j=0;j<g[y].size();++j)
				{
					if(m[g[y][j]]==1)
					{
						common.push_back(g[y][j]);
					}
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			if(a[x]==0 && g[x].size()>=k)
			{
				ll ctr=0;
				for(ll j=0;j<g[x].size();++j)
				{
					if(a[g[x][j]]==1)
						ctr++;
				}
				if(ctr>=k)
				{
					a[x]=1;
					ans++;
				}
			}
			if(a[y]==0 && g[y].size()>=k)
			{
				ll ctr=0;
				for(ll j=0;j<g[y].size();++j)
				{
					if(a[g[y][j]]==1)
						ctr++;
				}
				if(ctr>=k)
				{
					a[y]=1;
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
}