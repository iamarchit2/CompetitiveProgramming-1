#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
using namespace std;

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		ll d=abs(a+c-2*b);
		cout<<(d+1)/2<<endl;
	}
}