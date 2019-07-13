#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int main()
{
	ll n;
	cin>>n;
	vector<ll> b(n+1);
	unordered_set<ll> z;
	vector<pair<ll,ll> > a(n+1);
	for(ll i=1;i<=n;++i)
	{
		cin>>a[i].f;
		b[i]=a[i].f;
		a[i].s=i;
	}
	sort(a.begin(),a.end());
	
	ll time=0;
	for(ll i=1;i<=n;++i)
	{
		time=a[i].f;
		a[i].f=0;
		z.insert(a[i].s);
		if(z.find(time%n+1)!=z.end())
		{
			cout<<time%n+1;
			break;
		}
	}
}