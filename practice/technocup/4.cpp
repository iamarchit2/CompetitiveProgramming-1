#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define f first
// #define s second
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
	ll n,m,k;
	cin>>n>>m>>k;
	ll t=n*m*2;
	if(t%k!=0)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	t/=k;
	if(t>n*m)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	ll temp=0;
	ll base,height;
	ll i=n;
	while(i>=2)
	{
		temp=0;
		if(t%i==0 && t/i<=m)
		{
			temp=1;
			base=i;
			height=t/i;
			break;
		}
		if(t/i>m)
		{
			temp=0;
			break;
		}
		i--;
	}
	if(temp==0)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	else
	{
		cout<<"YES"<<endl;
		cout<<"0 0"<<endl;
		cout<<"0 "<<height<<endl;
		cout<<base<<" 0"<<endl;
	}
}