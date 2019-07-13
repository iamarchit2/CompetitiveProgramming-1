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
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		vi a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		sort(a);
		ll x,y;
		x=max(a[0]-k,(ll)0);
		y=a[0]+k;
		ll f=1;
		for(ll i=1;i<n;++i)
		{
			if(a[i]==a[i-1])
				continue;
			ll xn=max(a[i]-k,(ll)0);
			ll yn=a[i]+k;
			if(xn>y)
			{
				f=0;
				break;
			}
			else
			{
				x=xn;
			}
		}
		if(f)
			cout<<y<<endl;
		else
			cout<<-1<<endl;
	}
}
