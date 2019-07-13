#include<bits/stdc++.h>
using namespace std;
#define p 5
bool leftdiagonal(vector<vector<int> > &a,int r,int c)
{
	int x[]={-1,-1,-1,0,1,1,1,0};
	int y[]={-1,0,1,1,1,0,-1,-1};
	for(int i=0;i<8;++i)
	{
		if((r+x[i])>=0 && (r+x[i])<p && (c+y[i])>=0 && (c+y[i])<p)
		{if(x[i]==0 || y[i]==0)
		{
			if(a[r+x[i]][c+y[i]]==-1)
			{
				return false;
			}
		}
		else if(x[i]!=y[i])
		{
			if(a[r+x[i]][c+y[i]]==1)
			{
				return false;
			}
		}
	    }
	}
	return true;
}
bool rightdiagonal(vector<vector<int> > &a,int r,int c)
{
	int x[]={-1,-1,-1,0,1,1,1,0};
	int y[]={-1,0,1,1,1,0,-1,-1};
	for(int i=0;i<8;++i)
	{
		if((r+x[i])>=0 && (r+x[i])<p && (c+y[i])>=0 && (c+y[i])<p)
		{if(x[i]==0 || y[i]==0)
		{
			if(a[r+x[i]][c+y[i]]==1)
			{
				return false;
			}
		}
		else if(x[i]==y[i])
		{
			if(a[r+x[i]][c+y[i]]==-1)
			{
				return false;
			}
		}
	    }
	}
	return true;
}
bool f(int n,vector<vector<int> > &a,int r,int c)
{
	if(n==0)
	{
		return true;
	}
	if(c==p)
	{
		c=0;
		r++;
	}
	if(r==p)
	{
		return false;
	}
	if(leftdiagonal(a,r,c))
	{	
		a[r][c]=1;
		if(f(n-1,a,r,c+1))
		{
			return true;
		}
		a[r][c]=0;
	}

	if(rightdiagonal(a,r,c))
	{				
		a[r][c]=-1;
		if(f(n-1,a,r,c+1))
		{
			return true;
		}
		a[r][c]=0;
	}		
	if(f(n,a,r,c+1))
	{
		return true;
	}
	return false;
}
int main()
{
	vector<vector<int> > a(p,vector<int>(p,0));
	int n=16;
	if(f(n,a,0,0))
	{
		cout<<"yes"<<endl;
	}
	for(int i=0;i<p;++i)
		{
			for(int j=0;j<p;++j)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
}