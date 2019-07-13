#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n;
	cin>>n;
	ll ans=0;
	for(ll i=1;i<=n;i*=2)
	{
		n-=i;
		ans++;
	}
	if(n!=0)
		ans++;
	cout<<ans<<endl;
}