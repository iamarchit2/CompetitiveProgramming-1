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
unordered_set<ll> c;
unordered_map<ll,ll> u;
unordered_set<ll> factors(5);
ll findGCD(vector<ll> arr, ll n) 
{ 
    ll result = arr[0]; 
    for (ll i = 1; i < n; i++) 
        result = __gcd(arr[i], result); 
  
    return result; 
} 
void primeFactors(int n) 
{ 
    // Print the number of 2s that divide n 
    ll t=0;
    while (n%2 == 0) 
    { 
    	t=1;
        n = n/2; 
    } 
  if(t==1)
  {
  	c.insert(2);
  	u[2]++;
  }
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        ll t=0;
        while (n%i == 0) 
        { 
        	t=1;
            // printf("%d ", i); 
            n = n/i; 
        } 
        if(t==1)
        {
        	c.insert(i);
        	u[i]++;
        }
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) 
     {   c.insert(n);
    	u[n]++; 
    }
} 
int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n),b;
	
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	ll x=findGCD(a,n);
	
	for(ll i=0;i<n;++i)
	{
		if(a[i]!=1 && a[i]!=x)
		{
			b.pb(a[i]/x);
		}
	}
	if(b.size()==0)
	{
		cout<<"-1";
		exit(0);
	}
	sort(b.begin(), b.end());
	for(ll i=0;i<b.size();++i)
	{
		primeFactors(b[i]);
	}
	unordered_set<ll>::iterator it;
	ll ma=0;
	for(it=c.begin();it!=c.end();++it)
	{
		// cout<<*it<<endl;
		if(u[*it]>ma)
			ma=u[*it];
	}

	cout<<a.size()-ma<<endl;
}
