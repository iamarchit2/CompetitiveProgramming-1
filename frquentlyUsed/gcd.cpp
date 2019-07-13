#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	ll q;
	cin>>q;
	while(q--)
	{
		int ch;
		cin>>ch;
		if(ch==1)
		{
			ll x,y;
			cin>>x>>y;
			a[x-1]=y;
		}
		else
		{
			ll l,r,g;
			cin>>l>>r>>g;
			ll count=0;
			for(ll i=l-1;i<=r-1;++i)
			{
				if( __gcd(a[i],g)==1 )
					count++;
			}
			cout<<count<<endl;
		}
	}
}\]
'/'