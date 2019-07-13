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
	ll n,a,b;
	cin>>n>>a>>b;
	vi x(n);
	for(ll i=0;i<n;++i)
	{
		cin>>x[i];
	}
	ll cost=0,flag=0;;
	for(ll i=0;i<n/2;++i)
	{
		if(x[i]==0)
		{
			if(x[n-1-i]==1)
			{
				flag=1;
				break;
			}
			else if(x[n-1-i]==2)
			{
				cost+=a;
			}
		}
		else if(x[i]==1)
		{
			if(x[n-1-i]==0)
			{
				flag=1;
				break;
			}
			else if(x[n-1-i]==2)
			{
				cost+=b;
			}
		}
		else
		{
			if(x[n-1-i]==0)
			{
				cost+=a;
			}
			else if(x[n-1-i]==1)
			{
				cost+=b;
			}
			else
			{
				cost+=2*min(a,b);
			}
		}
	}
	if(n%2==1)
	{
		if(x[n/2]==2)
		{
			cost+=min(a,b);
		}
	}
	if(flag==1)
	{
		cout<<-1;
	}
	else
	{
		cout<<cost;
	}
}