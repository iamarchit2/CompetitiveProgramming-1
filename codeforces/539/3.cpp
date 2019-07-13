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
ll ans=0;
map<pi,ll> m;
void f(vi a,ll x,ll s,ll e)
{
	if(m[mp(s,e)]==1)
	{
		return;
	}
	else
		m[mp(s,e)]=1;
	if(x==0)
	{
		ans++;
		// cout<<s+1<<" "<<e+1;
		// cout<<endl;
	}
	if(e-s+1==2)
		return;
	f(a,x^a[s]^a[s+1],s+2,e);
	f(a,x^a[e]^a[e-1],s,e-2);
	f(a,x^a[s]^a[e],s+1,e-1);
}
long long subarrayXor(vi arr, ll n, ll m) 
{ 
    long long ans = 0; // Initialize answer to be returned 
  
    // Create a prefix xor-sum array such that 
    // xorArr[i] has value equal to XOR 
    // of all elements in arr[0 ..... i] 
    ll* xorArr = new ll[n]; 
  
    // Create map that stores number of prefix array 
    // elements corresponding to a XOR value 
    unordered_map<ll, ll> mp; 
  
    // Initialize first element of prefix array 
    xorArr[0] = arr[0]; 
  
    // Computing the prefix array. 
    for (ll i = 1; i < n; i++) 
        xorArr[i] = xorArr[i - 1] ^ arr[i]; 
  
    // Calculate the answer 
    for (ll i = 0; i < n; i++) { 
        // Find XOR of current prefix with m. 
        ll tmp = m ^ xorArr[i]; 
  
        // If above XOR exists in map, then there 
        // is another previous prefix with same 
        // XOR, i.e., there is a subarray ending 
        // at i with XOR equal to m. 
        ans = ans + ((long long)mp[tmp]); 
  
        // If this subarray has XOR equal to m itself. 
        if (i%2==1 && xorArr[i] == m) 
            ans++; 
  
        // Add the XOR of this subarray to the map 
        // if(i%2==0)
        	mp[xorArr[i]]++; 
    } 
  
    // Return total count of subarrays having XOR of 
    // elements as given value m 
    return ans; 
} 
int main()
{
	ll t;
	// cin>>t;
	t=1;
	while(t--)
	{
		ll n;
		cin>>n;
		vi a(n);
		ll x=0;
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			x=x^a[i];
			// cout<<x;
		}
		if(n%2==0)
		{
			f(a,x,0,n-1);
		}
		else
		{
			ll y=x^a[0],z=x^a[n-1];
			f(a,y,1,n-1);
			f(a,z,0,n-2);
		}
		cout<<ans<<endl;
		// cout<<subarrayXor(a,n,0);
	}
}