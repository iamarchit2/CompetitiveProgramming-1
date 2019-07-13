#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll t;
	cin>>t;
	vector<vector<pair<ll,string> > > ans;
	while(t--)
	{
		ll n,k,v;
		cin>>n>>k>>v;
		vector<pair<ll,string> > a(n),b,c;
		for(ll i=0;i<n;++i)
		{
			cin>>a[i].s;
			a[i].f=i;
		}
		ll x=__gcd(n,k);
		ll p=n/x,q=k/x;
		v=v%p;
		if(v==0)
		{
			v=p;
		}
		b.push_back(make_pair(0,""));
		for(ll i=1;i<=q;++i)
		{
			for(ll j=0;j<n;++j)
			{
				b.push_back(a[j]);
			}
		}
		ll e=v*k,s=e-k+1;
		for(ll i=s;i<=e;++i)
		{
			c.push_back(b[i]);
		}
		sort(c.begin(),c.end());
		ans.push_back(c);
	}
	for(ll i=0;i<ans.size();++i)
	{
		cout<<"Case #"<<i+1<<": ";
		for(ll j=0;j<ans[i].size();++j)
		{
			cout<<ans[i][j].s<<" ";
		}
		cout<<endl;
	}
}