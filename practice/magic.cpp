#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
using namespace std;

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k,sum=0,ctr=0;
		cin>>n>>k;
		vector<ll> a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			sum+=a[i];
		}
		for(ll i=0;i<n;++i)
		{
			if((a[i]+k)>(sum-a[i]))
			{
				ctr++;
			}
		}
		cout<<ctr<<endl;
	}
}