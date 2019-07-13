#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	string s;
	cin>>s;
	ll fir=1,sec=1,middle=1,temp=1;
	ll i=0;
	while(1)
	{
		if(i>=s.size()-1)
			break;
		if(s[i]==s[i+1])
			break;
		fir++;
		i++;
	}
	if(fir==s.size())
	{
		cout<<fir<<endl;
		exit(0);
	}
	i=s.size()-1;
	while(1)
	{
		if(i<=0)
			break;
		if(s[i]==s[i-1])
			break;
		sec++;
		i--;
	}
	for(ll i=0;i<s.size()-1;++i)
	{
		if(s[i]==s[i+1])
		{
			middle=max(middle,temp);
			temp=1;
		}
		else
		{
			temp++;
		}
	}
	middle=max(middle,temp);
	ll x;
	if(s[0]==s[s.size()-1])
		x=middle;
	else
		x=fir+sec;
	cout<<max(middle,x)<<endl;

}