//https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/00000000000079cc
//partially solved
#include<bits/stdc++.h>
using namespace std;
#define d float
#define PI 3.14159265
int main()
{
	int t,x=1;
	cin>>t;
	while(t--)
	{
		d a;
		cin>>a;
		d root = floor(sqrt(2)*pow(10,6))/pow(10,6);
		if(a<=root)
		{d b = a/root;
		d angle=acos(b); 
		double p=(sin(angle)+cos(angle))/(2*sqrt(2));
		double q=(-sin(angle)+cos(angle))/(2*sqrt(2));	
		cout<<"Case #"<<x<<":"<<endl;
		cout<<setprecision(16)<<p<<" "<<q<<" "<<0<<endl;
		p=(sin(angle)-cos(angle))/(2*sqrt(2));
		q=(sin(angle)+cos(angle))/(2*sqrt(2));
		cout<<setprecision(16)<<p<<" "<<q<<" "<<0<<endl;	
		cout<<setprecision(16)<<0<<" "<<0<<" "<<0.5<<endl;
		x++;
		}
	}
}