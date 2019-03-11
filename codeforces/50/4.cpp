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
	ll n,m;
	cin>>n;
	vi a(n);
	ll x=0,y=0;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
		x+=a[i];
	}
	
	cin>>m;
	vi b(m);
	for(ll i=0;i<m;++i)
	{
		cin>>b[i];
		y+=b[i];
	}
	// if(n==1 || m==1)
	// {
	// 	if(x==y)
	// 	{
	// 		cout<<1<<endl;
	// 		return 0;
	// 	}
	// 	else
	// 	{
	// 		cout<<-1<<endl;
	// 		return 0;
	// 	}
	// }
	ll ans=0,p,q;
	for(ll i=0,j=0;i<n && j<m;)
	{
		if(i==0 && j==0)
		{
			p=a[i];
			q=b[j];
		}
		if(p==q)
		{
			ans++;
			i++;j++;
			if(i==n && j==m)
			{
				cout<<ans;
				return 0;
			}
			if(i>=n || j>=m)
			{
				cout<<-1;
				return 0;
			}
			p=a[i];
			q=b[j];
		}
		if(p>q)
		{
			j++;
			if(j==m)
			{
				cout<<-1;
				return 0;
			}
			q+=b[j];
		}
		else if(q>p)
		{
			
			i++;
			if(i==n)
			{
				cout<<-1;
				return 0;
			}
			p+=a[i];
		}

	}
}