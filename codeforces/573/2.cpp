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
		string x,y,z;
		cin>>x>>y>>z;
		if(x==y && y==z)
		{
			cout<<0<<endl;
			continue;
		}
		if(x==y || y==z || x==z)
		{
			cout<<1<<endl;continue;
		}
		vector<pair<int,char> > a(3);
		a[0].f=x[0]-'0'+0;
		a[1].f=y[0]-'0'+0;
		a[2].f=z[0]-'0'+0;
		// cout<<a[1].f;
		a[0].s=x[1];
		a[1].s=y[1];
		a[2].s=z[1];
		sortA(a);
		if(a[0].s==a[1].s && a[1].s==a[2].s){
			
			if(a[0].f+1==a[1].f && a[1].f+1==a[2].f)
			{
				cout<<0<<endl;
				continue;
			}
		}
		if(a[0].s!=a[1].s && a[1].s!=a[2].s && a[0].s!=a[2].s)
		{
			cout<<2<<endl;
			continue;
		}
		if(a[0].s==a[1].s)
		{
			if(a[0].f+1==a[1].f || a[0].f+2==a[1].f)
			{
				cout<<1<<endl;
				continue;
			}
		}
		if(a[0].s==a[2].s)
		{
			if(a[0].f+1==a[2].f || a[0].f+2==a[2].f)
			{
				cout<<1<<endl;
				continue;
			}
		}
		if(a[1].s==a[2].s)
		{
			if(a[1].f+1==a[2].f || a[1].f+2==a[2].f)
			{
				cout<<1<<endl;
				continue;
			}
		}
		cout<<2<<endl;
	}
}
