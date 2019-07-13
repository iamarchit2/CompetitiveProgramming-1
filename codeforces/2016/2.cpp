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
ll digitsum(ll a)
{
	ll sum=0;
	while(a)
	{
		sum+=a%10;
		a/=10;
	}
	return sum;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll d;
		cin>>d;
		d++;
		do{
			d=digitsum(d);
		}while(d/10);
		cout<<d<<endl;
	}
}