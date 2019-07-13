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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		vector<vector<ll> > a(n+1);
		ll u,v;
		for(ll i=0;i<m;++i)
		{
			cin>>u>>v;
			// cin>>a[i];
			a[u].pb(v);
			a[v].pb(u);
		}
		vector<ll> visited(n+1,0);
		queue<ll> q;
		q.push(1);
		visited[1]=1;
		while(q.size())
		{
			ll temp=q.front();
			for(ll j=0;j<a[temp].size();++j)
			{
				if(visited[a[temp][j]]==0)
				{
					if(visited[temp]==1)
						visited[a[temp][j]]=2;
					else
						visited[a[temp][j]]=1;
					q.push(a[temp][j]);
				}
			}
			q.pop();
		}
		ll on=count(visited.begin(), visited.end(),1);
		ll tw=count(visited.begin(), visited.end(),2);
		ll x,y;
		if(on<=tw)
		{
			x=on;
			y=1;
		}
		else
		{
			x=tw;
			y=2;
		}
		cout<<x<<endl;
		for(ll i=1;i<=n;++i)
		{
			if(visited[i]==y)
				cout<<i<<" ";
		}
		cout<<endl;
	}
}