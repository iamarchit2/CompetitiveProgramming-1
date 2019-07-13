#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		map<char,ll> m;
		ll k=1;
		for(char c='A';c<='Z';++c,k++)
		{
			m[c]=k;
		}
		ll ans=0;
		for(ll i=0;i<a.size();++i)
		{
			ll x;
			if(b[i]>=a[i])
			{
				x=m[b[i]]-m[a[i]];
			}
			else
			{
				x=26-m[a[i]]+m[b[i]];
			}
			ans+=x/13+x%13;
		}
		cout<<ans<<endl;
	}
}