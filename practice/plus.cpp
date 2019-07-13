//https://www.hackerearth.com/challenge/competitive/may-circuits-18/algorithm/plus-plus-60bcac48/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int maxsum=0;
void f(vector<vector<int> > &a,int i,int j,int x,int y)
{
	maxsum=max(maxsum,a[i-1][j]*a[x-1][y]+a[i][j-1]*a[x][y-1]+a[i][j]*a[x][y]+a[i][j+1]*a[x][y+1]+a[i+1][j]*a[x+1][y]);
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> > a(n,vector<int>(m,0));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<n-1;++i)
	{
		for(int j=1;j<m-1;++j)
		{
			int x=i,y=j+3;
			while(x<n-1)
			{
				if(y>=m-1)
				{
					x++;
					if(x==n-1)
						break;
					y=1;
				}
				if(x-i+abs(y-j)>=3)
				{
					f(a,i,j,x,y);
				}
				y++;
			}
		}
	}
	cout<<maxsum<<endl;
}