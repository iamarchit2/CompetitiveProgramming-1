#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n,m;
	cin>>n>>m;
	vector<ll> tools(n);
	vector<vector<pair<ll,ll> > > a(n,vector<pair<ll,ll> >(m));
	for(ll i=0;i<n;++i)
	{
		for(ll j=0;j<m;++j)
		{
			cin>>a[i][j].f;
			a[i][j].s=j+1;
		}
		sort(a[i].begin,a[i].end());
	}
	vector<pair<pair<ll,ll>,ll> > x(n);
	for(ll i=0;i<n;++i)
	{
		x[i].f.f=a[i][0].f;
		x[i].f.s=a[i][0].s;
		x[i].s=i;
	}
	sort(x.begin(), x.end());
	ll enrgy=0;
	for(ll i=0;i<n;++i)
	{
		// if()
		enrgy+=x[i].f.f;
		// tools[x[i].s]=x[i].f.s;
	}
	cout<<enrgy<<endl;
}