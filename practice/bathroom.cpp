#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second 
void minmax(ll n,vector<pair<ll,pair<ll,ll> > > &a,vector<ll> &mina,vector<ll> &maxa)
{
	for(ll i=0;i<n;++i)
	{
		if(a[i].f==1)
		{
			mina[i]=-1;
			maxa[i]=-1;
		}
		else
		{
			mina[i]=min(a[i].s.f,a[i].s.s);
			maxa[i]=max(a[i].s.f,a[i].s.s);
		}
	}	
}
void update(ll n,vector<pair<ll,pair<ll,ll> > > &a,vector<ll> &mina,vector<ll> &maxa,ll index)
{
	for(ll i=index-1;i>=0 && a[i].f==0;i--)
	{
		a[i].s.s=a[i].s.s-a[index].s.s-1;
	}
	for(ll i=index+1;i<n && a[i].f==0;++i)
	{
		a[i].s.f=a[i].s.f-a[index].s.f-1;
	}
	minmax(n,a,mina,maxa);
}
ll f(ll k,ll n,vector<pair<ll,pair<ll,ll> > > &a,vector<ll> &mina,vector<ll> &maxa,ll index)
{
	ll t=*max_element(mina.begin(),mina.end());
	for(ll i=0;i<n;++i)
	{
		if(mina[i]!=t)
		{
			maxa[i]=-1;
		}
	}
	t=*max_element(maxa.begin(),maxa.end());
	for(ll i=0;i<n;++i)
	{
		if(maxa[i]==t)
		{
			index=i;
			a[i].f=1;k--;
			break;
		}
	}
	if(k==0)
	{
		return index;
	}
	update(n,a,mina,maxa,index);
	return f(k,n,a,mina,maxa,index);
}
int main()
{
	ll t,x=1;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		if(n%2==0)
		{
			if(k==n/2)
			{
				cout<<"Case #"<<x<<":"<<" "<<1<<" "<<0<<endl;
		        x++;				
			}
		}
		vector<pair<ll,pair<ll,ll> > > a(n);
		vector<ll> mina(n);
		vector<ll> maxa(n);
		for(ll i=0;i<n;++i)
		{
			a[i].f=0;
			a[i].s.f=i;
			a[i].s.s=n-i-1;
		}
		minmax(n,a,mina,maxa);
		ll i=f(k,n,a,mina,maxa,0);
		cout<<"Case #"<<x<<":"<<" "<<max(a[i].s.f,a[i].s.s)<<" "<<min(a[i].s.f,a[i].s.s)<<endl;
		x++;
	}
}