#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	ll ans=0;
	for(ll i=0;i<n;++i)
	{
		if(a[i]==b[i])
			continue;
		if(i==n-1)
			ans++;
		else if(a[i]==a[i+1])
			ans++;
		else if(a[i]!=a[i+1] && a[i+1]!=b[i+1])
		{
			ans++;i++;
		}
		else
			ans++;
	}
	cout<<ans<<endl;
}