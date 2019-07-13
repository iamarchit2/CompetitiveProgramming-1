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
		ll w,h;
		cin>>h>>w;
		vector<string> a(h);
		for(ll i=0;i<h;++i)
		{
			cin>>a[i];
		}
		if(h<=2 || w<=2)
		{
			cout<<"NO"<<endl;
			continue;
		}
		vector<vector<ll> > b(h,vi(w));
		ll f=0;
		for(ll i=0;i<h;++i)
		{
			for(ll j=0;j<w;++j)
			{
				if(a[i][j]=='*')
				{
					b[i][j]=1;
					f=1;
				}
			}
		}
		if(f==0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		ll flag=0;
		for(ll i=1;i<h-1;++i)
		{
			for(ll j=1;j<w-1;++j)
			{
				if(a[i][j]=='*' && a[i-1][j]=='*' && a[i+1][j]=='*' && a[i][j-1]=='*' && a[i][j+1]=='*')
				{
					ll k=i;
					while(k>=0 && b[k][j])
					{
						b[k][j]=0;
						k--;
					}
					k=i+1;
					while(k<h && b[k][j])
					{
						b[k][j]=0;
						k++;
					}
					k=j-1;
					while(k>=0 && b[i][k])
					{
						b[i][k]=0;
						k--;
					}
					k=j+1;
					while(k<w && b[i][k])
					{
						b[i][k]=0;
						k++;
					}
					flag=1;
					break;
				}

			}
			if(flag)
					break;
		}

		flag=0;
		for(ll i=0;i<h;++i)
		{
			for(ll j=0;j<w;++j)
			{
				if(b[i][j]==1)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
}