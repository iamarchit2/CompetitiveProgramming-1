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
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vi a(n);
		ll sum=0;
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			sum=(sum%mod+a[i]%mod)%mod;
		}
		ll q;
		cin>>q;
		vi l(n),r(n),x(n);
		for(ll i=0;i<q;++i)
		{
			cin>>l[i];
		}
		for(ll i=0;i<q;++i)
		{
			cin>>r[i];
		}
		for(ll i=0;i<q;++i)
		{
			cin>>x[i];
		}
		ll p;
		cin>>p;
		vi b(q);
		for(ll i=0;i<q;++i)
		{
			b[i]=(r[i]-l[i]+1)*x[i];
		}
		sort(b.begin(),b.end());
		ll mins=sum,maxs=sum;
		for(ll i=0;i<p;++i)
		{
			mins=(mins%mod+b[i]%mod)%mod;
			maxs=(maxs%mod+b[q-1-i]%mod)%mod;
		}
		cout<<maxs<<" "<<mins<<endl;
	}
}

