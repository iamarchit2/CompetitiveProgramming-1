#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	string s;
	ll ans=0;
	cin>>s;
	ll sum=0;
	vector<ll> a(3);
	for(ll i=0;i<s.size();++i)
	{
		ll x=s[i]-48;
		if(x%3==0)
		{
			ans++;
			sum=0;
			a[1]=a[2]=0;
		}
		else
		{
			sum+=x;
			sum=sum%3;
			if(sum==0)
			{
				ans++;
				sum=0;
				a[1]=a[2]=0;
			}
			else 
			{
				if(a[sum]==1)
				{
					a[1]=a[2]=0;
					ans++;
					sum=0;
				}
				else
				{
					a[sum]=1;
				}
			}
		}
	}
	cout<<ans;
}