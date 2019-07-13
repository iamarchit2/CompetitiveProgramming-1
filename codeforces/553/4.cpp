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
		ll n;
		cin>>n;
		// vpi a(n);
		// vi b(n);
		vector<pair<ll,pair<ll,ll> > > a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i].s.f>>a[i].s.s;
			a[i].f=a[i].s.f-a[i].s.s;
		}
		sort(a.begin(),a.end());
		// sort(a.begin(),a.end());
		// ll ans=0;
		// ll temp=a[0].f;
		
		// for(ll i=0;i<n;++i)
		// {
		// 	ll j=i;
		// 	vi p;
		// 	while(j<n && a[j].f==temp)
		// 	{
		// 		p.pb(a[j].s);
		// 		j++;
		// 	}
		// 	sort(p.begin(),p.end());
		// 	for(ll k=i,q=p.size()-1;k<j;++k,q--)
		// 	{
		// 		a[k].s=p[q];
		// 	}
		// 	i=j;
		// }
		// cout<<endl;
		// for(ll i=0;i<n;++i)
		// {
		// 	cout<<a[i].f<<" "<<a[i].s<<endl;
		// }
		ll ans=0;
		for(ll i=n-1,j=0;i>=0;--i,j++)
		{
			ans+=a[i].s.f*j+a[i].s.s*(n-1-j);
		}
		cout<<ans<<endl;
	}
}
