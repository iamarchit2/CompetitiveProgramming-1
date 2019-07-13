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
		ll k;
		cin>>k;
		if(k<25)
		{
			cout<<-1<<endl;
			continue;
		}
		ll i,f=1;
		for(i=5;i<=sqrt(k);++i)
		{
			if(k%i==0)
			{
				f=0;
				break;
			}
		}
		if(f==1)
		{
			cout<<-1<<endl;
			continue;
		}
		ll n=i;
		ll m=k/i;
		n-=5;
		m-=5;
		vector<vector<char> > a{{'a','e','i','o','u'},
								{'e','i','o','u','a'},
								{'i','o','u','a','e'},
								{'o','u','a','e','i'},
								{'u','a','e','i','o'}};
		vector<char> temp({'a','e','i','o','u'});
		for(ll i=0;i<n;++i)
		{
			a.pb(temp);
		}
		for(ll i=0;i<n;++i)
		{
			temp.pb('a');
		}
		for(ll i=0;i<m;++i)
		{
			for(ll j=0;j<n+5;++j)
			{
				a[j].pb(temp[j]);
			}
		}
		for(ll i=0;i<a.size();++i)
		{
			for(ll j=0;j<a[i].size();++j)
			{
				cout<<a[i][j];
			}
			// cout<<endl;
		}
		cout<<endl;
	}
}
