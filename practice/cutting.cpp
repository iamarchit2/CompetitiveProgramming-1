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
		ll n,ans=0;
		cin>>n;
		vector<ll> a(n),b(n),y;
		vector<pair<ll,ll> >x(n);
		
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		for(ll i=0;i<n;++i)
		{
			cin>>b[i];
			x[i].f=b[i];
			x[i].s=i;
			
			if(b[i]>a[i])
			{
				ans=-1;
				break;
			}
		}
		if(ans==-1)
		{
			cout<<-1<<endl;
			continue;
		}
		// vector<vector<pair<pair<ll,ll>,ll> > > c;
		// vector<pair<pair<ll,ll>,ll> > d;
		// for(ll i=0;i<n;++i)
		// {
		// 	if(a[i]==b[i])
		// 	{
		// 		if(d.size())
		// 		{
		// 			//sort(d.begin(),d.end());
		// 			c.push_back(d);
		// 		}
		// 		d.clear();
		// 	}
		// 	else
		// 	{
		// 		d.push_back(make_pair(make_pair(b[i],a[i]),i));
		// 	}
		// } 
		// if(d.size())
		// {
		// 	//sort(d.begin(),d.end());
		// 	c.push_back(d);
		// }

		
		
		// for(ll i=0;i<c.size();++i)
		// {
		// 	sort(c[i].begin(),c[i].end());
		// 	for(ll j=0;j<c[i].size();++j)
		// 	{
		// 		ll temp=c[i][j].f.f;
		// 	}
		// }

		sort(x.begin(),x.end());
		ans=0;
		for(ll i=0;i<n-1;++i)
		{
			if(x[i].f==x[i+1].f)
			{
				y.push_back(x[i].f);

			}
			else
			{
				if(a[x[i].s]!=b[x[i].s])
				{
					a[x[i].s]=b[x[i].s];
					ans++;
				}
			}
			while(x[i].f==x[i+1].f)
			{
				i++;
				if(i==n-1)
					break;
			}
		}
		if(x[n-1].f!=x[n-2].f)
		{
			if(a[x[n-1].s]!=b[x[n-1].s])
				{
					a[x[n-1].s]=b[x[n-1].s];
					ans++;
				}
		}
		for(ll i=0;i<y.size();++i)
		{
			ll q=y[y.size()-1-i];
			ll flag=0;
			for(ll j=0;j<a.size();++j)
			{
				if(a[j]==b[j])
				{
					if(a[j]==q)
						continue;
					if(flag==1)
					{
						ans++;flag=0;
					}
				}
				else if(q==b[j])
				{
					a[j]=q;
					flag=1;
				}
				else if(q>b[j])
				{
					if(a[j]>=q)
						a[j]=q;
					else
					{
						if(flag==1)
						{
							ans++;flag=0;
						}
					}
				}
			}
			if(flag==1)
				ans++;
		}
		cout<<ans<<endl;
	}
}