#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll t;
	cin>>t;
	vector<string> v;
	while(t--)
	{
		string a,ans;
		cin>>a;
		string b;
		vector<ll> in;
		for(ll i=0;i<a.size();++i)
		{
			if(a[i]==a[0])
				in.push_back(i);
		}
		if(in.size()==1)
		{
			ans="Impossible";
		}
		else
		{
			for(ll i=in[0];i<in[1];++i)
			{
				b+=a[i];
			}
			ans+=b;
			ll temp=0;
			for(ll i=2;i<in.size();++i)
			{
				string c;
				temp=0;
				for(ll j=in[i-1];j<in[i];++j)
				{
					c+=a[j];
				}
				if(c!=b)
				{
					temp=1;
					ans+=a;
					break;
				}
				else
				{
					ans+=c;
				}
			}
			if(temp==0)
			{
				string c;
				for(ll i=in[in.size()-1];i<a.size();++i)
				{
					c+=a[i];
				}
				if(c.size()>b.size())
					ans+=a;
				else
				{
					for(ll i=0;i<c.size();++i)
					{
						if(c[i]!=b[i])
						{
							temp=1;
							ans+=a;
							break;
						}
					}
					if(temp==0)
						ans="Impossible";
				}
			}
		}
		v.push_back(ans);
	}
	for(ll i=0;i<v.size();++i)
	{
		cout<<"Case #"<<i+1<<": "<<v[i]<<endl;
	}
}