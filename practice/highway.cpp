#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second 

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		double n,s,y;
		cin>>n>>s>>y;
		//double tim=(n*y)/s*1.0,x=y/s*1.0;
		double tim=0, x=y/s*1.0;
		vector<double> v(n),d(n),p(n),l(n);
		for(ll i=0;i<n;++i)
		{
			cin>>v[i];
		}
		for(ll i=0;i<n;++i)
		{
			cin>>d[i];
		}
		for(ll i=0;i<n;++i)
		{
			cin>>p[i];
		}
		for(ll i=0;i<n;++i)
		{
			cin>>l[i];
		}
		for(ll i=0;i<n;++i)
		{
			if(p[i]>=0 && d[i]==0)
			{
				p[i]-=(tim*v[i]);
			}
			else if(p[i]<=0 && d[i]==1)
			{
				p[i]+=(tim*v[i]);
			}
			tim+=x;
			if((p[i]>0 && d[i]==1) || (p[i]<0 && d[i]==0))
			{
				if(abs(p[i])-l[i]<=0)
					tim+=((abs(abs(p[i])-l[i]))+0.000001)/v[i];
				continue;
			}
			if((abs(p[i])-0.000001)/v[i]>x)
				continue;
			else
				tim+=(abs(p[i])+l[i]+0.000001)/v[i];
		}
		cout<<fixed;
		cout<<setprecision(10)<<tim<<endl;
	}
}