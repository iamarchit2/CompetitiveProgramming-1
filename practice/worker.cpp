#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second 

int main()
{
	ll n;
	cin>>n;
	vector<pair<ll,ll> > a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].f;
	}
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].s;
	}
	set<ll> one,two,three;
	for(ll i=0;i<n;++i)
	{
		if(a[i].s==1)
			one.insert(a[i].f);
		else if(a[i].s==2)
			two.insert(a[i].f);
		else
			three.insert(a[i].f);
	}
	if(one.size()==0 || two.size()==0)
		cout<<*three.begin();
	else if(three.size()==0)
		cout<<*one.begin()+*two.begin();
	else 
	{
		if(*one.begin()+*two.begin()<=*three.begin())
			cout<<*one.begin()+*two.begin();
		else
			cout<<*three.begin();
	}
}