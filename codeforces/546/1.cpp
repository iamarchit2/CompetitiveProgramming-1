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
	ll n;
	cin>>n;
	vpi a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].f>>a[i].s;
	}
	ll k;
	cin>>k;
	ll r=0;
	for(ll i=0;i<n;++i)
	{
		if(k>=a[i].f && k<=a[i].s)
		{
			break;
		}
		r++;
	}
	cout<<n-r<<endl; 
}
