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
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll x;
		cin>>x;
		ll c=0;
		if(x<8)
		{
			cout<<1<<endl;
			continue;
		}
		c=(x/7)+(x%7!=0);
		cout<<c<<endl;
	}
}