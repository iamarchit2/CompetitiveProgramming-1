#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<=b ; i++)
#define mp make_pair
#define INF 1000000000000000000
#define mod 1000000007
#define pi pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vpi a(n);
		ll minb=INF,ctr=0;
		for(ll i=0;i<n;++i)
		{
			cin>>a[i].f;
		}
		for(ll i=0;i<n;++i)
		{
			cin>>a[i].s;
			a[i].f=a[i].f%a[i].s;
			if(a[i].s<minb)
			{
				minb=a[i].s;
			}
		}
		for(ll i=0;i<n;++i)
		{
			if(a[i].f>=minb)
			{
				ctr+=a[i].s-a[i].f;
				a[i].f=0;
			}
		}
		// cout<<ctr<<endl;
		sort(a.begin(), a.end());
		vi c;
		c.pb(a[0].f);
		um u,k;
		ll ans=0;
		for(ll i=0;i<n;++i)
		{
			u[a[i].f]++;
			if(a[i].f!=c[c.size()-1])
				c.pb(a[i].f);
			if(a[i].f!=0)
			{
				k[a[i].f]+=a[i].s-a[i].f;
			}
		}
		// cout<<c.size()<<endl;
		for(ll i=0;i<c.size();++i)
		{
			// cout<<k[c[i]]<<" ";
			ans+=k[c[i]];
		}
		ans+=ctr;
		// cout<<ans<<endl;
		ll temp=ans;
		if(c[0]!=0)
			c.insert(c.begin(),0);
		for(ll i=1;i<c.size();++i)
		{
			
			temp=temp-k[c[i]]+(n-u[c[i]])*(c[i]-c[i-1]);
			if(i+1<c.size())
				k[c[i+1]]+=u[c[i+1]]*c[i];
			if(temp<ans)
				ans=temp;
		}
		cout<<ans<<endl;
	}
}