#include<bits/stdc++.h>
using namespace std;
#define ull long long 
#define m 1000000007
int main()
{
	ull t;
	cin>>t;
	while(t--)
	{
		ull n;
		string x,y;
		ull p=0,q=0;
		cin>>n;
		vector<string> a(n);
		for(ull i=0;i<n;++i)
		{
			cin>>a[i];
			x=a[0];
			if(a[i]==x)
				p++;
			if(a[i]!=x)
				{
					y=a[i];
					q++;
				}

		}
		if(p==q)
			cout<<"Draw"<<endl;
		else if(p>q)
		{
			cout<<x<<endl;
		}
		else
			cout<<y<<endl;


	}
}