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
	vi a(180,0);
	ll ctr=0;
	ll s=3;
	while(s<=180)
	{
		double ang=180.0/s;
		double mina=ang;
		double maxa=ang*(s-2.0);
		// if(ang==0)
		// 	break;
		// cout<<ang;
		while(ang<=maxa)
		{
			if(ang==(ll)ang && a[ang]==0)
			{
				a[ang]=s;
				ctr++;
			}
			ang+=mina;
			// cout<<ang<<" "<<s-2<<endl	;
		}
		// cout<<ctr;
		s++;
	}
	// cout<<ctr;
	// cout<<endl;
	// for(ll i=1;i<=179;++i)
	// 	cout<<a[i]<<endl;
	a[179]=360;
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<a[n]<<endl;
	}
}