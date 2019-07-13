#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
int main()
{
	ull n,c;
	cin>>n>>c;
	vector<pair<pair<ull,ull>,ull > > a(c),b(c),m1(n+1),m2(n+1);
	for(ull i=0;i<c;++i)
	{
		cin>>a[i].first.first;
		cin>>a[i].first.second;
		cin>>a[i].second;
		b[i].first.first=a[i].first.second;
		b[i].first.second=a[i].first.first;;
	}
	sort(a.begin(),a.end());
	ull j=a[0].first.first,x=0;
	ull min=a[0].second;
	for(ull i=1;i<c;++i)
	{
		if(a[i].first.first==j)
		{
			if(a[i].second<min)
			{
				min=a[i].second;
				x=i;
			}
		}
		else
		{
			m1[j]=a[x];
			j=a[i].first.first;
			min=a[i].second;
			x=i;
		}
		
	}
	sort(b.begin(),b.end());
	ull j=0,x=0;
	ull min=a[0].second;
	for(ull i=1;i<c;++i)
	{
		if(b[i].first.first==j)
		{
			if(b[i].second<min)
			{
				min=b[i].second;
				x=i;
			}
		}
		else
		{
			m2[j]=b[x];
			j++;
			min=a[i].second;
		}
		
	}
	
	
	cout<<ans;
}