#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		set<ll> a;
		ll temp;
		for(int i=0;i<n;++i)
		{
			cin>>temp;
			a.insert(temp);
		}
		cout<<n-a.size()<<endl;
	}
}