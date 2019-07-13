#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<string> a(n);
	cin.ignore();
	for(int i=0;i<n;++i)
	{
		getline(cin,a[i]);
	}
	int q;
	cin>>q;
	string buffer="";
	int cursori=n-1;
	while(q--)
	{
		string ch;
		cin>>ch;
		if(ch[0]=='d')
		{
			if(ch[1]=='y')
			{
				buffer=a[cursori];
			}
			a.erase(a.begin()+cursori);
			if(a.size()==0)
			{
				//a.resize(1);
				cursori=0;
			}
			else if(cursori==a.size())
				cursori=a.size()-1;
		}
		else if(ch[0]==':')
		{
			cursori=ch[1]-'0'-1;			
		}
		else if(ch[0]=='i')
		{
			int y;
			cin>>y;
			vector<string> temp(y);
			int x=cursori+1;
			cin.ignore();
			for(int i=0;i<y;++i)
			{
				getline(cin,temp[i]);
			}
			if(y>=1)
			{
				a[cursori]+=temp[0];
			}
			if(cursori==a.size()-1)
			{
				for(int i=1;i<y;++i)
				{
					a.insert(a.end(),temp[i]);
				}
			}
			else if(y>=2)
			{
				//a[cursori+1]=temp[y-1]+a[cursori+1];
				for(int i=1;i<y;++i)
				{
					a.insert(a.begin()+x,temp[i]);
					x++;
				}
			}
			cursori=x-1;
		}
		else if(ch[0]=='y')
		{
			buffer=a[cursori];			
		}
		else if(ch[0]=='p')
		{
			a[cursori]+=buffer;		
		}
	}
	for(int i=0;i<a.size();++i)
	{
		cout<<a[i]<<endl;
	}
}