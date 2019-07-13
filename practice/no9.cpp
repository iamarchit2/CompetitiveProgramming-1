#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define m 100000000
bool digit9(ll x)
{
	while(x)
	{
		if((x%10)==9)
			return true;
		x=x/10;
	}
	return false;
}
void build(vector<ll> &a)
{
	for(ll i=0;i<m;++i)
	{
		if((i+1)%9==0 || digit9(i+1))
			a[i+m]=1;
		else
			a[i+m]=0;
	}
	for(ll i=m-1;i>0;--i)
	{
		a[i]=a[2*i]+a[2*i+1];
	}
}
ll query(vector<ll> &tree,ll l,ll r)  //l and r are based on 1-based indexing
{ 
    ll res = 0;
    ll n=(tree.size()+1)/2;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) 
            res += tree[l++];
     
        if (r&1) 
            res += tree[--r];
    }
     
    return res;
}
int main()
{
	ll t,x=1;
	cin>>t;
	vector<ll> a(2*m);
	build(a);
	while(t--)
	{
		ll l,r;
		cin>>l>>r;
		ll ans=query(a,l,r);
		ans=r-l+1-ans;
		cout<<"Case #"<<x<<": "<<ans<<endl;
		x++;
	}
}