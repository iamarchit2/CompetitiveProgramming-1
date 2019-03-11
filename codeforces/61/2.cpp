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
	ll t;
	t=1;
	// cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vi a(n);
		ll sum=0;
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			sum+=a[i];
		}
		sort(a.begin(), a.end());
		ll m;
		cin>>m;
		vi b(m);
		for(ll i=0;i<m;++i)
		{
			cin>>b[i];
			cout<<(sum-a[n-b[i]])<<endl;
		}

	}
}
