#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
ll total_pattern=0;
int n;
bool check_path(int node1,int node2,vector<int> visited,vector<vector<int> > groups)
{
	int index=node1*n+node2;
	for(int i=0;i<groups[index].size();++i)
	{
		if(groups[index][i]==node1 || groups[index][i]==node2)
		{
			i++;
			while(groups[index][i]!=node1 && groups[index][i]!=node2)
			{
				if(!visited[i])
					return false;
				i++;
			}
			break;
		}
	}
	return true;
}
void pattern(int node,vector<int> visited,int length,vector<vector<int> > groups)
{
	++length;
	if(length>=1)
	{
		total_pattern++;
	}
	visited[node]=1;
	for(int i=0;i<n;++i)
	{
		if(i!=node)
		{
			if(!visited[i] && check_path(node,i,visited,groups))
			{
				pattern(i,visited,length,groups);
			}
		}
	}
}
int main()
{
	cin>>n;
	vector<pair<int,int> > a(n);
	for(int i=0;i<n;++i)
	{
		cin>>a[i].f>>a[i].s;
	}
	vector<vector<int> > groups;
	
	sort(a.begin(),a.end());
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			// if(i==j)
			// 	continue;

			for(int k=0;k<groups.size();++k)
			{
				if()
			}
		
			// vector<int> t;
			// for(int k=0;k<n;++k)
			// {
			// 	int m1=(a[k].s-a[j].s)*(a[k].f-a[i].f);
			// 	int m2=(a[k].f-a[j].f)*(a[k].s-a[i].s);
			// 	if(m1==m2)
			// 	{
			// 		t.push_back(k);
			// 	}
			// }
			// groups.push_back(t);
		}
	}
	// for(int i=0;i<groups.size();++i)
	// {
	// 	for(int j=0;j<groups[i].size();++j)
	// 	{
	// 		cout<<groups[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	vector<int> visited(n,0);
	for(int i=0;i<n;++i)
	{
		pattern(i,visited,-1,groups);
	}
	cout<<total_pattern;
}