//https://codejam.withgoogle.com/2018/challenges/0000000000007764/dashboard

//time complexity : nlogn

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main()
{
	ll t,x=1;
	cin>>t;
	while(t--)
	{
		ll n,l,ans=0,sum=0;
		cin>>n>>l;
		vector<pair<ll,ll > > a(l);
		for(ll i=0;i<l;++i)
		{
			cin>>a[i].s;
			sum+=a[i].s;
		}
		double p=100.0/n;
		if(p==floor(p))
		{
			cout<<"Case #"<<x<<": "<<"100"<<endl;
			x++;
			continue;
		}
		ll left=n-sum;
		if(p-floor(p)>=0.5)
		{
			ans+=left*ceil(p);
			for(ll i=0;i<l;++i)
			{
				double temp=a[i].s*100.0/n;
				if(temp-floor(temp)>=0.5)
					ans+=ceil(temp);
				else
					ans+=floor(temp);
			}
			cout<<"Case #"<<x<<": "<<ans<<endl;
			x++;
			continue;
		}
		// ll q=1;
		// double r=p;
		// while(p-floor(p)<0.5)
		// {
		// 	q++;
		// 	p+=r;
		// }
		vector<ll> b;
		for(ll i=1;i<=n;++i)
		{
			double temp=i*100.0/n;
			if(temp-floor(temp)>=0.5)
				b.push_back(i);
		}
		sort(a.begin(),a.end(),sortbysec);
		for(ll i=0,j=0;i<l;++i)
		{
			while(a[i].s>b[j])
			{
				j++;
			}
			a[i].f=b[j]-a[i].s;
		}
		sort(a.begin(),a.end());
		ll j=0;
		ll q=b[0];
		while(left)
		{
			if(j>=l)
			{
				ll k=left/q;
				ll m=left%q;
				ans+=m*floor(p);
				ans+=k*ceil(q*100.0/n);
				left=0;
			}
			else if(a[j].f>left)
			{
				ans+=floor(left*100.0/n);
				left=0;
			}
			else if(a[j].f>q)
			{
				j=l;
			}
			else
			{
				left-=a[j].f;
				a[j].s+=a[j].f;
				j++;
			}
		}
		for(ll i=0;i<l;++i)
		{
			double temp=a[i].s*100.0/n;
			if(temp-floor(temp)>=0.5)
				ans+=ceil(temp);
			else
				ans+=floor(temp);
		}
		cout<<"Case #"<<x<<": "<<ans<<endl;
		x++;
	}	
}