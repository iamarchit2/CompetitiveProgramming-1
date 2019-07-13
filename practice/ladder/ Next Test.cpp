#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	vector<ll> b(3001);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
		b[a[i]]=1;
	}
	for(ll i=1;i<=3000;++i)
	{
		if(b[i]==0)
		{
			cout<<i<<endl;
			break;
		}
	}
}