#include<bits/stdc++.h>
using namespace std;
#define ull long long
int main()
{
	ull n;
	cin>>n;
	vector<ull> a(2*n);
	for(ull i=0;i<2*n;++i)
	{
		a[i]=i+1;
	}
	ull x,y;
	for(ull i=0;i<n;++i)
	{
		cin>>x>>y;
		ull pid=a[x];
		ull qid=a[y];
		for(ull i=0;i<a.size();++i)
		{
			if(a[i]==pid)
				a[i]=qid;
		}
	}
	sort(a.begin(),a.end());
	ull min=2*n,max=2;
	ull c=1;
	for(ull i=0;i<2*n-1;++i)
	{
		if(a[i]==a[i+1])
			c++;
		else
		{
			if(c<min&&c!=1)
				min=c;
			if(c>max)
				max=c;
			c=1;
		}

	}
	cout<<min<<" "<<max;
}