#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pi 3.14159265
int main()
{
	ll t;
	cin>>t;
	vector<string> ans;
	while(t--)
	{
		double p,x,y,theta;
		cin>>p>>x>>y;
		if((x-50)*(x-50)+(y-50)*(y-50)-50*50 > 0)
		{
			//cout<<"Case #"<<c<<": "<<"white"<<endl;
			ans.push_back("white");
			// c++;
			continue;
		}
		if(x==50)
		{
			if(y>=50)
				theta=0;
			else if(y<50)
				theta=180;
		}
		else
		{
			theta=atan2((50.0-y),(50.0-x))*180.0/pi;
			//cout<<theta<<endl;
			if(theta<0)
			{
				theta=180.0+theta;
			}
			if(x>=50 && y>=50)
				theta=90.0-theta;
			else if(y<=50)
				theta=270.0-theta;
			else
				theta=450-theta;
		}
		double alpha=(p*360.0)/100.0;
		//cout<<theta<<" "<<alpha<<endl;
		if(alpha>=theta)
			// cout<<"Case #"<<c<<": "<<"black"<<endl;
			ans.push_back("black");
		else
			// cout<<"Case #"<<c<<": "<<"white"<<endl;
			ans.push_back("white");
		// c++;
	}
	for(ll i=0;i<ans.size();++i)
	{
		cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;
	}
}