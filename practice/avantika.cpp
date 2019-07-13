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
int range_query(vector<set<ll> >& st, ll left, ll right, ll n) 
{ 
    /*  Basically the left and right indices will move 
        towards right and left respectively and with 
        every each next higher level and compute the  
        minimum at each height. */
    // change the index to leaf node first 
    left += n; 
    right += n; 
  
    // initialize minimum to a very high value 
    // int mi = (int)1e9; 
    ll mi=0;
    while (left < right) { 
  
        // if left index in odd 
        if (left & 1) { 
            // mi = min(mi, segtree[left]);
            set<ll>::iterator it; 
            ll k=1;
  			for(it=st[left].begin();it!=st[left].end();++it,k++)
  			{
  				mi+=k*(*it);
  			}
            // make left index even 
            left++; 
        } 
  
        // if right index in odd 
        if (right & 1) { 
  
            // make right index even 
            right--; 
            set<ll>::iterator it;
            ll k=1; 
  			for(it=st[right].begin();it!=st[right].end();++it,k++)
  			{
  				mi+=k*(*it);
  			}
  
            // mi = min(mi, segtree[right]); 
        } 
  
        // move to the next higher level 
        left /= 2; 
        right /= 2; 
    } 
    return mi; 
} 
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vi a(n);
		vector<set<ll> > st(2*n);
		
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		for (ll i = 0; i < n; i++)  
        {
        	set<ll> temp;
        	temp.insert(a[i]);
        	st[n + i]=temp;
        }
        for (ll i = n - 1; i >= 1; i--) 
        {
        	// st[i] = min(st[2 * i],st[2 * i + 1]); 
        	set<ll> temp;
        	set<ll>::iterator it;
        	for(it=st[2*i].begin();it!=st[2*i].end();++it)
        	{
        		temp.insert(*(it));
        	}
        	for(it=st[2*i+1].begin();it!=st[2*i+1].end();++it)
        	{
        		temp.insert(*(it));
        	}
        	st[i]=temp;
        }
		ll m;
		cin>>m;
		while(m--)
		{
			ll l,r;
			cin>>l>>r;
			cout<<range_query(st, l-1,r , n)<<endl;
		}
	}
}