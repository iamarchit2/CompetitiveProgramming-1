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

int main()
{
	ll n;
	cin>>n;
	if(n==1 || n==2)
	{
		cout<<"No";
		return 0;
	}
	vi a,b;
	for(ll i=1;i<=n;++i)
	{
		if(i%2==0)
			a.pb(i);
		else
			b.pb(i);
	}
	cout<<"Yes"<<endl;
	cout<<a.size()<<" ";
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<b.size()<<" ";
	for(ll i=0;i<b.size();++i)
	{
		cout<<b[i]<<" ";
	}
}