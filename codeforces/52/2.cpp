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
	ll n,m;
	cin>>n>>m;
	ll x=n-2*m;
	ll y=0;
	ll mi=max(y,x);
	ll mx;
	
	if(m==0)
	{
		mx=n;
		cout<<mi<<" "<<mx;
		exit(0);
	}
	mx=n-2;
	ll v=2;
	m--;
	while(m>0)
	{
		mx--;
		m-=v;
		v++;
	}
	cout<<mi<<" "<<mx;
}