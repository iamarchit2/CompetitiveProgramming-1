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
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string x;
		cin>>x;
		ll temp=0;
		for(ll int i=0;i<x.size();++i)
		{
			if(x[i]!=x[0])
			{
				temp=1;
				ll te=x[i];
				x[i]=x[x.size()-1];
				x[x.size()-1]=te;
				break;
			}
		}
		if(temp)
		{
			cout<<x<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
}