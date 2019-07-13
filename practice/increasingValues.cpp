//https://www.hackerearth.com/challenge/competitive/may-circuits-18/algorithm/increasing-values-8ae86432/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
void bfs(vector<pair<ll,vector<ll> > > &tree,vector<pair<ll,vector<ll> > > &graph,vector<ll> &parent)
{
	queue<ll> q;
	q.push(1);
	vector<ll> visited(graph.size());
	visited[1]=1;
	while(q.size())
	{
		ll temp=q.front();
		q.pop();
		for(ll i=0;i<graph[temp].s.size();++i)
		{
			if(!visited[graph[temp].s[i]])
			{
				visited[graph[temp].s[i]]=1;
				q.push(graph[temp].s[i]);
				tree[temp].s.push_back(graph[temp].s[i]);
			}
			else
			{
				parent[temp]=graph[temp].s[i];
			}
		}
	}
}

ll dfs(vector<pair<ll,vector<ll> > > &tree,ll v,vector<ll> &visited)
{
	visited[v]=1;
	for(ll i=0;i<tree[v].s.size();++i)
	{
		if(!visited[tree[v].s[i]])
		{
			tree[v].f+=dfs(tree,tree[v].s[i],visited);
		}
	}
	return tree[v].f;
}
int main()
{
	ll n,q,x;
	cin>>n>>q>>x;
	vector<pair<ll,vector<ll> > > graph(n+1),tree(n+1);
	ll u,v;
	graph[1].s.push_back(1);
	for(ll i=0;i<n-1;++i)
	{
		cin>>u>>v;
		graph[u].s.push_back(v);
		graph[v].s.push_back(u);
	}
	for(ll i=1;i<=n;++i)
	{
		cin>>graph[i].f;
		tree[i].f=graph[i].f;
	}
	vector<ll> parent(n+1);
	parent[1]=1;
	bfs(tree,graph,parent);
	ll good=0;
	vector<ll> visited(n+1);
	tree[1].f+=dfs(tree,1,visited);
	for(ll i=1;i<=n;++i)
	{
		if(tree[i].f>x)
			good++;
	}
	while(q--)
	{
		ll d,a;
		cin>>d>>a;
		while(1)
		{
			ll t=1;
			if(d==1)
				t--;
			if(tree[d].f>x)
				break;
			tree[d].f+=a;
			if(tree[d].f>x)
				good++;
			d=parent[d];
			if(t==0)
				break;
		}
		cout<<good<<endl;
	}
}