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
vi a;
void primeFactors(ll n) 
{ 
    // Print the number of 2s that divide n 
    while (n%2 == 0) 
    { 
        // printf("%d ", 2);
        a.pb(2); 
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
            a.pb(i);
            n = n/i; 
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) 
        // printf ("%d ", n); 
        a.pb(n);
} 
int main()
{
	ll n,b;
	cin>>n>>b;
	primeFactors(b);

	sort(a.begin(),a.end());
	ll c=1;
	ll i=a.size()-2;
	while( a[i]==a[a.size()-1])
	{
		c++;
		i--;
		// cout<<i;
	}
	ll count = 0; 
  
    // Keep dividing n by powers of  
    // 5 and update count 
    for (ll i = a[a.size()-1]; n / i >= 1; i *= a[a.size()-1] ) 
        count += n / i; 
    ans=count/c;
    if()
    cout<<count<<endl;
}
