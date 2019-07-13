#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n,s;
	cin>>n>>s;
	vector<ll> a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	ll ans=0;
	sort(a.begin(), a.end());
	if(a[n/2]==s)
		cout<<ans<<endl;
	else if(a[n/2]<s)
	{
		for(ll i=n/2;i<n && a[i]<s;++i)
		{
			ans+=s-a[i];
		}
		cout<<ans<<endl;
	}
	else 
	{
		for(ll i=n/2;i>=0 && a[i]>s;--i)
		{
			ans+=a[i]-s;
		}
		cout<<ans<<endl;
	}
}