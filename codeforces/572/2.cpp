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
#define sort(a) sort(a.begin(),a.end())
void print1D(vi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
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
		ll n;
		cin>>n;
		vi a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		sort(a);
		reverse(a.begin(),a.end());
		ll tem=a[2];
		a.erase(a.begin()+2);
		a.pb(tem);
		int f=1;
		for(ll i=0;i<n;++i)
		{
			if(i==0)
			{
				if((a[n-1]+a[1])<=a[0])
				{
					f=0;
					break;
				}
			}
			else if(i==n-1)
			{
				if((a[n-2]+a[0])<=a[n-1])
				{
					f=0;
					break;
				}
			}
			else
			{
				if((a[i-1]+a[i+1])<=a[i])
				{
					f=0;
					break;
				}
			}
		}
		if(f)
		{
			cout<<"YES"<<endl;
			print1D(a);
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}
