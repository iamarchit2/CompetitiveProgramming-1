#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<ll>


int main()
{
	for(ll i=0;i<1000;++i);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vi a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		vi max_sum(n);
		max_sum[0]=max((ll)0,a[0]);
		max_sum[1]=max(max_sum[0],a[1]);
		for(ll i=2;i<n;++i)
		{
			max_sum[i]=max(max_sum[i-1],max_sum[i-2]+a[i]);
		}
		vi ans;
		ll i;
		for(i=n-1;i>=2;--i)
		{
			if(max_sum[i]==max_sum[i-1])
			{
				continue;
			}
			else
			{
				ans.pb(a[i]);
				i--;
			}
		}
		if(i==0 && a[i]>0)
		{
			ans.pb(a[i]);
		}
		if(i==1 && max(a[0],a[1])>0)
		{
			ans.pb(max(a[0],a[1]));
		}
		for(ll i=0;i<ans.size();++i)
			cout<<ans[i];
		cout<<endl;
	}
}
