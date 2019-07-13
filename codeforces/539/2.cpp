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
vector<vector<ll> > v(101);
void primeFactors(ll n) 
{ 
    // Print the number of 2s that divide n 
    ll k=n;
    while (n%2 == 0) 
    { 
        // printf("%d ", 2); 
        v[k].pb(2);
        n = n/2; 
    } 
  
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (ll i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            // printf("%d ", i);
            v[k].pb(i); 
            n = n/i; 
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) 
        // printf ("%d ", n); 
        v[k].pb(n);
} 
void printDivisors(ll n) 
{ 
    // Note that this loop runs till square root 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                // printf("%d ", i);
                v[n].pb(i); 
  
            else // Otherwise print both 
                // printf("%d %d ", i, n/i);
                {
                	v[n].pb(i);
                	v[n].pb(n/i);
                } 
        } 
    } 
} 
int main()
{
	ll t;
	// cin>>t;
	t=1;
	for(ll i=100;i>=2;--i)
	{
		printDivisors(i);
	}
	// for(ll i=100;i>=2;--i)
	// {
	// 	for(ll j=0;j<v[i].size();++j)
	// 	{
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	while(t--)
	{
		ll n;
		cin>>n;
		vi a(n);
		ll ans=0;
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			ans+=a[i];
			// cout<<ans<<" ";
		}
		sort(a.begin(), a.end());
		ll fix=ans;
		for(ll i=n-1;i>0 && a[i]>1;--i)
		{
			for(ll j=0;j<v[a[i]].size();++j)
			{
				ans=min(ans,fix-a[i]+a[i]/v[a[i]][j]-a[0]+a[0]*v[a[i]][j]);
				// cout<<ans<<" ";
			}
		}
		cout<<ans<<endl;
	}
}