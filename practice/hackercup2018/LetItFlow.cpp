#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007
int main()
{
	ll t;
	cin>>t;
	vector<ll> ans;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<string> a(3);
		for(ll i=0;i<3;++i)
			cin>>a[i];
		ll ctr=1;
		ll factor=2;
		if(n%2==1)
		{
			ans.push_back(0);
			continue;
		}
		if(a[0][0]=='#' || a[1][0]=='#' || a[1][n-1]=='#' || a[2][n-1]=='#')
		{
			ans.push_back(0);
			continue;
		}
		for(ll j=1;j<=n-2;j+=2)
		{
			factor=2;
			if(a[0][j]=='#' || a[0][j+1]=='#')
				factor-=1;
			if(a[1][j]=='#' || a[1][j+1]=='#')
				factor-=2;
			if(a[2][j]=='#' || a[2][j+1]=='#')
				factor-=1;
			ll temp=0;
			factor=max(factor,temp);
			ctr=((ctr%M) * (factor%M))%M;
			if(ctr==0)
				break;
		}
		ans.push_back(ctr);
	}
	for(ll i=0;i<ans.size();++i)
	{
		cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;
	}
}