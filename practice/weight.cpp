#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
ll power(ll x,ll n)
{
	if(n==0)
		return 1;
	if(n%2==0)
		return power((x*x)%M,n/2)%M;
	else
		return ((x%M)*(power((x*x)%M,(n-1)/2)%M))%M;
}
int main()
{
	ll t;
	cin>>t;
	
	while(t--)
	{
		ll n,w;
		cin>>n>>w;
		ll ans,s;
		if(w>=0)
			s=9-w;
		else
			s=9+w+1;
		if(abs(w)>9)
			ans=0;
		else if(n==2)
			ans=s;
		else
			ans=(s*(power(10,n-2)%M))%M;
		cout<<ans<<endl;
	}
}