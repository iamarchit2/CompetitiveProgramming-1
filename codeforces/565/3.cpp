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
	ll t=1;
	// cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<vector<ll> > a(45);
		ll x;
		ll ans=n;
		for(ll i=0;i<n;++i)
		{
			cin>>x;
			a[x].pb(i);
		}
		ll i=0,j=0,k=0,l=0,m=0;
		n=0;
		while(ans!=0)
		{
			// if(i<a[42].size() && i<a[23].size() && i<a[16].size() && i<a[15].size() && i<a[8].size() && i<a[4].size() && a[42][i]>a[23][i] && a[23][i]>a[16][i] && a[16][i]>a[15][i] && a[15][i]>a[8][i] && a[8][i]>a[4][i] )
			// {
			// 	ans-=6;
			// 	i++;
			// }
			// else
			// {
			// 	break;
			// }
			while(i<a[42].size() && j<a[23].size() && a[42][i]<a[23][j])
			{
				i++;
			}
			if(i==a[42].size())
				break;
			i++;
			while(j<a[23].size() && k<a[16].size() && a[23][j]<a[16][k])
			{
				j++;
			}
			if(j==a[23].size())
				break;
			j++;
			while(k<a[16].size() && l<a[15].size() && a[16][k]<a[15][l])
			{
				k++;
			}
			if(k==a[16].size())
				break;
			k++;
			while(l<a[15].size() && m<a[8].size() && a[15][l]<a[8][m])
			{
				l++;
			}
			if(l==a[15].size())
				break;
			l++;
			while(m<a[8].size() && n<a[4].size() && a[8][m]<a[4][n])
			{
				m++;
			}
			if(m==a[8].size())
				break;
			if(n==a[4].size())
				break;
			m++;
			n++;
			ans-=6;

		}
		cout<<ans<<endl	;
	}
}