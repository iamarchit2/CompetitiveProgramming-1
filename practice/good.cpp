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
		string a;
		ll n,ans=0,k=0,p=0,q=0;
		cin>>a>>n;
		for(ll i=0;i<a.size();++i)
		{
			if(a[i]=='a')
				{
					k++;
					p++;
				}
			else
				{
					k--;
					q++;
				}
			if(k>0)
				ans++;
		}
		if(k==0)
		{
			ans=ans*n;
		}
		else if(k<0)
		{
			k=abs(k);
			k=p/k;
			string b=a;
			if(n>=k+1)
			{
				while(k--)
					b+=a;
			}
			else
			{
				k=n-1;
				while(k--)
					b+=a;
			}
			k=0;ans=0;
			for(ll i=0;i<b.size();++i)
			{
				if(b[i]=='a')
					k++;
				else
					k--;
				if(k>0)
					ans++;
			}
		}
		else
		{
			k=q/k;
			string b=a;
			if(n>=k+1)
			{
				ans=a.size()*(n-k-1);
				while(k--)
					b+=a;
			}
			else
			{
				ans=0;
				k=n-1;
				while(k--)
					b+=a;
			}
			k=0;
			for(ll i=0;i<b.size();++i)
			{
				if(b[i]=='a')
					k++;
				else
					k--;
				if(k>0)
					ans++;
			}	
		}
		cout<<ans<<endl;
	}
}