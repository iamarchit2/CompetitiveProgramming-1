#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second 

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll ans=0;
		vector<ll> a(2001,0);
		ll temp;
		for(ll i=0;i<n;++i)
		{
			cin>>temp;
			a[1000+temp]++;
		}
		for(ll i=0;i<a.size();++i)
		{
			ans+=(a[i]*(a[i]-1))/2;
			for(ll j=i+1;j<a.size();++j)
			{
				if((i+j)%2==1)
					continue;
				if(a[(i+j)/2])
				{
					ans+=a[i]*a[j];
				}
			}
		}
		cout<<ans<<endl;
	}
}