#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n,d;
	cin>>n>>d;
	vector<ll> a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	if(n==1)
		cout<<2;
	else{
	unordered_map<ll,ll> b;
	ll ans=2;
	if(a[1]-a[0]-d>=d)
	{
		ans++;
		b[a[0]+d]=1;
	}
	if(a[n-1]-d-a[n-2]>=d)
	{
		if(b[a[n-1]-d]==0)
		{
			ans++;
			b[a[n-1]-d]=1;
		}
	}
	for(ll i=1;i<n-1;++i)
	{
		if(a[i]-d-a[i-1]>=d)
		{
			if(b[a[i]-d]==0)
			{
				ans++;
				b[a[i]-d]=1;
			}
		}
		if(a[i+1]-a[i]-d>=d)
		{
			if(b[a[i]+d]==0)
			{
				ans++;
				b[a[i]+d]=1;
			}
		}
	}
	cout<<ans;
}
}