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
	cin>>t;
	while(t--)
	{
		float n,A,b,x,y,z;
		cin>>n>>A>>b>>x>>y>>z;
		// vi a(n),c;
		multiset<ll> a;
		for(ll i=0;i<n;++i)
		{
			ll temp;
			cin>>temp;
			a.insert(temp);
			// cin>>a[i];
			// c.pb(a[i]);
		}
		if(b>=z)
		{
			cout<<"RIP"<<endl;
			continue;
		}
		// sort(a.begin(),a.end());
		// while(a[n-1]!=0)
		// {
		// 	for(ll i=0;i<n;++i)
		// 	{
		// 		a[i]/=2;
		// 		c.pb(a[i]);
		// 	}
		// }
		// sort(c.begin(),c.end());
		ll k=ceil((z-b)/y)-1;
		ll req=z-A-k*x;
		ll sum=0,ans=0;;
		// for(ll i=c.size()-1;i>=0;--i)
		// {
		// 	if(req<=0)
		// 		break;
		// 	req-=c[i];
		// 	ans++;
		// }
		// cout<<*(a.rbegin());
		multiset<ll>::iterator it=a.end();
		it--;
		while(req>0 && *(it)!=0)
		{
			ans++;
			req-=*(it);
			ll k=*it/2;
			a.erase(it);
			a.insert(k);
			it=a.end();
			it--;
// cout<<*it<<endl;
		}
		if(req>0)
			cout<<"RIP"<<endl;
		else
			cout<<ans<<endl;
	}
}
