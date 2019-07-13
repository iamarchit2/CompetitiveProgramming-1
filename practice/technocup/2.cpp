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
	ll n,d;
	cin>>n>>d;
	ll m;
	cin>>m;
	for(ll i=0;i<m;++i)
	{
		ll x,y;
		cin>>x>>y;
		if(x+y-d>=0 && x+y-2*n+d<=0 && x-y-d<=0 && y-x-d<=0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}