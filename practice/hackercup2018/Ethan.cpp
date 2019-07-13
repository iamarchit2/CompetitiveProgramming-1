#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007


int main()
{
	ll t;
	cin>>t;
	vector<vector<ll> > ans;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		vector<vector<ll> > a(n,vector<ll>(2));
		for(ll i=0;i<n;++i)
		{
			cin>>a[i][0]>>a[i][1];
		}
		stack<ll> s;
		vector<ll> pre;
		vector<ll> post;
		s.push(1);
		while(s.size())
		{
			ll temp=s.top();
			s.pop();
			pre.push_back(temp);
			if(a[temp-1][1]!=0)
			{
				s.push(a[temp-1][1]);
			}
			if(a[temp-1][0]!=0)
			{
				s.push(a[temp-1][0]);
			}
		}
		stack<ll> s1,s2;
		s1.push(1);
		while(s1.size())
		{
			ll temp=s1.top();
			s1.pop();
			s2.push(temp);
 
        	if (a[temp-1][0]!=0)
            	s1.push(a[temp-1][0]);
        	if (a[temp-1][1]!=0)
            	s1.push(a[temp-1][1]);
		}
		while (s2.size())
    	{
        	ll temp = s2.top();
        	s2.pop();
        	post.push_back(temp);
    	}
    	vector<ll> m(n+1),label(n+1),visited(n+1);
    	ll l=0;
    	for(ll i=0;i<n;++i)
    	{
    		m[pre[i]]=post[i];
    	}
    	ll ctr=0;
    	for(ll i=1;i<=n;++i)
    	{
    		if(!visited[i])
    		{
    			l++;
    			ctr++;
    			visited[i]=1;
    			ll j=m[i];
    			if(l%k==0)
    				label[i]=k;
    			else
    				label[i]=l%k;
    			while(j!=i)
    			{
    				if(l%k==0)
    					label[j]=k;
    				else
    					label[j]=l%k;
    				visited[j]=1;
    				j=m[j];
    			}
    		}
    	}
    	if(ctr>=k)
    	{
    		ans.push_back(label);
    	}
    	else
    	{
    		vector<ll> z;
    		z.push_back(-1);
    		z.push_back(-1);
    		ans.push_back(z);
    	}
	}
	for(ll i=0;i<ans.size();++i)
	{
		cout<<"Case #"<<i+1<<": ";
		for(ll j=1;j<ans[i].size();++j)
		{
			if(ans[i][j]==-1)
				cout<<"Impossible";
			else
			{				
				cout<<ans[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}