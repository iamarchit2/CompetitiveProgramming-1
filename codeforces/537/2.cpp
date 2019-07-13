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
	ll n,k,m;
	cin>>n>>k>>m;
	vi a(n);
	REP(i,0,n)
	{
		cin>>a[i];
	}
	double ans=0.0;
	sort(a.begin(),a.end());
	
	{
		ll sum=0;
		REP(i,0,n)
		{
			sum+=a[i];
		}
		ans=((sum+min(m,k*n))*1.0)/(n*1.0);
		vi b(n);
		REP(i,0,n)
		{
			sum-=a[i];
			b[i]=sum;
		}
		REP(i,0,min(m,n-1))
		{
			double avg=((b[i]+min((m-i-1),k*(n-i-1)))*1.0)/((n-i-1)*1.0);
			ans=max(ans,avg);
		}
	}
	cout<<setprecision(10)<<ans<<endl;
}
