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
	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		ll ans=0;
		if(d+1<=a && (d+1)%b==0)
			ans++;
		ll x=(c-1)/b;
		ll y=a/b-(d+1)/b;
		ll z=0;
		ans+=max(z,x);
		ans+=max(z,y);
		cout<<ans<<endl;
		// ll x=a/b;
		// ll y=0;
		// if(c%b==0)
		// {
		// 	x--;
		// 	y=c;
		// }
		// else
		// {
		// 	x--;
		// 	y=b*(c/b+1);
		// }
		// y=(d-y)/b;
		// cout<<x-y<<endl;
	}
}