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
	ll n,t;
	cin>>n>>t;
	vector<pi> a(n);
	vi b(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].f;
		b[i]=a[i].f+t+1;
	}
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].s;
	}
	sort(a.begin(),a.end());
	ll temp=0;
	for(ll i=0;i<n-1;++i)
	{
		if(a[i].s>a[i+1].s)
		{
			temp=1;
			break;
		}
	}
	if(temp==1)
	{
		cout<<"No"<<endl;
	}
	else
	{
		cout<<"yes"<<endl;
		for(ll i=0;i<n;++i)
		{
			cout<<b[i]<<" ";
		}
		cout<<endl;
	}
}