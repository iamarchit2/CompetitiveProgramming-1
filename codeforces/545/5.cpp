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
	ll h,n;
	cin>>h>>n;
	vi a(n);
	ll m=0,sum=0;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
		a[i]=-a[i];
		sum+=a[i];
		m=max(m,sum);
	} 

	ll r=h;
	ll l=h-m;
	ll ans=0;
	if(l>0)
	{
		if(sum<=0)
		{
			cout<<-1<<endl;
			exit(0);
		}
		if(l%sum==0)
		{
			ans+=(l/sum)*n;
			r=m;
		}
		else
		{
			ans+=((l/sum)+1)*n;
			r=h-((l/sum)+1)*sum;
		}
	}
	for(ll i=0;i<n && r>0;++i)
	{
		r-=a[i];
		ans++;
	}
	if(r>0)
	{
		cout<<-1<<endl;
		exit(0);
	}
	cout<<ans<<endl;
}