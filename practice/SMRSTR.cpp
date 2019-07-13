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
		ll n,q;
		cin>>n>>q;
		vector<ll> d(n);
		ll p=1;for(ll i=0;i<n;++i)
		{
			cin>>d[i];
			if(p<=1000000000)
			{
				p*=d[i];
			}
		}
		vector<ll> x(q);
		for(ll i=0;i<q;++i)
		{
			cin>>x[i];
			x[i]=x[i]/p;
		}
		for(ll i=0;i<q;++i)
		{
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}
}