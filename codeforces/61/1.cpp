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

int main()
{
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	if( a==d )
	{
		if(c==0)
			cout<<1<<endl;
		else if(a>=1)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
	else
		cout<<0<<endl;
}
