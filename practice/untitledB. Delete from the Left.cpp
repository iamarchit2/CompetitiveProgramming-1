#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	string s,t;
	cin>>s>>t;
	ll i,j;
	for(i=s.size()-1,j=t.size()-1;i>=0 && j>=0;--i,--j)
	{
		if(s[i]!=t[j])
		{
			break;
		}
	}
	cout<<i+j+2;

}