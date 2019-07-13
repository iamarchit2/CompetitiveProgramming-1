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
		ll n,q;
		cin>>n>>q;
		// vi a(n);
		deque <int> a;
		ll m=0;
		for(ll i=0;i<n;++i)
		{
			ll f;
			cin>>f;
			if(f>m)
				m=f;
			a.pb(f);
			// cin>>a[i];
		}

		// ll k=300001;
		vpi ans;
		// for(ll i=1;i<=k-1;++i)
		// {
		while(a.front()!=m)
		{
			ll x=a.front();
			a.pop_front();
			ll y=a.front();
			a.pop_front();
			// ans[i].f=x;
			// ans[i].s=y;
			ans.pb(mp(x,y));
			if(x>y)
			{
				a.push_front(x);
				a.pb(y);
			}
			else
			{
				a.push_front(y);
				a.pb(x);
			}

		}
		vi b(n);
		for(ll i=0;i<n;++i)
		{
			b[i]=a.front();
			a.pop_front();
		}
		// print1D(b);
		while(q--)
		{
			ll m;
			cin>>m;
			if(m<=ans.size())
			{
				cout<<ans[m-1].f<<" "<<ans[m-1].s<<endl;
			}
			else
			{
				m-=ans.size();
				m%=(n-1);
				if(m==0)
					m=n-1;
				cout<<b[0]<<" "<<b[m]<<endl;
			}
		}
	}
}

