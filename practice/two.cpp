#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n;
	cin>>n;
	vector<ll> p(n+1),holes(n+1);
	for(ll i=1;i<=n;++i)
	{
		cin>>p[i];
	}
	for(ll i=1;i<=n;++i)
	{
		vector<ll> holes(n+1);
		holes[i]=1;
		ll j=p[i];
		while(1)
		{
			holes[j]++;
			if(holes[j]==2)
			{
				cout<<j<<" ";
				break;
			}
			j=p[j];
		}
	}
}