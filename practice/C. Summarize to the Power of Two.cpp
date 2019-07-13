#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int main()
{
	ll n,ans=0;
	cin>>n;
	vector<ll> a(n+1),b;
	unordered_map<ll,ll> u; 
	for(ll i=1;i<=n;++i)
	{
		cin>>a[i];
		u[a[i]]+=i;
	}
	for(ll i=1;i<=2*(ll)pow(10,9);i*=2)
	{
		b.push_back(i);
	}
	for(ll i=1;i<=n;++i)
	{
		ll temp=0;
		for(ll j=0;j<b.size();++j)
		{
			if(u[b[j]-a[i]]!=0 && u[b[j]-a[i]]!=i)
			{
				temp=1;
				break;
			}
		}
		if(temp==0)
			ans++;
	}
	cout<<ans;
}