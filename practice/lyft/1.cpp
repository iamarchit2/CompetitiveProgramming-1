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
	ll n;
	cin>>n;
	ll ax,ay,bx,by,cx,cy;
	cin>>ax>>ay>>bx>>by>>cx>>cy;
	if(bx<ax && cx<ax)
	{
		if((by<ay && cy<ay) || (by>ay && cy>ay))
		{
			cout<<"YES"<<endl;
			exit(0);
		}
	}
	else if(bx>ax && cx>ax)
	{
		if((by<ay && cy<ay) || (by>ay && cy>ay))
		{
			cout<<"YES"<<endl;
			exit(0);
		}
	}
	cout<<"NO"<<endl;
}