#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void buildtree(vector<int> &arr,vector<ll> &tree,ll n)
{
	for(int i=0;i<n;++i)
	{
		if(arr[i]==0)
		{
			tree[n+i]=1;
		}
		else
			tree[n+i]=0;
	}
	for (int i = n - 1; i > 0; --i)     
        tree[i] = tree[i<<1] + tree[i<<1 | 1];
        
}	
int query(vector<ll> &tree,ll l, ll r,ll n) 
{ 
    int res = 0;
     
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) 
            res += tree[l++];
     
        if (r&1) 
            res += tree[--r];
    }
     
    return res;
}
// ll zero(vector<ll> &tree,ll start,ll end,ll index,ll a,ll b)
// {
// 	ll mid=(start+end)/2;
// 	if(start>=a && b>=end)
// 		return tree[index];
// 	if(a>end || start>b)
// 		return 0;
// 	return zero(tree,start,mid,2*index,a,b)+zero(tree,mid+1,end,2*index+1,a,b);
// }
int main()
{
	ll n,q;
	cin>>n>>q;
	vector<ll> a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	vector<vector<int> > b(31,vector<int>(n,0));
	for(ll i=0;i<n;++i)
	{
		int j=0;
		while(a[i]>0)
		{
			b[j][i]=a[i]%2;
			a[i]=a[i]/2;
			j++;
		}
	}
	vector<vector<ll> > t(31,vector<ll>(2*n));
	for(int i=0;i<31;++i)
	{
		buildtree(b[i],t[i],n);
	}
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		vector<int> ans(31);
		for(int i=0;i<31;++i)
		{
			ll count0=query(t[i],l-1,r,n);
			ll count1=r-l+1-count0;
			if(count0>count1)
			{
				ans[i]=1;
			}
			else
			{
				ans[i]=0;
			}
		}
		ll result=0;
		for(int i=0;i<31;++i)
		{
			result+= ans[i]*pow(2,i);
		}
		cout<<result<<endl;
	}
}