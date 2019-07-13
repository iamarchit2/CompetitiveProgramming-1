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

void SieveOfEratosthenes(ll n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    vector<bool> prime(n+1,true); 
     
  
    for (ll p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p 
            for (ll i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
   ll ans=0;
    // Print all prime numbers 
    for (ll p=2; p<=n; p++) 
       if (prime[p]) 
          ans++;
    cout<<ans<<endl;       
} 
  
// Driver Program to test above function 
int main() 
{ 
    // ll n = 1000000000; 
    // cout << "Following are the prime numbers smaller "
    //      << " than or equal to " << n << endl; 
    // SieveOfEratosthenes(n); 
    // return 0; 
    // // unordered_map<ll,unordered_set<ll> > u;
    // set<ll> a,b,c;
    // set<ll>::iterator it;
    // a.insert(3);
    // b.insert(6);
    // vector<ll> a(1),b(1),c(2);
    // a[0]=3;b[0]=6;
    // merge(a.begin(),a.end(),b.begin(),b.end(),c.begin());
    // cout<<*(c.begin())<<" "<<c.size();
    cout<<10287648000%mod;
} 
// int main()
// {
// 	// ll t;
// 	// cin>>t;
// 	// while(t--)
// 	// {
// 	// 	ll n;
// 	// 	cin>>n;
// 	// 	vi a(n);
// 	// 	for(ll i=0;i<n;++i)
// 	// 	{
// 	// 		cin>>a[i];
// 	// 	}
// 	// }
// 	for(ll i=0;i<200;++i)
// 	{
// 		for(ll i=0)
// 	}

// }