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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vi a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			a[i]=a[i]%3;
		}
		sort(a);
		ll one=count(a.begin(), a.end(),1);
		ll two=count(a.begin(), a.end(),2);
		ll z=count(a.begin(), a.end(),0);
		ll ans=z+min(one,two)+(max(one,two)-min(one,two))/3;
		cout<<ans<<endl;;
	}
}