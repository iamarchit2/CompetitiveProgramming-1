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

int main()
{
	ll t;
	cin>>t;
	cout << fixed << setprecision(10);
	while(t--)
	{
		double n,sig;
		cin>>n>>sig;
		if(n==1 && sig!=0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		if(n==1)
		{
			cout<<"0"<<endl;
			continue;
		}
		double a= sig*sig*n*(n/(n-1));
		a=sqrt(a);
		for(ll i=0;i<n-1;++i)
		{
			cout<<0<<" ";
		}
		cout<<a<<endl;
	}
}