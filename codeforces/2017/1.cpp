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
int comp(vector<vi> a,ll x,ll y)
{
	if(a[x]==a[y])
		return 0;
	ll p=0,q=0;
	for(ll i=0;i<3;++i)
	{
		if(a[x][i]>a[y][i])
			p=1;
		else if(a[x][i]<a[y][i])
			q=1;
	}
	if(p==1 && q==1)
		return 0;
	else return 1;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		vector<vi> a(3,vi(3));
		for(ll i=0;i<3;++i)
		{
			for(ll j=0;j<3;++j)
			{
				cin>>a[i][j];
			}
		}
		if(comp(a,0,1)==1 && comp(a,1,2)==1 && comp(a,2,0)==1)
		{
			cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
	}
	
}