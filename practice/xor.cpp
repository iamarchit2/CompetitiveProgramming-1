#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define m 1000000
int main()
{
	ull n,q;
	cin>>n>>q;
	vector<ull> a(n+1);
	vector<ull> x(n+1);
	vector<ull> ct(m,0);
	for(ull i=1;i<n+1;++i)
	{
		cin>>a[i];
		x[i]=x[i-1]^a[i];
		ct[x[i]]++;
	}
	while(q--)
	{
		int choice;
		ull index,xk,count=0;
		cin>>choice>>index>>xk;
		if(choice==1)
		{
			for(ull i=index;i<n+1;++i)
			{
				ct[x[i]]--;
				x[i]=x[i]^a[index]^xk;
				ct[x[i]]++;
			}
			 a[index]=xk;
		}
		else
		{
			
			cout<<ct[xk]<<endl;
		}
	}
}