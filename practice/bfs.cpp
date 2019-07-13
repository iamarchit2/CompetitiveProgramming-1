#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n;
	cin>>n;
	unordered_set<ll> a[n+1];
	for(ll i=1;i<n;++i)
	{
		ll x,y;
		cin>>x>>y;
		a[x].insert(y);
		a[y].insert(x);
	}
	vector<ll> s(n),visited(n+1),m(n+1);
	for(ll i=0;i<n;++i)
	{
		cin>>s[i];
		m[s[i]]++;
		if(m[s[i]]==2)
		{
			cout<<"No"<<endl;
			exit(0);
		}
	}
	if(s[0]!=1)
	{
			cout<<"No"<<endl;
			exit(0);
	}
	queue< ll > q;
	q.push(s[0]);
	ll x, i=1;
	while(!q.empty())
	{
		x=q.front();
		while(a[x].size())
		{
			q.push(s[i]);
			if(a[x].find(s[i])!=a[x].end())
			{
				a[x].erase(s[i]);
				a[s[i]].erase(x);
				i++;
			}
			else
			{
				cout<<"No\n";
				return 0;
			}
		}
		q.pop();
	}
	cout<<"Yes\n";
}