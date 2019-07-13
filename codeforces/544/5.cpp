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
void bfs(ll i,vector<vector<ll> > &graph)
{
	vector<ll> visited(graph.size(),0);
	queue<ll> q;
	q.push(i);
	visited[i]=1;
	while(q.size())
	{
		ll temp=q.front();
		for(ll j=0;j<graph[temp].size();++j)
		{
			if(visited[graph[temp][j]]==0)
			{
				visited[graph[temp][j]]=1;
				cout<<temp<<" "<<graph[temp][j]<<endl;
				q.push(graph[temp][j]);
			}
		}
		q.pop();
	}
}
int main()
{
	ll n,m;
	cin>>n>>m;
	vector<vi> a(n+1);
	for(ll i=0;i<m;++i)
	{
		ll u,v;
		cin>>u>>v;
		a[u].pb(v);
		a[v].pb(u);
	}
	ll index=-1,l=0;
	for(ll i=1;i<=n;++i)
	{
		if(a[i].size()>l)
		{
			index=i;
			l=a[i].size();
		}
	}
	bfs(index,a);
}