#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<=b ; i++)
#define mp make_pair
#define INF 1000000000000000000
// #define mod 1000000007
#define pi pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>
#define mod 998244353
void dfs(ll i,vector<ll> &visited,vector<vector<ll> > &graph,ll &x,ll m)
{
	visited[i]=m;
	x=((x%mod)*(m%mod))%mod;
	if(m==2)
		m=1;
	else
		m=2;
	for(ll j=0;j<graph[i].size();++j)
		if(visited[graph[i][j]]==0)
			dfs(graph[i][j],visited,graph,x,m);
		else if(visited[i]==visited[graph[i][j]])
		{	
			x=0;
			return;
		}
		
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll v,e;
		cin>>v>>e;
		vector<vector<ll> > graph(v+1);
		for(ll i=0;i<e;++i)
		{
			ll src,dest;
			cin>>src>>dest;
			graph[src].pb(dest);
			graph[dest].pb(src);
		}
		vi visited(v+1);
		vi vis(v+1);
		ll x,y;
		ll m=2;
		ll a=1;
		for(ll i=1;i<=v;++i)
		{
			if(visited[i]==0)
			{
				x=1;
				m=2;
				dfs(i,visited,graph,x,m);
				y=1;
				m=1;
				dfs(i,vis,graph,y,m);
				a=(a*(x+y)%mod)%mod;
				// if(m==2)
				// 	m=1;
				// else 
				// 	m=2;
			}
		}
		
		m=1;
		
		// for(ll i=0;i<v+1;++i)
		// 	cout<<visited[i]<<" ";
		// cout<<endl;
		// cout<<x<<" ";
		// visited.clear();
		
		// for(ll i=1;i<=v;++i)
		// {
		// 	if(vis[i]==0)
		// 	{
		// 		y=1;
		// 		m=1;
		// 		dfs(i,vis,graph,y,m);
		// 		a2=(a2*y)%mod;
		// 		// if(m==2)
		// 		// 	m=1;
		// 		// else 
		// 		// 	m=2;
		// 	}
		// }
		// cout<<y<<" ";
		cout<<(a)%mod<<endl;
	}	
	
}