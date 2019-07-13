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
#define vpi vector<pi>
vi pr;
void SieveOfEratosthenes(ll n) 
{ 
    vector<bool> prime(n+1,true); 
     
  
    for (ll p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (ll i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (ll p=2; p<=n; p++) 
       if (prime[p]) 
       		pr.pb(p);
} 
  
int main()
{
	ll t;
	cin>>t;
	um u;
	SieveOfEratosthenes(200);
	for(ll i=0;i<pr.size();++i)
	{
		for(ll j=i+1;j<pr.size();++j)
		{
			u[pr[i]*pr[j]]=1;
		}
	}
	while(t--)
	{
		ll n;
		cin>>n;
		ll flag=0;
		for(ll i=1;i<=n/2;++i)
		{
			if(u[i]==1 && u[n-i]==1)
			{
				// cout<<i<<" "<<n-i;
				flag=1;
				break;
			}
		}
		if(flag)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}