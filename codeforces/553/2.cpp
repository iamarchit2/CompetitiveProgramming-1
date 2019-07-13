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
		vector<vi> a(n,vi(m));
		
		ll flag=0,index=-1;
 		for(ll i=0;i<n;++i)
		{
			um u;
			for(ll j=0;j<m;++j)
			{
				cin>>a[i][j];
				u[a[i][j]]++;
			}
			if(u.size()>1)
				index=i;
		}
		if(index==-1)
		{
			ll ans=0;
			for(ll i=0;i<n;++i)
			{
				ans^=a[i][0];
			}
			if(ans==0)
			{
				cout<<"NIE";
			}
			else
			{
				cout<<"TAK"<<endl;
				for(ll i=0;i<n;++i)
				{
					cout<<1<<" ";
				}
			}
		}
		else
		{
			cout<<"TAK"<<endl;
			ll ans=0;
			vi p(n);
			for(ll i=0;i<n;++i)
			{
				if(i==index)
					continue;
				ans^=a[i][0];
				p[i]=1;
			}
			ll k;
			for(ll i=0;i<m;++i)
			{
				if(a[index][i]!=ans)
				{
					k=i;
					break;
				}
			}
			p[index]=k+1;
			for(ll i=0;i<n;++i)
			{
				cout<<p[i]<<" ";
			}
		}
	}
}
