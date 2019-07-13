#include<bits/stdc++.h>
using namespace std;
#define ull  long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ull n;
		cin>>n;
		vector<pair<ull,ull> > a(n),b(n),c,d;
		vector<ull> ans(n);
		for(ull i=0;i<n;++i)
		{
			cin>>a[i].first;
			a[i].second=i;
		}
		b=a;
		sort(b.begin(),b.end());
		for(ull i=0;i<n;++i)
		{
			if(b[i].first==b[i+1].first)
			{
				c.push_back(b[i]);
				c.push_back(b[i+1]);
				i++;
			}
			else
			{
				d.push_back(b[i]);
			}
		}
		ull x,y;
		x=c.size();
		y=d.size();
		
	  if(n<=4)
	  { if((x>2||x==0)&&(y>1||y==0))
		{
			cout<<n<<endl;
			for(ull i=0;i<y-1;++i)
			{
				ans[d[i+1].second]=d[i].first;
			}
            if(y!=0)
			{
				ans[d[0].second]=d[y-1].first;
            }
			for(ull i=0;i<x-2;++i)
			{
				
				ans[c[i+2].second]=c[i].first;
			}

			if(x!=0)
			{
				ans[c[0].second]=c[x-2].first;
			    ans[c[1].second]=c[x-1].first;
		    }
		}
		else if((x>2||x==0)&&(y==1))
		{
			cout<<n-1<<endl;
			ans[d[0].second]=d[0].first;
			for(ull i=0;i<x-2;++i)
			{
				ans[c[i+2].second]=c[i].first;
			}
			if(x!=0)
			{
				ans[c[0].second]=c[x-2].first;
			    ans[c[1].second]=c[x-1].first;
			}
		}
		else if((x==2)&&(y>1))
		{
			cout<<n<<endl;
			for(ull i=0;i<y-2;++i)
			{
				ans[d[i+2].second]=d[i].first;
			}
			ans[d[0].second]=c[0].first;
			ans[d[1].second]=c[1].first;
			ans[c[0].second]=d[y-2].first;
			ans[c[1].second]=d[y-1].first;
		}
		else if((x==2)&&(y==1))
		{
			cout<<n-1<<endl;
			ans[d[0].second]=c[0].first;
			ans[c[0].second]=d[0].first;
			ans[c[1].second]=c[1].first;
		}
		else if((x==2)&&(y==0))
		{
			cout<<n-2<<endl;
			ans[c[0].second]=c[0].first;
			ans[c[1].second]=c[1].first;
		}
		
		for(ull i=0;i<n;++i)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	  }	
	    
	}
}