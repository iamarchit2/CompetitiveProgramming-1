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
#define MAXN 1000001 
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

// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
vector<ll> getFactorization(ll x) 
{ 
	vector<ll> ret; 
	while (x != 1) 
	{ 
		ret.push_back(spf[x]); 
		x = x / spf[x]; 
	} 
	return ret; 
} 


int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	sieve();
	ll t=1;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vi a(n);
		um u;
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			vector <ll> p = getFactorization(a[i]);
			// print1D(p);
			// cout<<endl;
			sort(p.begin(), p.end());
			ll c=1,j;
			for(j=1;j<p.size();++j)
			{
				if(p[j]==p[j-1])
					c++;
				else
				{
					u[p[j-1]]=max(u[p[j-1]],c);
					c=1;
				}
			} 
			u[p[j-1]]=max(u[p[j-1]],c);
		}
		// if(n==1)
		// {
		// 	cout<<a[0]*a[0]<<endl;
		// 	continue;
		// }
		ll ans=1;
		ll count=1;
		unordered_map<ll,ll>::iterator it=u.begin();
		if(u.size()==1)
			it->second++;
		for(it=u.begin();it!=u.end();++it)
		{
			// cout<<it->first<<" "<<it->second<<endl;
			// if((it->second)%2==1)
				// it->second++;
			ans*=(ll)pow(it->first,it->second);
			count*=(it->second+1);
		}
		sort(a.begin(),a.end());
		if((count-2)==n && ans!=a[n-1])
		{
			cout<<ans<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
}

