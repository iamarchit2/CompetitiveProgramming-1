#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
struct Node {
    long long num_ones_subarrays;
    int len, len_ones_left, len_ones_right;
};

Node merge(Node i,Node j)
{
	Node temp;
	temp.len=i.len+j.len;
	temp.num_ones_subarrays=i.num_ones_subarrays+j.num_ones_subarrays+i.len_ones_right*j.len_ones_left;
	if(i.len_ones_left==i.len)
	{
		temp.len_ones_left=i.len+j.len_ones_left;
	}
	else
	{
		temp.len_ones_left=i.len_ones_left;
	}
	if(j.len_ones_right==j.len)
	{
		temp.len_ones_right=j.len+i.len_ones_right;
	}
	else
	{
		temp.len_ones_right=j.len_ones_right;
	}
	return temp;
}
void build(vector<Node> &tree)
{
	ll n=tree.size()/2;
	for(size_t i=0;i<n;++i)
	{
		tree[i+n].num_ones_subarrays=tree[i+n].len_ones_right=tree[i+n].len_ones_left=tree[i+n].len=1;
	}
	for(size_t i=n-1;i>0;--i)
	{
		tree[i]=merge(tree[2*i],tree[2*i+1]);
	}
}
void update(vector<Node> &tree,ll index,ll newValue,ll temp)
{
	
	ll n=(tree.size())/2;
	if(newValue>=temp)
	{
		ll i=index+n;
		tree[i].num_ones_subarrays=tree[i].len_ones_right=tree[i].len_ones_left=0;
	}
	else
	{
		ll i=index+n;
		tree[i].num_ones_subarrays=tree[i].len_ones_right=tree[i].len_ones_left=1;
	}
	for(ll i=index+n;i>1;i=i/2)
	{
		tree[i/2]=merge(tree[i],tree[i+1]);
	}
}
ll query(vector<Node> &tree,ll l,ll r )
{
	l=l-1;
	ll n=(tree.size())/2,ctr=0;
	Node res;
    
   	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
   	{
      	if (l&1) 
       	{
       		if(ctr==0)
       		{
       			res=tree[l++];
       			ctr++;
        	}
        	else
           		res = merge(res,tree[l++]);
        }
        if (r&1) 
	    {
   	    	if(ctr==0)
       		{
       			res=tree[--r];
       			ctr++;
       		}	
           	else
           		res = merge(res,tree[--r]);
       	}
    }
     
   	return res.num_ones_subarrays;
}
void print(vector<Node> a)
{
	for(ll i=0;i<a.size();++i)
		cout<<a[i].num_ones_subarrays<<" ";
	cout<<endl;
}
int main()
{
	ll n,q,L,R;
	cin>>n>>q>>L>>R;
	vector<Node> a(2*n),b(2*n);
	build(a);
	b=a;
	print(a);
	while(q--)
	{
		int qury;
		cin>>qury;
		if(qury==1)
		{
			ll x,y;
			cin>>x>>y;
			update(a,x-1,y,R+1);
			update(b,x-1,y,L);
			print(a);
			print(b);
		}
		else
		{
			ll l,r;
			cin>>l>>r;
			ll ans=query(a,l,r)-query(b,l,r);
			cout<<ans<<endl;
		}
	}
}