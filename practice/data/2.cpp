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

ll digitsum(ll n)
{
	ll a=0;
	while(n)
	{
		a+=n%10;
		n/=10;
	}
	return a;
}
bool f(ll n,ll x,unordered_map<ll,pi> &u)
{
	while(n/10)
	{
		n=digitsum(n);
		x++;
	}
	if(u[n].f==1)
		return true;
	u[n].f=1;
	u[n].s=x;
	return false;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		unordered_map<ll,pi> u;
		ll n,d;
		cin>>n>>d;
		ll x=0;
		while(1)
		{
			if(f(n,x,u))
			{
				break;
			}
			n+=d;
			x++;
		}
		ll i=0;
		while(u[i].f==0)
		{
			i++; 
		}
		cout<<i<<" "<<u[i].s<<endl;
	}

}