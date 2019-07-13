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
int main()
{
	ll n;
	cin>>n;
	if(n%3==0)
	{
		cout<<1<<" "<<1<<" "<<n-2<<endl;
	}
	else
	{
		cout<<1<<" "<<2<<" "<<n-3<<endl;
	}
}