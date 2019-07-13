#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n;
	cin>>n;
	vector<pair<ll,string> > a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].s;
		a[i].f=a[i].s.size();
	}
	sort(a.begin(),a.end());
	ll k=0;
	for(ll j=n-1;j>0;j--)
	{
		size_t found=a[j].s.find(a[j-1].s);
		if(found==string::npos)
		{
			k=1;
			break;
		}
	}
	if(k==0)
	{
		cout<<"YES"<<endl;
		for(ll i=0;i<n;++i)
		{
			cout<<a[i].s<<endl;
		}
	}
	else
		cout<<"NO"<<endl;
}