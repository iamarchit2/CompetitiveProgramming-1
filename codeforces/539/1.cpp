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
	ll n,v;
	cin>>n>>v;
	n-=1;
	if(v>=n)
	{
		cout<<n<<endl;
		exit(0);
	}
	ll ans=v,i=1,l=v;
	while(n)
	{
		if(v==n)
		{
			// cout<<ans<<endl;
			break;
		}
		n-=1;
		i++;
		ans+=i;
	}
	cout<<ans<<endl;
}