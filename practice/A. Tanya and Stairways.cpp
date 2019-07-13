#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n,s=1;
	cin>>n;
	vector<ll> a(n),b;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
		if(a[i]==1 && i)
		{
			s++;
			b.push_back(a[i-1]);
		}
	}
	b.push_back(a[n-1]);
	cout<<s<<endl;
	for(ll i=0;i<b.size();++i)
	{
		cout<<b[i]<<" ";
	}
}