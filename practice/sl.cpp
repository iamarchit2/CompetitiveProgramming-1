#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<=b ; i++)
#define mp make_pair
#define INF 1000000000000000000
#define mod 1000000007
#define pi pair<ll,ll>
#define vi vector<ll>

int main()
{
	ll n,p=0,q=0,m=INF,sum=0;
	cin>>n;
	vi a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
		sum+=abs(a[i]);
		m=min(m,abs(a[i]));
		if(a[i]<=0)
			p=1;
		if(a[i]>=0)
			q=1;
	}
	if(n==1)
		{cout<<a[0]<<endl;
	return 0;}
	if(p==1 && q==1)
	{
		cout<<sum<<endl;
	}
	else 
	{
		cout<<sum-2*m<<endl;
	}
	

}