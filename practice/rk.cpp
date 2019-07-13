#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll m;
		cin>>m;
		vector<ll> a;
		a.clear();
		for(ll i=1;i<=m;i*=4)
		{
			a.push_back(i);
		}
		ll i=a.size()-1,ctr=0;
		while(m)
		{
			if(m>=a[i])
			{
				ctr++;
				m-=a[i];
			}
			else
				i--;
		}
		if(ctr%2==1)
		{
			cout<<"RK";
		}
		else
		{
			cout<<"Nakul";
		}
		cout<<endl;
	}
}