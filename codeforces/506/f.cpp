#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define inf 1000000000000000000
#define mod 1000000007
int main()
{
	ll n,k;
	cin>>n>>k;
	string t,s;
	cin>>t;
	string a=t,b=t;
	a.erase(a.end()-1);
	b.erase(b.begin());
	string temp="";
	while(a.size())
	{
		if(a==b)
		{
			for(ll i=a.size();i<n;++i)
				temp+=t[i];

			break;
		}
		a.erase(a.end()-1);
		b.erase(b.begin());
	}
	if(temp=="")
	{
		temp=t;
	}
	s+=t;
	for(ll i=0;i<k-1;++i)
	{
		s+=temp;
	}
	cout<<s<<endl;
}