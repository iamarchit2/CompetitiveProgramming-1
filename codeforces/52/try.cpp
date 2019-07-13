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