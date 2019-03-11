#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<=b ; i++)
#define mp make_pair
#define INF 1000000000000000000
#define mod 998244353
#define pi pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>

int main()
{
	ll n;
	cin>>n;
	string s;
	cin>>s;
	if(n==1)
	{
		cout<<1<<endl;
		exit(0);
	}
	if(s[0]!=s[n-1])
	{
		ll ans=1,i=0;
		while(s[i]==s[0])
		{
			i++;
			ans++;
		}
		i=n-1;
		while(s[i]==s[n-1])
		{
			i--;
			ans++;
		}
		cout<<ans<<endl;
	}
	else
	{
		ll ans=0,i=0,x=0,y=0;
		while(s[i]==s[0])
		{
			i++;
			x++;
		}
		i=n-1;
		while(s[n-1]==s[i])
		{
			i--;
			y++;
		}
		ans=((x+1)%mod*(y+1)%mod)%mod;
		cout<<ans<<endl;
	}
	
}