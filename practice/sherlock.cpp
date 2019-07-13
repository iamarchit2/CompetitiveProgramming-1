#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll t,x=0;
	cin>>t;
	vector<string> ans(t);
	while(t--)
	{
		ll n,k,p;
		cin>>n>>k>>p;
		string q,u;
		ll a,b,c;
		for(ll i=0;i<n;++i)
			q+='0';
		for(ll i=0;i<k;++i)
		{
			cin>>a>>b>>c;
			if(c==1)
				q[a-1]='1';
		}
		p=p-1;
		while(p)
		{
			if(p%2==0)
			{
				u.insert(u.begin(),'0');
			}
			else
			{
				u.insert(u.begin(),'1');
			}
			p=p/2;
		}
		ll j=q.size()-1,ctr=0;
		for(ll i=u.size()-1,k=1;i>=0;--i,k++)
		{
			if(u[i]=='1')
			{
				while(ctr!=k)
				{
					if(q[j]=='0')
						ctr++;
					j--;
				}
				q[j+1]='1';
			}
		}
		ans[x++]=q;
		// cout<<"Case #"<<x<<": ";
		// cout<<q;
		// cout<<endl;
		// x++;
	}
	for(ll i=0;i<ans.size();++i)
	{
		cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;
	}
}