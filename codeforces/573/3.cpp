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
#define vvi vector<vi>
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>
#define sortA(a) sort(a.begin(),a.end())
#define sortD(a) sort(a.begin(),a.end(),greater<int>())
#define all(a) (a.begin(),a.end())
void print1D(vi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void print2D(vector<vi> a)
{
	for(ll i=0;i<a.size();++i)
	{
		for(ll j=0;j<a[i].size();++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t=1;
	// cin>>t;
	while(t--)
	{
		ll n,m,k;
		cin>>n>>m>>k;
		vi a(m);
		for(ll i=0;i<m;++i)
		{
			cin>>a[i];
		}
		ll c1=0,c2=0;
		ll x=a[0]/k;
		if(a[0]%k==0)
			x--;
		ll ans=0;
		for(ll i=0;i<m;)
		{
			if((a[i]-c2)/k==x)
			{
				c1++;
				i++;
			}
			else if((a[i]-c2)/k==x+1 && (a[i]-c2)%k==0)
			{
				c1++;
				i++;
			}
			else
			{
				ans++;
				c2+=c1;
				c1=0;
				x=(a[i]-c2)/k;
				if((a[i]-c2)%k==0)
					x--;
			}
		}
		if(c1)
			ans++;
		cout<<ans<<endl;
	}
}
