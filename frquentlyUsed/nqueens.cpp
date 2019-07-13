#include<bits/stdc++.h>
using namespace std;
#define ull  long long 
bool is_attacked(ull x,ull y,vector<vector<ull> > &board)
{
	for(ull i=0;i<board.size();++i)
	{
		if(board[x][i]==1)
			return true;
		if(board[i][y]==1)
			return true;
	}
	for(ull i=0;i<board.size();++i)
	{
		for(ull j=0;j<board.size();++j)
		{
			if(i+j==x+y && board[i][j]==1)
				return true;
			if(i-j==x-y && board[i][j]==1 )
				return true;
		}
	}
	return false;

}
bool nQueens(vector<vector<ull> > &board,ull n,int i)
{
	if(n==0)
		return true;
	for(ull j=0;j<board.size();++j)
	{
		if(is_attacked(i,j,board))
		{
			continue;
		}
		board[i][j]=1;
		if(nQueens(board,n-1,i+1))
			return true;
		else
			board[i][j]=0;
	}
	return false;
}
int main()
{
	ull n;
	cin>>n;
	vector<vector<ull> > board(n,vector<ull>(n));
	if(nQueens(board,n,0))
	{
		cout<<"YES"<<endl;
		for(ull i=0;i<n;++i)	
		{
			for(ull j=0;j<n;++j)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else
		cout<<"NO"<<endl;
}