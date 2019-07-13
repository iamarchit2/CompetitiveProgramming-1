#include<bits/stdc++.h>
using namespace std;
#define ull  long long int
int main()
{
	ull n,c;
	ull cost=0;
	cin>>n>>c;
	vector<pair<ull,pair<ull,ull> > > a(c);
	for(ull i=0;i<c;++i)
	{
		cin>>a[i].second.first;
		cin>>a[i].second.second;
		cin>>a[i].first;
	}
    sort(a.begin(),a.end());
    vector<ull> b(n+1);
    b[0]=-1;

    for(ull i=0;i<c;++i)
    {
    	if(b[a[i].second.first]==0 || b[a[i].second.second]==0)
    	{
    		cost+=a[i].first;
    		if(b[a[i].second.first]==-1 || b[a[i].second.second]==-1)
       		{
       			if(b[a[i].second.first]==-1)
       			{
       				if(b[a[i].second.second]==0)
       					b[a[i].second.second]=a[i].second.second;
       				for(ull i=0;i<=n;++i)
       				{
       					if(b[i]==b[a[i].second.second])
       						b[i]=-1;
       				}
       			}
       			else
       			{
       				if(b[a[i].second.first]==0)
       					b[a[i].second.first]=a[i].second.first;
       			    for(ull i=0;i<=n;++i)
       				{
       					if(b[i]==b[a[i].second.first])
       						b[i]=-1;
       				}	
       			}
       		}

       		else
       		{
       			if(b[a[i].second.first]==0)
       			  b[a[i].second.first]=a[i].second.first;
       			if(b[a[i].second.second]==0)
       				b[a[i].second.second]=a[i].second.second;
       			for(ull i=0;i<=n;++i)
       			{
       				if(b[i]==b[a[i].second.first])
       					b[i]=b[a[i].second.second];
       			}
       		}
    	}
    	else if(b[a[i].second.first]!=b[a[i].second.second])
    	{
    		cost+=a[i].first;
    		if(b[a[i].second.first]==-1)
       			{
       				for(ull i=0;i<=n;++i)
       				{
       					if(b[i]==b[a[i].second.second])
       						b[i]=-1;
       				}
       			}
       		else if(b[a[i].second.second]==-1)
       			{
       			    for(ull i=0;i<=n;++i)
       				{
       					if(b[i]==b[a[i].second.first])
       						b[i]=-1;
       				}	
       			}
       		else
    	    {
    	    	for(ull i=0;i<=n;++i)
       			{
       				if(b[i]==b[a[i].second.first])
       					b[i]=b[a[i].second.second];
       			}
       		}

    	}
    	
    }
    cout<<cost;
}