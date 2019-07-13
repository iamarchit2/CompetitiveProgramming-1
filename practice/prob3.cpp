#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll p,sub;
	cin>>p>>sub;
	vector<vector<pair<ll,ll> > > a(p,vector<pair<ll,ll> >(sub));
	for(ll i=0;i<p;++i)
	{
		for(ll j=0;j<sub;++j)
		{
			cin>>a[i][j].f;
		}
		for(ll j=0;j<sub;++j)
		{
			cin>>a[i][j].s;
		}
		sort(a[i].begin(),a[i].end());
	}
	vector<pair<ll,ll> > ans(p);
	for(ll i=0;i<p;++i)
	{
		ll ctr=0;
		for(ll j=0;j<sub-1;++j)
		{
			if(a[i][j].s>a[i][j+1].s)
				ctr++;
		}
		ans[i]=make_pair(ctr,i+1);
	}
	sort(ans.begin(),ans.end());
	for(ll i=0;i<p;++i)
	{
		cout<<ans[i].s<<endl;
	}
}