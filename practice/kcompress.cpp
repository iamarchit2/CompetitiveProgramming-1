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
		ll n,s;
		cin>>n>>s;
		vector<ll> a(n),b,x(n);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		b=a;
		sort(b.begin(), b.end());
		map<ll,ll> m,q;
		for(ll i=0,p=1;i<n;++i)
		{
			if(m[b[i]]==0)
			{
				m[b[i]]=p;
				p++;
				q[b[i]]=i;
			}
			else
			{
				q[b[i]]++;
			}
		}
		for(ll i=0;i<n;++i)
		{
			x[i]=q[a[i]];
			a[i]=m[a[i]];
		}
		for(ll i=0;i<n;++i)
		{
			cout<<a[i]<<" "<<x[i]<<endl;
		}
		if(accumulate(a.begin(),a.end(),0)<=s)
		{
			cout<<n+1<<endl;
			continue;
		}
		ll k=n-2;
		while(accumulate(a.begin(),a.end(),0)>s)
		{
			
		}
	}
}