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
		ull n,ctr=0;
		cin>>n;
		vector<ull> a(n),b,c,d;
		for(ull i=0;i<n;++i)
		{
			cin>>a[i];
			if(a[i]%4==1)
				b.push_back(a[i]);
			else if(a[i]%4==2)
				c.push_back(a[i]);
			else if(a[i]%4==3)
				d.push_back(a[i]);
		}
		
		ull p=c.size(),q=b.size(),r=d.size();
		ctr+=p/2;
		p=p%2;
		ctr+=min(q,r);
		ull temp=min(q,r);
		q-=temp;
		r-=temp;
		ull k=max(q,r);
		if(p==1 && k%4==2)
		{
			ctr+=2;
			p=0;
			k-=2;
		}
		ctr+=(k/4)*3;
		k=k%4;
		if(p==0 && k==0)
		{
			cout<<ctr<<endl;
		}
		else
			{cout<<-1<<endl;}
	}
}