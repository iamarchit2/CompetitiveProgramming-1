#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	ll max=LLONG_MIN,min=LLONG_MAX;
	ll maxi,mini;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
		if(a[i]>max)
		{
			max=a[i];
			maxi=i;
		}
		if(a[i]<=min)
		{
			min=a[i];
			mini=i;
		}
	}
	ll ans=0;
	if(mini>maxi)
	{
		ans=maxi+n-1-mini;
	}
	else
	{
		ans=maxi+n-1-mini-1;
	}
	cout<<ans<<endl;
}