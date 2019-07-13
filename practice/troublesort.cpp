//https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/00000000000079cb

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second 
int main()
{
	ll t,x=1;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<pair<ll,ll> > a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i].f;
			a[i].s=i;
		}
	
		sort(a.begin(),a.end());
		
		ll flag=0,flag2=0;
		ll i,j=0;
		for( i=0;i<n;++i)
		{
			if(abs(a[i].s-i)%2==1)
			{
				flag2=0;
				if(j<i)
					j=i;
				while(a[i].f==a[j].f)
				{
					if(abs(a[j].s-a[i].s)%2==1)
					{
						flag2=1;
						ll temp=a[i].s;
						a[i].s=a[j].s;
						a[j].s=temp;
						break;
					}
					j++;
					if(j>=n)
					{
						break;
					}
				}
				if(flag2==0)
				{
					flag=1;
					break;
				}
			}
			
		}
		if(flag==1)
		{
			cout<<"Case #"<<x<<":"<<" "<<i<<endl;
		}
		else
		{
			cout<<"Case #"<<x<<":"<<" "<<"OK"<<endl;
		}
		x++;
	}
}