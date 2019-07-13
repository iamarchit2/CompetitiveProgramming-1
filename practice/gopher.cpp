#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		cin>>a; 
		int c=3,d=3,p,q,ctr=0;
		vector<vector<int> > x(3,vector<int>(3,1));	
		while(true)
		{
			cout<<c<<d;
			cin>>p>>q;
			if(p==1 && q==1)
				break;
		
			if(p==c-1 && q==d-1)
			{
				ctr+=x[0][0];
				x[0][0]=0;
			}
			else if(p==c-1 && q==d)
			{
				ctr+=x[0][1];
				x[0][1]=0;
			}
			else if(p==c-1 && q==d+1)
			{
				ctr+=x[0][2];
				x[0][2]=0;
			}
			else if(p==c && q==d-1)
			{
				ctr+=x[1][0];
				x[1][0]=0;
			}
			else if(p==c && q==d)
			{
				ctr+=x[1][1];
				x[1][1]=0;
			}
			else if(p==c && q==d+1)
			{
				ctr+=x[1][2];
				x[1][2]=0;
			}
			else if(p==c+1 && q==d-1)
			{
				ctr+=x[2][0];
				x[2][0]=0;
			}
			else if(p==c+1 && q==d)
			{
				ctr+=x[2][1];
				x[2][1]=0;
			}
			else if(p==c+1 && q==d+1)
			{
				ctr+=x[2][2];
				x[2][2]=0;
			}
			if(ctr==9)
			{
				ctr=0;d+=3;
				for(int i=0;i<3;++i)
				{
					for(int j=0;j<3;++j)
					{
						x[i][j]=1;
					}
				}
			}
		}
	}
}