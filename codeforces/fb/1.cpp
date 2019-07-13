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
	ll k=1;
	cin>>t;
	while(t--)
	{
		string a;
		cin>>a;
		ll n=a.size();
		ll B=count(a.begin(), a.end(),'B');
		// cout<<B<<endl;
		ll minB=0;
		ll maxB=n-2;
		ll i;
		for(i=2;i<=n-1;i+=2)
		{
			minB++;
		}
		if((n-1)%2)
			minB++;
		// cout<<B<<" "<<minB<<" "<<maxB<<endl;
		if(B>=minB && B<=maxB)
			cout<<"Case #"<<k<<": Y"<<endl;
		else
		{
			minB=2;
			if(B>=minB && B<=maxB)
				cout<<"Case #"<<k<<": Y"<<endl;
			else
				cout<<"Case #"<<k<<": N"<<endl;
		}
		k++;
	}
}
