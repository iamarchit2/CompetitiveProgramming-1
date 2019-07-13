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
	ll n;
	cin>>n;
	ll x,y;
	ll ans=0;
	for(ll i=0;i<n;++i)
	{
		cin>>x>>y;
		if(x+y>ans)
		{
			ans=x+y;
		}
	}
	cout<<ans<<endl;
}