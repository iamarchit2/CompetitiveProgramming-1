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
#define sort(a) sort(a.begin(),a.end())
void print1D(vi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void print2D(vector<vi> a)
{
	for(ll i=0;i<a.size();++i)
	{
		for(ll j=0;j<a[i].size();++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t=1;
	// cin>>t;
	while(t--)
	{
		ll p,q;
		cin>>p>>q;
		ll n=max(p,q);
		ll m=min(p,q);
		ll ans=0;
		if(m==1)
		{
			cout<<(n+1)/3;
			continue;
		}
		if(m==2)
		{
			cout<<(n+1)/2;
			continue;
		}
		if(m%3==0)
		{
			ans+=2*((n+1)/3);
			m-=3;
		}
		ll x=(n+1)/2;
		ll y=(m+1)/3;
		ans+=x*y;
		if((m+1)%3==2)
			ans+=(n+1)/3;
		cout<<ans<<endl;
	}
}