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
	ll n;
	cin>>n;
	vi a(n);
	ll sum=0;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a.begin(),a.end());
	// vi b(n);
	// ll t=0;
	// for(ll i=n-1,k=1;i>=0;--i)
	// {
	// 	t+=a[i];
	// 	b[k]=t;
	// 	k++;
	// }
	ll q;
	cin>>q;
	ll x=0;
	while(q--)
	{
		ll k,ans=0;
		cin>>k;
		ll t=n-k;
		while(t--)
		{
			x+=a[k];
		}
		cout<<x<<endl;
	}
}