#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n;
	cin>>n;
	string s;
	cin>>s;
	vector<ll> a(26);
	ll temp=0;
	for(ll i=0;i<n;++i)
	{
		a[s[i]-'a']++;
		if(a[s[i]-'a']==2)
		{
			temp=1;
			break;
		}
	}
	if(temp==1 || n==1)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}