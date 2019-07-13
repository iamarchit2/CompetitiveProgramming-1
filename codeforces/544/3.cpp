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
	while(t--)
	{
		ll n;
		cin>>n;
		vi a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		sort(a.begin(), a.end());
		ll ans=0,temp=0;
		for(ll i=0,j=0;j<n;)
		{
			if(a[j]-a[i]<=5)
			{
				temp++;
				j++;
			}
			else
			{
				ans=max(ans,temp);
				i++;
				temp--;;
			}
		}
		ans=max(ans,temp);
		cout<<ans;
	}
}
