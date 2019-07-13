#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
void f(ll &ctr,ll i,ll j,string dir,vector<string> a,vector<vector<ll> > vis)
{	
	if(i==2 && j==a[0].size()-1 && dir=="u")
	{
		ctr++;
		return;
	}
	vis[i][j]=1;
	if(dir=="l" || dir=="r")
	{
		if(i-1>=0) 
		{
			if(!vis[i-1][j] && a[i-1][j]=='.')
			{
				dir="d";
				f(ctr,i-1,j,dir,a,vis);
			}
		}
		if(i+1<=2)
		{
			if(!vis[i+1][j] && a[i+1][j]=='.')
			{
				dir="u";
				f(ctr,i+1,j,dir,a,vis);
			}
		}	
	}
	else if(dir=="u" || dir=="d")
	{
		if(j-1>=0) 
		{
			if(!vis[i][j-1] && a[i][j-1]=='.')
			{
				dir="r";
				f(ctr,i,j-1,dir,a,vis);
			}
		}
		if(j+1<a[0].size())
		{
			if(!vis[i][j+1] && a[i][j+1]=='.')
			{
				dir="l";
				f(ctr,i,j+1,dir,a,vis);
			}
		}	
	}
}
int main()
{
	ll t;
	cin>>t;
	vector<ll> ans;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<string> a(3);
		for(ll i=0;i<3;++i)
			cin>>a[i];
		// vector<vector<ll> > l(3,vector<ll>(a[0].size())),r(3,vector<ll>(a[0].size()));
		// vector<vector<ll> > u(3,vector<ll>(a[0].size())),d(3,vector<ll>(a[0].size()));
		vector<vector<ll> > vis(3,vector<ll>(a[0].size()));
		ll ctr=0;
		string dir="l";
		f(ctr,0,0,dir,a,vis);
		ans.push_back(ctr);
	} 
	for(ll i=0;i<ans.size();++i)
	{
		cout<<ans[i]<<endl;
	}
}