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
	vi a(n);
	ll x=0,y=0;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
		x+=a[i];
	}
	ll m;
	cin>>m;
	vi b(m);
	for(ll i=0;i<m;++i)
	{
		cin>>b[i];
		y+=b[i];
	}
	if(n==1 || m==1)
	{
		if(x==y)
		{
			cout<<1<<endl;
			return 0;
		}
		else
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	ll ans=0;
	ll p=a[0],q=b[0];
	ll i,j;
	for(i=1,j=1;i<n && j<m;)
	{
		if(p==q)
		{
			ans++;
			p=a[i];q=b[j];
			i++;j++;
		}
		else if(p>q)
		{
			q+=b[j];
			j++;
		}
		else
		{
			p+=a[i];
			i++;
			// cout<<i<<" ";
		}
	}
	// cout<<i<<endl;
	// cout<<p<<" "<<q;
	if(i==n)
	{
		for(;j<m;++j)
			q+=b[j];
	}
	else if(j==m)
	{
		for(;i<n;++i)
			p+=a[i];
	}
	if(p==q)
	{
		cout<<ans+1;
	}
	else
	{
		cout<<-1;
	}
}