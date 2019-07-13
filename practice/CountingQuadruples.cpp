// https://www.hackerearth.com/challenge/competitive/may-circuits-18/algorithm/counting-quadruples-of-points-26250f44/
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
double dist(ll i,ll j,vector<pair<double,double> > &a)
{
	return sqrt((a[i].f-a[j].f)*(a[i].f-a[j].f) + (a[i].s-a[j].s)*(a[i].s-a[j].s));
}
bool f(ll p,ll q,ll r,ll s,vector<pair<double,double> > &a)
{
	if(dist(p,q,a)-dist(q,r,a)+dist(r,s,a)-dist(s,p,a)<=0.0001)
		return true;
	else
		return false; 	
}
int main()
{
	ll n;
	cin>>n;
	vector<pair<double,double> > a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].f>>a[i].s;
	}
	// vector<double> distance;
	// double temp;
	// for(ll i=0;i<n;++i)
	// {
	// 	for(ll j=i+1;j<n;++j)
	// 	{
	// 		temp=sqrt((a[i].f-a[j].f)*(a[i].f-a[j].f) + (a[i].s-a[j].s)*(a[i].s-a[j].s));

	// 	}
	// }
	ll count=0;
	for(ll i=0;i<n-3;++i)
	{
		for(ll j=i+1;j<n-2;++j)
		{
			for(ll k=j+1;k<n-1;++k)
			{
				for(ll l=k+1;l<n;++l)
				{
					if(f(i,j,k,l,a))
					{
						if()
					}
				}
			}
		}
	}
	cout<<count<<endl;
}