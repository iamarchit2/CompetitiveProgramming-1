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
		ll n,m;
		cin>>n>>m;
		vi a(n),b(m);
		ll e1,o1,e2,o2;
		e1=o1=e2=o2=0;
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			if(a[i]%2)
			{
				o1++;
			}
			else
				e1++;
		}
		for(ll i=0;i<m;++i)
		{
			cin>>b[i];
			if(b[i]%2)
				o2++;
			else
				e2++;
		}
		ll ans=min(e1,o2)+min(e2,o1);
		cout<<ans<<endl;

	}
}
