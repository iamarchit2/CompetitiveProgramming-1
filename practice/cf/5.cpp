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

bool isSubset(vi arr1, vi arr2, ll m, ll n) 
{ 
    ll i = 0, j = 0; 
      
    if (m < n) 
       return 0; 
  
    // sort(arr1., arr1 + m); 
    // sort(arr2, arr2 + n); 
    while (i < n && j < m ) 
    { 
        if( arr1[j] <arr2[i] ) 
            j++; 
        else if( arr1[j] == arr2[i] ) 
        { 
            j++; 
            i++; 
        } 
        else if( arr1[j] > arr2[i] ) 
            return 0; 
    } 
   
    return  (i < n)? false : true; 
}  


int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t=1;
	// cin>>t;
	while(t--)
	{
		ll m,n;
		cin>>m>>n;
		// vi a(n);
		vector<vector<ll> > a,c;
		for(ll i=0;i<m;++i)
		{
			ll s;
			cin>>s;
			vi b(s);
			for(ll j=0;j<s;++j)
			{
				cin>>b[j];
			}
			sort(b.begin(), b.end());
			a.pb(b);
			// cin>>a[i];
		}
		for(ll i=0;i<m;++i)
		{
			vi b;
			for(ll j=1,k=0;j<=n;++j)
			{
				if(k>=a[i].size())
					b.pb(j);
				if(a[i][k]!=j)
				{
					b.pb(j);
				}
				else
				{
					k++;
				}
			}
			c.pb(b);
		}
		ll f=0;
		for(ll i=0;i<m;++i)
		{
			for(ll j=0;j<m;++j)
			{
				if(isSubset(c[j],a[i],c[j].size(),a[i].size()))
				{
					f=1;
					break;
				}
			}
		}
		if(f)
		{
			cout<<"impossible"<<endl;
		}
		else
		{
			cout<<"possible"<<endl;
		}
	}
}
