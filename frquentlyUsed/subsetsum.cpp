#include<bits/stdc++.h>
using namespace std;
bool subsetsum(vector<int> &a,vector<int> &b,int m,int rsum,int ssum,int i)
{
	if(ssum==m)
		return true;
	if(ssum>m || (ssum+rsum)<m)
		return false;
	if(subsetsum(a,b,m,rsum-a[i],ssum+a[i],i+1))
	{
		b[i]=1;
		return true;
	}
	if(subsetsum(a,b,m,rsum-a[i],ssum,i+1))
	{
		return true;
	}
	return false;
}
int main()
{
	int n,m,sum=0;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		sum+=a[i];
	}
	cin>>m;
	if(subsetsum(a,b,m,sum,0,0))
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;++i)	
		{
			cout<<b[i]<<" ";
		}
	}
	else
		cout<<"NO"<<endl;
}