#include<bits/stdc++.h>
using namespace std;
#define ll long long
void buildtree(vector<int> &arr,vector<int> &tree,int start,int end,int index)
{
	if(start==end)
	{
		tree[index]=arr[start];
		// functionForLeaves(tree,index,arr[start])
		return;
	}
	int mid=(start+end)/2;
	buildtree(arr,tree,start,mid,2*index);
	buildtree(arr,tree,mid+1,end,2*index+1);
	tree[index]=__gcd(tree[2*index]+tree[2*index+1]);
	// functionForNodes(tree,index,tree[2*index],tree[2*index+1]);
}
int sumofrange(vector<int> &tree,int start,int end,int index,int a,int b)
{
	int mid=(start+end)/2;
	if(start>=a && b>=end)
		return tree[index];
	if(a>end || start>b)
		return 0;
	return sumofrange(tree,start,mid,2*index,a,b)+sumofrange(tree,mid+1,end,2*index+1,a,b);
} 
void update(vector<int> &tree,int start,int end,int index,int a,int c,int b)
{
	// if(start==end)
	// {
	// 	if(a==start)
	// 	{
	// 		//tree[index]=b;
	// 		// functionForLeaves(tree,index,b);
	// 	}
	// 	return;
	// }
	// if(a<=end && a>=start)
	// {
	// 	//tree[index]+=b-c;
		
	// 	int mid=(start+end)/2;
	// 	update(tree,start,mid,2*index,a,c,b);
	// 	update(tree,mid,end,2*index+1,a,c,b);
	// }
	
}
int main()
{
	// int n;
	// cin>>n;
	// vector<int> arr(n),tree(2*n);
	// for(int i=0;i<n;++i)
	// {
	// 	cin>>arr[i];
	// }

	// buildtree(arr,tree,0,n-1,1);

	// int a,b;
	// cout<<"range??";
	// cin>>a>>b;
	// cout<<sumofrange(tree,0,n-1,1,a,b);

	// cout<<"index and element for update:";
	// cin>>a>>b;
	// update(tree,0,n-1,1,a,arr[a],b);
	// arr[a]=b;

	ll n,q;
	cin>>n>>q;
	vi a(n),tree(2*n);;
	cin>>a(n);
	for(ll i=0;i<n;++1)
	{
		cin>>a[i];
	}
	buildtree(a,tree,0,n-1,1);
	while(q--)
	{
		ll x;
		cin>>x;
		if(x==1)
		{
			ll p,v;
			cin>>p>>v;
		}
		else
		{

		}
	}
}