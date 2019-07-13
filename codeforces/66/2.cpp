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
		ll a[6]={4 , 8, 15, 16, 23, 42};
		vi ans(6);
		map<ll,pair<ll,ll> > u;
		for(ll i=0;i<6;++i)
		{
			for(ll j=i+1;j<6;++j)
			{
				// cout<<a[i]*a[j]<<" ";
				u[a[i]*a[j]]=mp(a[i],a[j]);
			}
		}
		// ll x,y;
		// x=u[32].f;
		// y=u[32].s;
		// cout<<x<<" "<<y;
		cout<<"? 1 2"<<endl;
		fflush(stdout);
		ll n;
		cin>>n;
		ll x,y,b,c;
		x=u[n].f;
		y=u[n].s;
		cout<<"? 2 3"<<endl;
		fflush(stdout);
		// ll n;
		cin>>n;
		// ll x,y,b,c;
		b=u[n].f;
		c=u[n].s;
		if(x==b || x==c)
		{
			ans[1]=x;
			ans[0]=y;
			if(x==b)
			{	
				ans[2]=c;
			}
			else{
				ans[2]=b;
			}
		}
		else if(y==b || y==c)
		{
			ans[1]=y;
			ans[0]=x;
			if(y==b)
			{	
				ans[2]=c;
			}
			else{
				ans[2]=b;
			}
		}
		cout<<"? 4 5"<<endl;
		fflush(stdout);
		// ll n;
		cin>>n;
		// ll x,y,b,c;
		x=u[n].f;
		y=u[n].s;
		cout<<"? 5 6"<<endl;
		fflush(stdout);
		// ll n;
		cin>>n;
		// ll x,y,b,c;
		// mp(b,c)=u[n];
		b=u[n].f;
		c=u[n].s;
		if(x==b || x==c)
		{
			ans[4]=x;
			ans[3]=y;
			if(x==b)
			{	
				ans[5]=c;
			}
			else{
				ans[5]=b;
			}
		}
		else if(y==b || y==c)
		{
			ans[4]=y;
			ans[3]=x;
			if(y==b)
			{	
				ans[5]=c;
			}
			else{
				ans[5]=b;
			}
		}
		cout<<"! ";
		print1D(ans);
		cout<<endl;
	}
}

