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
	cout<<endl;
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
int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	SieveOfEratosthenes(200000);
	// cout<<pr.size();
	ll t=1;
	cin>>t;
	while(t--)
	{
		um u;
		ll n;
		cin>>n;
		vi a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			u[a[i]]=1;
		}
		sort(a);
		ll k=1;
		ll x=a[n-1],y=-1;
		ll ans1=a[n-1],ans2=0;
		for(ll i=n-2;i>=0;--i)
		{
			if(x%a[i]!=0)
			{
				if(y==-1 || y%a[i]!=0)
				{
					y=a[i];
					ans1+=a[i];
					k++;
					if(k==3)
						break;
				}
			}
		}
		ll i=0;
		k=0;
		while(i<pr.size() && x/pr[i] && k<3)
		{
			if(x%pr[i]==0 && u[x/pr[i]])
			{
				ans2+=x/pr[i];
				k++;
			}
			i++;
		}
		// cout<<ans1<<" "<<ans2<<endl;
		cout<<max(ans1,ans2)<<endl;
	}
}
