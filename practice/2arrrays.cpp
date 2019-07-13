#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 

int main()
{
	ull n,m,k;
	cin>>n>>m>>k;
	vector<ull> a(n),b(m),c,temp(n);
	for(ull i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for(ull i=0;i<m;++i)
	{
		cin>>b[i];
	}
	for(ull i=0;i<min(n,m);++i)
	{
		if(a[i]==b[i])
		{
			c.push_back(i);
		}
	}
	if(k>c.size())
	{
		cout<<0;
		exit(0);
	}
	if(k==c.size())
	{
		ull ctr=1;
		ull p=c[0],q=a.size()-c[c.size()-1]-1,r=b.size()-c[c.size()-1]-1;
	}

}