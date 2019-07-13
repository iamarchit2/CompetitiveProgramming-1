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
	ll n,ans=0;
	cin>>n;
	vi a(n),b(n);
	map<pi,ll> c;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for(ll j=0;j<n;++j)
	{
		cin>>b[j];
	}
	for(ll i=0;i<n;++i)
	{
		if(a[i]==0)
		{
			if(b[i]==0)
				ans++;
		}
		else
		{
			ll gcd=__gcd(a[i],b[i]);
			if(gcd)
			{
				a[i]/=gcd;
				b[i]/=gcd;
			}
			if(a[i]<0)
			{
				a[i]=-a[i],b[i]=-b[i];
			}
			c[mp(a[i],b[i])]++;
		}
	}
	ll temp=0;
	for(auto it:c)
	{
		temp=max(temp,it.s);
	}
	ans+=temp;
	cout<<ans<<endl;
}
