#include<bits/stdc++.h>
using namespace std;
#define ll long long
void reverse(vector<int> &a,int p,int q)
{
	for(int i=p,j=q;i<=p+(q-p)/2;++i,--j)
	{
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}
map<vector<int>,pair<int,int> > m;
int ans=INT_MAX;
void f(vector<int> &a,int ctr)
{
	if(is_sorted(a.begin(),a.end()))
	{
		ans=min(ans,ctr);
		return;
	}
	if(m[a].first==1 && ctr>=m[a].second)
		return;
	if(ctr>=ans)
		return;
	m[a].first=1;
	m[a].second=ctr;
	for(int i=2;i<=a.size();++i)
	{
		for(int j=0;j<=a.size()-i;++j)
		{
			reverse(a,j,j+i-1);
			f(a,ctr+1);
			reverse(a,j,j+i-1);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	f(a,0);
	cout<<ans;
}