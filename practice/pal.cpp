#include<bits/stdc++.h>
using namespace std;
bool f(string a,int x)
{
	for(int i=0;i<x/2;++i)
	{
		if(a[i]!=a[x-1-i])
			return false;
	}
	return true;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		string a,c;
		cin>>a;
		n=a.size();
		int r=n;
		for(int i=0;i<n;++i)
		{
			c.clear();
			for(int j=i;j<n;++j)
			{
				c+=a[j];
				int x=c.size();
				if(c.size()>1){
			    if(f(c,x))
			    {
				  r+=x*x;
			    }
			    }	
		    }
	    }
	
		cout<<r<<endl;
	}
}