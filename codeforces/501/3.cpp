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
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>
int main()
{
	ll n;
	cin>>n;
	vi b(n/2),a(n);
	for(ll i=0;i<n/2;++i)
	{
		cin>>b[i];
	}
	a[0]=0;
	a[n-1]=b[0];
	for(ll i=1;i<n/2;++i)
	{
		if(b[i]-a[i-1]<=a[n-i])
		{
			a[i]=a[i-1];
			a[n-i-1]=b[i]-a[i];
		}
		else
		{
			a[n-i-1]=a[n-i];
			a[i]=b[i]-a[n-i-1];
		}
	}
	for(ll i=0;i<n;++i)
	{
		cout<<a[i]<<" ";
	}
}