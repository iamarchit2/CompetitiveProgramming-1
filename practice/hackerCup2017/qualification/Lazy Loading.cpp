#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll t;
	cin>>t;
	vector<ll> ans;
	while(t--)
	{
		ll n,ctr=0;
		cin>>n;
		vector<ll> w(n);
		for(ll i=0;i<n;++i)
		{
			cin>>w[i];
		}
		sort(w.begin(),w.end());
		ll i=0,j=n-1;
		while(1)
		{
			ll temp=ceil(50.0/w[j])-1;
			i+=temp;
			if(i>j)
				break;
			ctr++;
			j--;
		}
		ans.push_back(ctr);
	}
	for(ll i=0;i<ans.size();++i)
	{
		cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;
	}
}