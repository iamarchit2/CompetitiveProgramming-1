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
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vi a(n),b(n+1);
		for(ll	 i=0;i<n;++i)
		{
			cin>>a[i];
			if(a[i]<=n)
			{
				b[a[i]]=1;
			}
		}
		ll ans=0;
		for(ll i=1;i<=n;++i)
		{
			if(b[i]==0)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}