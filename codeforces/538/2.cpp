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

int main()
{
	ll t;
	t=1;
	while(t--)
	{
		ll n,m,k;
		cin>>n>>m>>k;
		vi a(n),b(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		b=a;
		sort(a.begin(), a.end());
		ll i=n-1,j=0;
		ll ans=0;
		while(j!=m*k)
		{
			ans+=a[i];
			i--;
			j++;
		}
		cout<<ans<<endl;
		ll tmp=a[n-m*k];
		ll p=n-m*k+1;
		ll q=1;
		while(p<n && tmp==a[p])
		{
			q++;
			p++;
		}
		ll c=0,d=0;
		for(ll i=0,j=0;i<n,j<k-1;++i)
		{
			
			// else
			// {
				if(b[i]>tmp)
					c++;
			// }
				if(b[i]==tmp)
				{
					if(d<q)
					{
						d++;
						c++;
					}
				}
				if(c==m)
			{
				j++;
				c=0;
				cout<<i+1<<" ";
			}
		}
	}
}
