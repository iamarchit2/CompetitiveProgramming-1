//https://www.hackerearth.com/challenge/competitive/may-circuits-18/algorithm/counting-bipartite-graphs-b7517e70/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int nCr(int n,int r)
{
	if(n==r)
		return 1;
	if(r==1)
		return n;
	return nCr(n-1,r)+nCr(n-1,r-1);
}
int main()
{
	ll n,m;
	cin>>n>>m;
	vector<vector<ll> > a(n,vector<ll>(m,0));
	for(ll i=0;i<n;++i)
	{
		a[i][0]=1;
	}
	for(ll j=0;j<m;++j)
	{
		a[0][j]=1;
	}
	for(ll i=1;i<n;++i)
	{
		for(ll j=i;j<m;++j)
		{
			a[i][j]+=a[i][j-1]*(pow(2,n)-1);
			ll k=1;
			while(k<=i)
			{
				a[i][j]+=a[i-k][j-1]*pow(2,n-k)*nCr(n,k);
				k++;
			}
			a[j][i]=a[i][j];
		}
	}
	cout<<a[n-1][m-1];
}