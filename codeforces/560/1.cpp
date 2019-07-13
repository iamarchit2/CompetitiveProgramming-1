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
void print1D(vi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
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
		ll n,x,y;
		cin>>n>>x>>y;
		string a;
		cin>>a;
		ll i=n-1;
		ll ans=0;
		for(;i>n-1-y;--i)
		{
			if(a[i]=='1')
				ans++;
		}
		if(a[i]=='0')
			ans++;
		i--;
		for(;i>n-1-x;--i)
		{
			if(a[i]=='1')
				ans++;
		}
		cout<<ans<<endl;
	}
}

