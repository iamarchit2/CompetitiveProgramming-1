#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
bool search(ll x,vector<pair<ll,ll> > a,ll start,ll end,ll &mid)
{
	mid=start+(end-start)/2;
	if(start>end)
		return false;
	if(a[mid].f==x)
		return true;
	if(x<a[mid].f)
		return search(x,a,start,mid-1,mid);
	else
		return search(x,a,mid+1,end,mid);
}
int main()
{
	ll k;cin>>k;
	vector<pair<pair<ll,ll>,ll> > a;
	vector<ll> b(k);
	vector<ll> sum(k);
	for(ll i=0;i<k;++i)
	{
		
		cin>>b[i];
		for(ll j=0;j<b[i];++j)
		{
			ll temp;
			cin>>temp;
			a.push_back(make_pair(make_pair(temp,i),j));
			sum[i]+=temp;
		}
	}
	for(ll i=0,j=0;i<a.size();)
	{
		while(a[i].f.s==j)
		{
			a[i].f.f=sum[j]-a[i].f.f;
			i++;
		}
		j++;
	}
	sort(a.begin(),a.end());
	ll temp=0;
	for(ll i=0;i<a.size()-1;)
	{
		ll x=i+1;
		while(a[i].f.f==a[x].f.f)
		{if(a[i].f.s!=a[x].f.s)
		{
			temp=1;
			cout<<"YES"<<endl;
			cout<<a[i].f.s+1<<" "<<a[i].s+1<<endl<<a[x].f.s+1<<" "<<a[x].s+1<<endl;
			break;
		}
		x++;
		}
		i=x;
		if(temp==1)
			break;
	}
	if(temp==0)
		cout<<"NO"<<endl;
}