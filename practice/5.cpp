#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
#define m 1000000007
int main()
{
	ull t;
	cin>>t;
	while(t--)
	{
		ull n;
		cin>>n;
		ull ans=0;
		vector<pair<ull,ull> > a(n);
		for(ull i=0;i<n;++i)
		{
			cin>>a[i].first;
		}
		for(ull i=0;i<n;++i)
		{
			cin>>a[i].second;
		}
		//sort(a.begin(),a.end());
		for(ull i=0;i<n;++i)
		{
			for(ull j=i+1;j<n;++j)
			{
				ull x=abs(a[j].first-a[i].first);
				ull y=max(a[i].second,a[j].second);
				ans=(ans%m+((x%m)*(y%m))%m)%m;
			}
		}
		cout<<ans<<endl;
	}
}