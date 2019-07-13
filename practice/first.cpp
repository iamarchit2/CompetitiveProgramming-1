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
		ll s,e;
		cin>>s>>e;
		ll n;
		cin>>n;
		ll temp=1;
		while(n--)
		{
			ll x,y;
			cin>>x>>y;
			if((x>s && x<e) || (y>s && y<e))
			{
				temp=0;
			}
		}
		if(temp)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}