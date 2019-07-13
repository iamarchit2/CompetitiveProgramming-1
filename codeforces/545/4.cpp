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
	ll n;
	cin>>n;
	string x,y;
	cin>>x>>y;
	// um ux;
	vector<vi> ax(27);
	for(ll i=0;i<n;++i)
	{
		if(x[i]=='?')
		{
			// ux[26]++;
			ax[26].pb(i);
		}
		else
		{
			// ux[x[i]-'a']++;
			ax[x[i]-'a'].pb(i);
		}
	}
	vi temp;
	vpi ans;
	for(ll i=0;i<n;++i)
	{
		if(y[i]=='?')
			temp.pb(i);
		else if(ax[y[i]-'a'].size())
		{
			ans.pb({ax[y[i]-'a'][ax[y[i]-'a'].size()-1],i});
			ax[y[i]-'a'].pop_back();
		}
		else if(ax[26].size())
		{
			ans.pb({ax[26][ax[26].size()-1],i});
			ax[26].pop_back();
		}
	}
	ll i=0;
	while(i<=26)
	{
		while(ax[i].size() && temp.size())
		{
			ans.pb({ax[i][ax[i].size()-1],temp[temp.size()-1]});
			ax[i].pop_back();
			temp.pop_back();
		}	
		i++;
	}
	cout<<ans.size()<<endl;
	for(ll i=0;i<ans.size();++i)
	{
		cout<<ans[i].f+1<<" "<<ans[i].s+1<<endl;
	}
}