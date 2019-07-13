#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
// #define s second
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
	// cin>>t;
	while(t--)
	{
		ll n,y;
		cin>>n>>y;
		vi a(n);
		ll sum=0;
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			sum+=a[i];
		}
		vi x(n);
		x[0]=max((ll)0,a[0]);
		for(ll i=1;i<n;++i)
		{
			x[i]=x[i-1]+a[i];
			x[i]=max((ll)0,x[i]);
		}
		ll k=*max_element(x.begin(), x.end());
		ll s,e;
		for(ll i=0;i<n && k!=0;++i)
		{
			if(x[i]==k)
			{
				e=i,s=i-1;
				while(s>=0 && x[s]!=0)
				{
					s--;
				}
				s++;
				break;
			}
		}
		if(y>0)
		{
			cout<<k*y<<endl;
			continue;
		}
		if(k==0)
		{
			cout<<sum*y<<endl;
			continue;
		}
		ll b1=0,b2=0,b=0;
		if(s!=0)
		{
			s--;
			b=y*a[s];
			b1=b;
			s--;
			while(s>=0)
			{
				b+=y*a[s];
				b1=max(b1,b);
				s--;
			}
		}
		if(e!=n-1)
		{
			e++;
			b=y*a[e];
			b2=b;
			e++;
			while(e<n)
			{
				b+=y*a[e];
				b2=max(b2,b);
				e++;
			}
		}
		cout<<k+max(b1,b2)<<endl;
	}
}