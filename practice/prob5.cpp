#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
void dfs1(ll i,vector<vector<ll> > &graph,map<pair<ll,ll>,ll> &m,vector<ll> &cycle,
	vector<ll> &from,vector<ll> visited)
{
	visited[i]=1;
	for(ll j=0;j<graph[i].size();++j)
	{
		if(visited[graph[i][j]]==0)
		{
			from[graph[i][j]]=i;
			dfs1(graph[i][j],graph,m,cycle,from,visited);
		}
		else if(graph[i][j]!=from[i])
		{
			cycle[m[make_pair(graph[i][j],i)]]=1;
			ll temp=i;
			while(temp!=graph[i][j])
			{
				cycle[m[make_pair(temp,from[temp])]]=1;
				temp=from[temp];
			}
		}
	}
		
}
void dfs2(ll i,ll &x,ll &y,vector<vector<ll> > &graph,map<pair<ll,ll>,ll> &m,vector<ll> &cycle,
	vector<ll> visited,ll p)
{
	visited[i]=1;
	for(ll j=0;j<graph[i].size();++j)
	{	
		if(visited[graph[i][j]]==0)
		{
			if(cycle[m[make_pair(i,graph[i][j])]]==0)
			{
				if(p==0)
				{
					x++;y++;
				}
				else
				{
					y++;
				}
				dfs2(graph[i][j],x,y,graph,m,cycle,visited,p);
			}
			else
			{
				if(p==0)
				{
					y++;
					dfs2(graph[i][j],x,y,graph,m,cycle,visited,1);
				}
				else
				{
					continue;
				}
			}
		}
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
		vector<vector<ll> > graph(n+1);
		vector<pair<ll,ll> > edges(m+1); 
		map<pair<ll,ll>,ll> M;
		for(ll i=1;i<=m;++i)
		{
			ll x,y;
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
			edges[i]=make_pair(x,y);
			M[make_pair(x,y)]=M[make_pair(y,x)]=i;
		}
		vector<ll> cycle(m+1),from(n+1),visited(n+1);
		dfs1(1,graph,M,cycle,from,visited);
		// for(ll i=1;i<=m;++i)
		// {
		// 	cout<<cycle[i]<<" ";
		// }
		// for(ll i=1;i<=m;++i)
		// {
		// 	ll u=edges[i].f;
		// 	ll v=edges[i].s;
		// 	visited[u]=visited[v]=1;
		// 	ll left1=0,left2=0,right1=0,right2=0;
		// 	ll p;
		// 	if(cycle[i]==1)
		// 		p=1;
		// 	else
		// 		p=0;
		// 	dfs2(u,left1,left2,graph,M,cycle,visited,p);
		// 	dfs2(v,right1,right2,graph,M,cycle,visited,p);
		// 	ll res=1;
		// 	res+=left2+right2+left1*right2+right1*left2-left1*right1;
		// 	if(p==1)
		// 	{
		// 		res+=left2*right2;
		// 	}
		// 	// cout<<left1<<" "<<left2<<" "<<right1<<" "<<right2<<" "<<res<<endl;
		// 	cout<<res<<endl;
		// 	visited[u]=visited[v]=0;
		// }
	}
}