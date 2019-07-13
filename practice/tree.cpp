#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define m 1000000007
ull f(ull d,ull a,ull b)
{
	if(d==0)
		return a;
	if(d==1)
		return b;
	return((f(d-1,a,b)%m+f(d-2,a,b)%m)%m);
}
ull distance(vector<ull> b,vector<pair<ull,ull> > tree,ull u)
{
	vector<ull> a;
	a.push_back(u);	
	while(tree[u].first!=u)
	{
		a.push_back(tree[u].first);
		u=tree[u].first;
	}
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	ull i=0;
	while(a[i]==b[i])
	{
		if(i==a.size() || i==b.size())
		{
			i++;
			break;
		}
		i++;
	}
	i--;
	return(a.size()+b.size()-2-2*i);
}
int main()
{
	ull t;
	cin>>t;
	while(t--)
	{
		ull n,q;
		cin>>n>>q;
		vector<pair<ull,ull> > tree(n+1);
		for(ull i=1;i<=n;++i)
		{
			tree[i].first=i;
		} 
		for(ull i=1;i<=n-1;++i)
		{
			ull x,y,temp;
			cin>>x>>y;
			if(tree[x].first==x)
			{
				tree[x].first=y;
			}
			else if(tree[y].first==y)
			{
				tree[y].first=x;
			}
			else
			{
				while(x!=y)
				{
					temp=tree[y].first;
					tree[y].first=x;
					x=y;
					y=temp;
				}
			}
		}
		while(q--)
		{
			ull choice;
			cin>>choice;
			switch(choice)
			{
				case 1:  {
					        ull v,k,a,b;
					        cin>>v>>k>>a>>b;
					        vector<ull> c;	
	                        c.push_back(v);	
                        	while(tree[v].first!=v)
                        	{
		                       c.push_back(tree[v].first);
		                       v=tree[v].first;
	                        }
					        for(ull i=1;i<=n;++i)
					        {
					        	ull d=distance(c,tree,i);
					        	if(d<=k)
					        	{
					        		tree[i].second=(tree[i].second%m+f(d,a,b)%m)%m;
					        	}
					        }
					        break;
				         }
				case 2:  {
					        ull v;
					        cin>>v;
					        cout<<tree[v].second<<endl;
					        break;
			           	 }
			}
		}
	}
}