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
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		for(ll i=0;i<m;++i)
		{
			cin>>b[i];
		}
		sort(a.begin(), a.end());
		ll y=a[0],j;
		for(ll i=0;i<n;++i)
		{
			a[i]-=y;
		}
		vi dif;
		for(ll i=0;i<n-1;++i)
		{
			dif.pb(a[i+1]-a[i]);
		}
		ll hcf=dif[0];
		for(ll i=1;i<dif.size();++i)
		{
			hcf=__gcd(hcf,dif[i]);
		}
		ll flag=1;
		// cout<<hcf<<endl;
		for(ll i=0;i<m;++i)
		{
			if((hcf%b[i])==0)
			{
				flag=0;
				cout<<"YES"<<endl;
				cout<<y<<" "<<i+1<<endl;
				break;
			}
		}
		if(flag)
			cout<<"NO"<<endl;
	}
}