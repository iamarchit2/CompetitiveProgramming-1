//https://www.codechef.com/ZCOPRAC/problems/ZCO14003

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
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	ll m=a[0]*n;
	for(ll i=1;i<n;++i)
	{
		if(a[i]*(n-i)>m)
			m=a[i]*(n-i);
	}
	cout<<m<<endl;
}