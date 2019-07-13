#include<bits/stdc++.h>
using namespace std;
#define ull long long 
ull search(ull z,vector<pair<ull,ull> > &a,ull start,ull end)
{
	ull mid=start+(end-start)/2;
	if(start>end)
		return -1;

	if(z==a[mid].first)
		return mid;
	else if(z>a[mid].first)
		return search(z,a,mid+1,end);
	else
		return search(z,a,start,mid-1);

}
int main()
{
	ull n,q;
	cin>>n>>q;
	vector<pair<ull,ull> >  a(n),c;
	vector<vector<pair<ull,ull> > > b;
	for(ull i=0;i<n;++i)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a.begin(),a.end());

 	c.push_back(a[0]);
	for(ull i=0;i<n-1;++i)
	{
		if(a[i+1].first==a[i].first)
			c.push_back(a[i+1]);
		else
		{
			b.push_back(c);
			c.clear();
			c.push_back(a[i+1]);
		}
	}
	b.push_back(c);

	c.clear();
	for(ull i=0;i<b.size();++i)
	{
		c.push_back(b[i][0]);
	}

	while(q--)
	{
		ull min=n;
		ull y,z; char d;
		cin>>y>>z>>d;
		ull x=search(z,c,0,c.size()-1);
		if(x==-1)
		{
			cout<<-1<<endl;
			continue;
		}
		for(ull i=0;i<b[x].size();++i)
		{
		        if(d=='R')
				{
					if(b[x][i].second>=y)
					{
						if(b[x][i].second-y<min)
							min=b[x][i].second-y;
					}
					else
					{
						if(n-(y-b[x][i].second)<min)
							min=n-(y-b[x][i].second);
					}
				}
				else
				{
				    if(b[x][i].second<=y)
					{
						if(b[x][i].second-y<min)
							min=-b[x][i].second+y;
					}
					else
					{
						if(n-(-y+b[x][i].second)<min)
							min=n-(-y+b[x][i].second);
					}	
				}        	
		}

		
		if(min==n)
		{
			cout<<-1<<endl;
        }
        else
        	cout<<min<<endl;
		
	}
}