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

int main()
{
	ll n;
	cin>>n;
	vpi a(n);
	vi b(n),c(n);
	um u;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].f>>a[i].s;
		b[i]=a[i].f+a[i].s;
		u[b[i]]++;
	}
	ll S;
	cin>>S;
	ll ans=0;
	for(ll i=0;i<n;++i)
	{
		ans+=u[b[i]-S];
	}
	cout<<ans<<endl;
}