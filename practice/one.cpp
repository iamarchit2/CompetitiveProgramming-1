#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n,h,a,b,k;
	cin>>n>>h>>a>>b>>k;
	while(k--)
	{
		ll ta,fa,tb,fb;
		ll ans=0;
		cin>>ta>>fa>>tb>>fb;
		if(ta==tb)
		{
			ans+=abs(fb-fa);
		}
		else if(fa<a)
		{
			ans+=a-fa;
			ans+=abs(tb-ta);
			ans+=abs(fb-a);
		}
		else if(fa>b)
		{
			ans+=fa-b;
			ans+=abs(tb-ta);
			ans+=abs(b-fb);
		}
		else
		{
			ans+=abs(tb-ta);
			ans+=abs(fb-fa);
		}
		cout<<ans<<endl;
	}
}