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
ll nextPowerOf2(ll n)  
{  
    ll count = 0;    
    if (n && !(n & (n - 1)))  
        return n;  
      
    while( n != 0)  
    {  
        n >>= 1;  
        count += 1;  
    }  
      
    return (ll)pow(2,count);  
}  
ll cal(ll r)
{
	ll terms=nextPowerOf2(r)-1;
	// cout<<terms<<endl;
	if(r>terms)
		terms=nextPowerOf2(r)*2-1;
	ll even=0,odd=0,i,k,j;
	for(i=1,k=0,j=1;k<terms;i*=2,j++)
	{
		if(j%2)
		{
			odd+=i;
		}
		else
		{
			even+=i;
		}
		k+=i;
	}
	j--;
	if(j%2)
	{
		odd-=(terms-r);
	}
	else
	{
		even-=(terms-r);
	}
	// cout<<odd<<" "<<even;
	ll sum=0;
	sum=((((even+1)%mod)*(even%mod))%mod+(((odd)%mod)*(odd%mod))%mod)%mod;
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t=1;
	// cin>>t;
	while(t--)
	{
		ll l,r;
		cin>>l>>r;
		// cal(r);
		ll res=cal(r)-cal(l-1);
		if(res<0)
			res+=mod;
		cout<<res<<endl;
	}
}
