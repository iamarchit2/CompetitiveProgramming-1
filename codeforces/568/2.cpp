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
#define sort(a) sort(a.begin(),a.end())
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
		ll n;
		cin>>n;
		while(n--)
		{
			string x,y;
			cin>>x>>y;
			ll flag=1;
			vector<pair<char,ll> > a,b;
			// for(ll i=0,j=0;i<x.size() && j<y.size();)
			// {
			// 	ll f=0;
			// 	while(j<y.size() && x[i]==y[j])
			// 	{
			// 		j++;
			// 		f=1;
			// 	}
			// 	if(f==0)
			// 	{
			// 		flag=0;
			// 		break;
			// 	}
			// 	i++;
			// }
			// if(flag)
			// 	cout<<"YES"<<endl;
			// else
			// 	cout<<"NO"<<endl;
			ll c=1;
			for(ll i=0;i<x.size()-1;++i)
			{
				if(x[i]==x[i+1])
				{
					c++;
				}
				else
				{
					a.pb(mp(x[i],c));
					c=1;
				}
			}
			a.pb(mp(x[x.size()-1],c));
			c=1;
			for(ll i=0;i<y.size()-1;++i)
			{
				if(y[i]==y[i+1])
				{
					c++;
				}
				else
				{
					b.pb(mp(y[i],c));
					c=1;
				}
			}
			b.pb(mp(y[y.size()-1],c));
			if(a.size()!=b.size())
			{
				cout<<"NO"<<endl;
			}
			else
			{
				ll f=0;
				for(ll i=0;i<a.size();++i)
				{
					if(a[i].f!=b[i].f || a[i].s>b[i].s)
					{
						f=1;
						break;
					}
				}
				if(f)
					cout<<"NO"<<endl;
				else
					cout<<"YES"<<endl;
			}
		}
	}
}

