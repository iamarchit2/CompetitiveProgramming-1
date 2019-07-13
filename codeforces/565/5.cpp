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
#define sort(a) sort(a.begin(),a.end())
void print1D(vi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
}
void print2D(vector<vi> a)
{
	for(ll i=0;i<a.size();++i)
	{
		for(ll j=0;j<a[i].size();++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
vi pr;
void SieveOfEratosthenes(ll n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    // bool prime[n+1]; 
    vector<bool> prime(n+1,true);
    // memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (ll p=2; p<=n; p++) 
       if (prime[p]) 
          // cout << p << " "; 
       		pr.pb(p);
} 
#define MAXN 200001
vi spf(MAXN);
void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (ll j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
bool isprime(ll k)
{
	for(ll i=2;i<=sqrt(k);++i)
	{
		if(k%i==0)
			return false;
	}
	return true;
}
int main()
{
	SieveOfEratosthenes(2750131);
	sieve();
	// cout<<spf[81];
	// cout<<pr.size();
	ll t=1;
	// cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vi b(2*n),a;
		for(ll i=0;i<2*n;++i)
		{
			cin>>b[i];
		}
		sort(b);
		for(ll i=2*n-1;i>=0;)
		{
			if(!isprime(b[i]))
			{
				ll k=b[i]/spf[b[i]];
				ll j=lower_bound(b.begin(), b.end(),k)-b.begin();
				a.pb(b[i]);
				// b.erase(b.begin()+i);
				b.erase(b.begin()+j);
				i-=2;
			}
			else
			{
				i--;
			}
		}
		// print1D(b);
		// cout<<pr[1]<<endl;
		for(ll i=0;i<b.size();)
		{
			ll k=lower_bound(b.begin(), b.end(),pr[b[i]-1])-b.begin();
			if(k==b.size())
			{
				i++;
				continue;
			}
			// cout<<b[k]<<" ";
			if(pr[b[i]-1]==b[k])
			{
				a.pb(b[i]);
				// b.erase(b.begin()+i);
				b.erase(b.begin()+k);
				i++;
				// if(i+1!=k)
				// 	i++;
			}
			else
				i++;
		}
		print1D(a);
		cout<<endl;
	}
}