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
	vector<ll> a(n),b(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for(ll i=0;i<n;++i)
	{
		cin>>b[i];
	}
	ll sa=0,sb=0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll p=n-1,q=n-1;
	// for(ll i=0;i<n;++i)
	// {
	// 	if(a[i]<)
	// }
	while(p>-1 || q>-1)
	{
		if(p<=-1)
		{
			q--;
		}
		else if(q<=-1)
		{
			sa+=a[p];
			p--;
		}
		else if(a[p]>b[q])
		{
			sa+=a[p];
			p--;
		}
		else
		{
			q--;
		}
		if(q<=-1)
		{
			p--;
		}
		else if(p<=-1)
		{
			sb+=b[q];
			q--;
		}
		else if(b[q]>a[p])
		{
			sb+=b[q];
			q--;
		}
		else
		{
			p--;
		}
	}
	cout<<sa-sb<<endl;
}