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
void print1D(vi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
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
		ll n,m;
		cin>>n>>m;
		vi u(n+1);
		vi a(n+1);
		for(ll i=0;i<m;++i)
		{
			ll k;
			cin>>k;
			if(k==0)
				continue;
			// a.clear();
			// a.resize(k);
			for(ll j=0;j<k;++j)
			{
				cin>>a[j];
			}
			ll j=0;
			for(j=0;j<k-1;++j)
			{
				if(u[a[j]]==0)
				{
					u[a[j]]=a[j+1];
				}
				else if(u[a[j]]==a[j])
				{
					u[a[j]]=a[j+1];
				}
				else
				{
					// ll temp=u[a[j]];
					// u[a[j]]=a[j+1];
					// u[a[j+1]]=temp;
					ll k=u[a[j]];
					while(u[k]!=k)
					{
						k=u[k];
					}
					u[k]=a[j+1];
				}
			}
			if(u[a[j]]==0)
				u[a[j]]=a[j];
		}
		vi ans(n+1);
		vi temp;
		for(ll i=1;i<=n;++i)
		{
			if(ans[i]!=0)
				continue;
			// vi temp;
			temp.clear();
			ll c=1;
			temp.pb(i);
			ll j=i;
			while(u[j]!=j && u[j]!=0)
			{
				c++;
				temp.pb(j);
				j=u[j];
			}
			if(j!=i)
				temp.pb(j);
			for(ll j=0;j<temp.size();++j)
			{
				ans[temp[j]]=c;
			}
			// print1D(ans);
			// cout<<endl;
		}
		for(ll i=1;i<=n;++i)
		{
			cout<<ans[i]<<" "; 
		}
		cout<<endl;
	}
}

