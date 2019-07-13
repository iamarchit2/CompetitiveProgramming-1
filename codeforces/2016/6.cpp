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
ll exponentMod(ll A, ll B) 
{ 
    // Base cases 
    if (A == 0) 
        return 0; 
    if (B == 0) 
        return 1; 
  
    // If B is even 
    ll y; 
    if (B % 2 == 0) { 
        y = exponentMod(A, B / 2)%mod; 
        y = (y * y) % mod; 
    } 
  
    // If B is odd 
    else { 
        y = A % mod; 
        y = (y * exponentMod(A, B - 1) % mod) % mod; 
    } 
  
    return y%mod; 
} 
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,c;
		cin>>n>>c;
		ll x=exponentMod(c,n);
		x=exponentMod(x,n)-1;
		ll y=(x*x)%mod;
		ll z=(y*y)%mod;
		ll p=(y*x)%mod;
		ll q=(z*x)%mod;
		ll ans=(1+(2*x)%mod+(3*y)%mod+(3*p)%mod+(2*z)%mod+q%mod)%mod;
		cout<<ans<<endl;
	}
}