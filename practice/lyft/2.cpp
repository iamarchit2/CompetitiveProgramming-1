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
bool isPrime(ll n) 
{ 
    // Corner case 
    if (n <= 1)  return false; 
  
    // Check from 2 to n-1 
    for (ll i=2; i<sqrt(n); i++) 
        if (n%i == 0) 
            return false; 
  
    return true; 
} 
int main()
{
	ll n;
	cin>>n;
	while(n--)
	{
		ll a,b;
		cin>>a>>b;
		ll x=a-b;
		ll y=a+b;
		if(x==1)
		{
			if(isPrime(y))	
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
}