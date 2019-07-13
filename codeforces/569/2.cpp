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
		// vpi a,b;
		vi c(n);
		for(ll i=0;i<n;++i)
		{
			ll temp;
			cin>>temp;
			c[i]=temp;
			// if(temp>=0)
			// 	a.pb(mp(temp,i));
			// else
			// 	b.pb(mp(temp,i));
			if(temp>=0)
				c[i]=-1*(c[i]+1);

		}
		if(c.size()%2)
		{
			// ll k=*max_element(c.begin(),c.end());
			// c[k]=
			ll m=INF,k=-1;
			for(ll i=0;i<n;++i)
			{
				if(c[i]<m)
				{
					m=c[i];
					k=i;
				}
			}
			c[k]=-1*(c[k]+1);
		}
		print1D(c);
		// sort(a);
		// sort(b);
		// if(b.size()%2==0)
		// {
		// 	if(a.size()%2==0)
		// 	{

		// 	}
		// 	else
		// 	{

		// 	}
		// }
		// else
		// {

		// }
	}
}

