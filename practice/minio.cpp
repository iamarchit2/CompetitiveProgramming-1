#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> s(n),a(n,0);
		for(ll i=0;i<n;++i)
		{
			cin>>s[i];
		}
		for(ll i=0;i<n;++i)
		{
			ll sum=0;
			ll j=i-1;
			while(j>=0)
			{
				if(s[i]>=sum)
					a[j]++;
				else
					break;
				sum+=s[j];
				j--;
			}	
			sum=0;j=i+1;
			while(j<n)
			{
				if(s[i]>=sum)
					a[j]++;
				else
					break;
				sum+=s[j];
				j++;
				
			}
		}
		for(ll i=0;i<n;++i)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}