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
	while(t--)
	{
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if(x1!=x2 && y1!=y2)
		{
			cout<<"sad"<<endl;
		}
		else if(x1==x2)
		{
			if(y2>y1)
			{
				cout<<"up"<<endl;
			}
			else
			{
				cout<<"down"<<endl;
			}
		}
		else
		{
			if(x2>x1)
			{
				cout<<"right"<<endl;
			}
			else
			{
				cout<<"left"<<endl;
			}
		}
	}
}