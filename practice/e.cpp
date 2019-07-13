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

int main()
{
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<ll> a(k);
	for(ll i=0;i<n;++i)
	{
		a[s[i]-'A']++;
	}
	cout<<k*(*min_element(a.begin(), a.end()));
}