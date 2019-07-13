#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second 

int main()
{
	ll t,x=1;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		multiset <ll, greater <ll> > m;
		m.insert(n);
		while(--k)
		{
			ll a=*m.begin();
			if(a%2==0)
			{
				m.insert(a/2);
				m.insert(a/2-1);
			}
			else
			{
				m.insert(a/2);
				m.insert(a/2);
			}
			m.erase(m.begin());
		}
		ll a=*m.begin();
		if(a%2==0)
		{
			cout<<"Case #"<<x<<":"<<" "<<a/2<<" "<<a/2-1<<endl;
		}
		else
		{
			cout<<"Case #"<<x<<":"<<" "<<a/2<<" "<<a/2<<endl;
		}
		x++;
	}
}