#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<b ; i++)
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
	ll t;
	t=1;
	// cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		vi a(n),v(k);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			v[a[i]%k]++;
		}
		ll ans=v[0]/2,i=1,j=k-1;
		for(;i<j;++i,--j)
		{
			ans+=min(v[i],v[j]);
		}
		if(i==j)
			ans+=(v[i]/2);
		cout<<ans*2<<endl;
	}
}
