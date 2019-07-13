#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n,k;
	cin>>n>>k;
	vector<pair<ll,ll> > a(n);
	unordered_map<ll,ll> u;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].f;
		a[i].s=i;
	}
	ll temp=k;
	vector<ll> ans;
	for(ll i=0;i<n;++i)
	{
		if(u[a[i].f]==0 && temp!=0)
		{
			u[a[i].f]=1;
			ans.push_back(a[i].s);
			temp--;
		}
		if(temp==0)
		{
			break;
		}
	}
	if(ans.size()<k)
		cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for(ll i=0;i<ans.size();++i)
		{
			cout<<ans[i]+1<<" ";
		}
	}

}