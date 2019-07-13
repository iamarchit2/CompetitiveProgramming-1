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
	ll n,m;
	cin>>n>>m;
	vector<vi> a(n,vi(m)),b(n,vi(m));
	um ua;
	for(ll i=0;i<n;++i)
	{
		for(ll j=0;j<m;++j)
		{
			cin>>a[i][j];
			ua[a[i][j]]++;
		}
	}
	for(ll i=0;i<n;++i)
	{
		for(ll j=0;j<m;++j)
		{
			cin>>b[i][j];
			// ub[b[i][j]]++;
			if(ua[b[i][j]]<=0)
			{
				cout<<"NO"<<endl;
				exit(0);
			}
			ua[b[i][j]]--;
		}
	}
	for(ll i=0;i<n;++i)
	{
		for(ll j=0;j<m;++j)
		{
			if(ua[a[i][j]]!=0)
			{
				cout<<"NO"<<endl;
				exit(0);
			}
		}
	}
	for(ll i=0;i<n;++i)
	{
		for(ll j=0;j<m;++j)
		{
			if(a[i][j]==b[i][j])
			{
				continue;
			}
			ll k=1,flag=0;
			while(j-k>=0 && i+k<n)
			{
				if(b[i][j]==a[i+k][j-k])
				{
					ll temp=a[i][j];
					a[i][j]=a[i+k][j-k];
					a[i+k][j-k]=temp;
					flag=1;
					break;
				}
				k++;
			}
			if(flag==0)
			{
				cout<<"NO"<<endl;
				exit(0);
			}
		}
	}
	cout<<"YES"<<endl;
}

