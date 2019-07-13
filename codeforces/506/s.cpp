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
	ll ans=0,temp=0;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for(ll i=0,j=0;i<n;++i)
	{
		while(j<n && a[j]<=2*a[i])
		{
			temp++;
			j++;
		}
		ans=max(ans,temp);
		temp=j-1-i;
		if(j==n)
			break;
	}
	cout<<ans<<endl;
}