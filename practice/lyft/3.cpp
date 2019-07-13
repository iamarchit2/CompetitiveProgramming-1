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
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>

int main()
{
	ll n;
	cin>>n;
	vi a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	vi b(n);
	ll ctr=0;
	for(ll i=0;i<n;++i)
	{
		ll j=i-a[i];
		while(j>=0)
		{
			if(a[j]>a[i])
			{
				b[i]=-1;
				break;
			}
			j-=a[i];
		}
		if(b[i]==-1)
			continue;
		j=i+a[i];
		while(j<n)
		{
			if(a[j]>a[i])
			{
				b[i]=-1;
				break;
			}
			j+=a[i];
		}
		if(b[i]!=-1)
		{
			b[i]=1;
			ctr++;
		}
	}
	while(ctr!=n)
	{
		for(ll i=0;i<n;++i)
		{
			if(b[i]==1 || b[i]==0)
				continue;
			ll j=i-a[i];
			while(j>=0)
			{
				if(a[j]>a[i] && b[j]==1)
				{
					b[i]=0;
					ctr++;
					break;
				}
				j-=a[i];
			}
			if(b[i]==0)
				continue;
			j=i+a[i];
			while(j<n)
			{
				if(a[j]>a[i] && b[j]==1)
				{
					b[i]=0;
					ctr++;
					break;
				}
				j+=a[i];
			}
			// if(b[i]==-1)
			// 	b[i]=1;
		}
		for(ll i=0;i<n;++i)
		{
			if(b[i]==1 || b[i]==0)
				continue;
			ll j=i-a[i];
			ll t=0;
			while(j>=0)
			{
				if(a[j]>a[i] && b[j]==-1)
				{
					t=1;
					break;
				}
				j-=a[i];
			}
			if(t)
				continue;
			j=i+a[i];
			while(j<n)
			{
				if(a[j]>a[i] && b[j]==-1)
				{
					t=1;
					break;
				}
				j+=a[i];
			}
			if(t==0)
			{
				b[i]=1;
				ctr++;
				break;
			}
		}
	}
	for(ll i=0;i<n;++i)
	{
		if(b[i]==1)
			cout<<"B";
		else
			cout<<"A";
	}
	cout<<endl;
}