#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
set<ll> t;
void primeFactors(ll n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        t.insert(2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            t.insert(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        t.insert(n);
} 
int main()
{
	ll n;
	cin>>n;
	vector<pair<ll,ll> > a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].f>>a[i].s;
	}
	if(n==1)
	{
		cout<<a[0].f;
		exit(0);
	}
	vector<ll> x(4);
	
	x[0]=gcd(a[0].f,a[1].f);x[1]=gcd(a[0].f,a[1].s);x[2]=gcd(a[0].s,a[1].f);x[3]=gcd(a[0].s,a[1].s);
	for(ll i=0;i<4;++i)
	{
		primeFactors(x[i]);
	}
	ll temp=0;
	ll ans=-1;
	set<ll>:: iterator it; 
	for(it=t.begin();it!=t.end();++it)
	{
		temp=0;
		if(*it!=1)
		{
			for(ll i=0;i<n;++i)
			{
				if(a[i].f%(*it)!=0 && a[i].s%(*it)!=0)
				{
					temp=1;
					break;
				}
			}
			if(temp==0)
			{
				ans=*it;
				break;
			}
		}
	}
	cout<<ans<<endl;
}