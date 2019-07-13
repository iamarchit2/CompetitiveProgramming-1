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
	ll t;
	// cin>>t;
	t=1;
	while(t--)
	{
		ll n;
		cin>>n;
		vi a(n-1),p(n),prefix(n);
		ll sum=0;
		for(ll i=0;i<n-1;++i)
		{
			cin>>a[i];
			sum+=a[i];
			prefix[i+1]=sum;
		}
		
		ll k=n-*max_element(prefix.begin(), prefix.end());
		um u;
		for(ll i=0;i<n;++i)
		{
			prefix[i]+=k;
			if(prefix[i]<=0 || prefix[i]>n || u[prefix[i]]==1)
			{
				cout<<-1;
				exit(0);
			}
			u[prefix[i]]=1;
		}
		print1D(prefix);
	}
}