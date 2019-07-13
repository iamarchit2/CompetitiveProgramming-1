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
	ll n,m;
	cin>>n>>m;
	vi a(n);
	map<pi,ll> M;
	um u;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
		u[a[i]]=i;
	}
	vpi b(m);
	for(ll i=0;i<m;++i)
	{
		cin>>b[i].f>>b[i].s;
		if(u[b[i].f]<u[b[i].s])
			M[b[i]]=1;
	}
	ll flag=1,i=n-1,j=n-1,k=a[n-1];
	// while(flag)
	{
		vi c;
		i=j-1;
		while(i>=0)
		{
			if(M[mp(a[i],k)]==1)
			{
				// if(a[i]==k)
				// 	j--;
				// flag=1;
				// swap(a[i-1],a[i]);
				// break;
				// ll t=i;
				// while(t<n-1 && M[mp(a[t],a[t+1])]==1)
				// {
				// 	if(a[t+1]==k)
				// 		j--;
				// 	swap(a[t],a[t+1]);
				// 	t++;
				// }
				// i++;
				// cout<<c.size()<<" ";
				flag=1;
				for(ll t=0;t<c.size();++t)
				{
					if(M[mp(a[i],c[t])]==0)
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					// cout<<a[i]<<" ";
					j--;
				}
				else
				{
					c.pb(a[i]);
				}
			}
			else
			{
				c.pb(a[i]);	
			}
			i--;
		}
	}
	cout<<n-1-j<<endl;
}
