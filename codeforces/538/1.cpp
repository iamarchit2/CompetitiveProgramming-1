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
	ll x,y,z;
	cin>>x>>y>>z;
	ll a,b,c;
	int t=1;
	cin>>a>>b>>c;
	if(a>=x)
	{
		a-=x;
		if((a+b)>=y)
		{
			ll d=a+b-y;
			if((c+d)>=z)
			{
				cout<<"YES"<<endl;
				exit(0);
			}
		}
	}
	cout<<"NO"<<endl;

}
