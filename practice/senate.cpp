#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second 
 
int main()
{
	ll t,x=1;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		set<pair<ll,char> ,greater<pair<ll,char> > > a;
		set<pair<ll,char> ,greater<pair<ll,char> > > :: iterator itr;
		for(ll i=0;i<n;++i)
		{
			ll temp;
			cin>>temp;
			a.insert(make_pair(temp,'A'+i));
		}
		cout<<"Case #"<<x<<":"<<" ";
		pair<ll,char> p;
		while(a.size())
		{
			if(a.size()==3)
			{
				itr=a.begin();
				if((*itr).f==1 && (*itr++).f==1 && (*itr++).f==1)
				{
					itr=a.begin();
					cout<<(*itr).s<<" "<<(*itr++).s<<(*itr++).s;
					break;
				}
			}
			for(int i=1;i<=2;++i)
			{
				p=*a.begin();
				cout<<p.s;
				p.f-=1;
				a.erase(a.begin());
				if(p.f!=0)
				{
					a.insert(p);
				}
			}
			cout<<" ";
		}
		cout<<endl;
		x++;
	}
} 