//https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard

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
		ll d;
		string p;
		cin>>d>>p;
		ll strength=1,damage=0,j=0,ans=0;
		vector<ll> c(count(p.begin(),p.end(),'C')+1,0);
		for(ll i=0;i<p.size();++i)
		{
			if(p[i]=='S')
			{
				c[j]++;
				damage+=strength;
			}
			else
			{
				j++;
				strength*=2;
			}
		}
		if(damage<=d)
		{
			cout<<"Case #"<<x<<":"<<" "<<0<<endl;
			x++;
			continue;
		}
		ll flag=0;
		while(c.size()-1)
		{
			j=c.size()-1;
			if(damage-(c[j]*strength/2)==d)
			{
				flag=1;
				ans+=c[j];
				break;
			}
			if(damage-(c[j]*strength/2)<d)
			{
				while(damage>d)
				{
					ans++;
					damage-=(strength/2);
				}
				flag=1;
				break;
			}
			ans+=c[j];
			damage-=(c[j]*strength/2);
			strength/=2;
			c[j-1]+=c[j];
			c.pop_back();
		}
		if(flag==0)
		{
			cout<<"Case #"<<x<<":"<<" "<<"IMPOSSIBLE"<<endl;
		}
		else
		{
			cout<<"Case #"<<x<<":"<<" "<<ans<<endl;
		}
		x++;
	}
}