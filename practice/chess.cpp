#include<bits/stdc++.h>
using namespace std;
#define ull  long long 
ull m=10000000;
vector<vector<ull> > board(8,vector<ull>(8));
ull horse(ull p,ull q,ull r,ull s,ull n)
{
	cout<<"&";

	if(p==r && q==s)
		return n;
	ull x[]={-2,-2,-1,-1,+2,+2,+1,+1},y[]={-1,+1,-2,+2,-1,+1,-2,+2};
	ull ans;
	for(ull i=0;i<8;++i)
	{
		if(p+x[i]>=1 && p+x[i]<=8 && q+y[i]>=1 && q+y[i]<=8)
		{
			if(board[p+x[i]-1][q+y[i]-1]==1)
			{
				continue;
			}
            board[p+x[i]-1][q+y[i]-1]=1;
		    ans=min(m,horse(p+x[i],q+y[i],r,s,n+1));
		    board[p+x[i]-1][q+y[i]-1]=0;
			
		}
	}
	return ans;
}
int main()
{
	// ull n,p,q,ctr=0;
	// cin>>p>>q>>n;
	// horse(p,q,n);
	// for(ull i=0;i<10;++i)
	// {
	// 	for(ull j=0;j<10;++j)
	// 	{
	// 		if(board[i][j]==1)
	// 			ctr++;
	// 	}
	// }
	// cout<<ctr<<endl;
	ull t;
	cin>>t;
	while(t--)
	{
		string x,y;
		ull p,q,r,s;
		cin>>x>>y;
		p=x[0]-96;
		r=y[0]-96;
		q=x[1]-48;
		s=y[1]-48;
		board[p-1][q-1]=1;
		ull ans=horse(p,q,r,s,0);
		cout<<ans<<endl;
	}

	
}