#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
unordered_map<ll,ll> u,ub;
ll gr1=0,ls1=0,gr2=0,ls2=0,ind;
void binary(ll x,vector<ll> &a,ll l,ll h)
{
	ll mid=l+(h-l)/2;
	if(l>h)
		return;
	if(a[mid]==x)
		return;
	if(a[mid]>x)
	{
		if(ind<mid)
		{
			h=mid-1;
			gr1++;
		}
		else
		{
			l=mid+1;
			gr2++;
		}
	}
	else
	{
		if(ind>mid)
		{
			l=mid+1;
			ls1++;
		}
		else
		{
			h=mid-1;
			ls2++;
		}
	}
	binary(x,a,l,h);
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		vector<ll> a(n+1), b(n+1);
		for(ll i=1;i<=n;++i)
		{
			cin>>a[i];
			u[a[i]]=i;
		}
		b=a;
		sort(b.begin(),b.end());
		for(ll i=1;i<=n;++i)
		{
			ub[b[i]]=i;
		}
		while(q--)
		{
			ll x;
			cin>>x;
			ind=u[x];
			gr1=ls1=gr2=ls2=0;
			binary(x,a,1,n);
			ll swp=0;
			if(gr2==ls2)
			{
				swp=gr2;
			}
			else if(gr2>ls2)
			{
				swp+=ls2;
				gr2-=ls2;
				ls2+=ls1;
				ll ls=ub[x]-1;
				ls-=ls2;
				if(ls>=gr2)
				{
					swp+=gr2;
				}
				else
					swp=-1;
			}
			else
			{
				swp+=gr2;
				ls2-=gr2;
				gr2+=gr1;
				ll gr=n-ub[x];
				gr-=gr2;
				if(gr>=ls2)
				{
					swp+=ls2;
				}
				else
					swp=-1;
			}
			cout<<swp<<endl;
		}
	}
}