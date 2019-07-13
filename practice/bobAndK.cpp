//  https://www.hackerearth.com/challenge/competitive/may-circuits-18/algorithm/bob-and-subset-23f0729c/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int nCr(int n,int r)
{
	if(n==r)
		return 1;
	if(r==1)
		return n;
	return nCr(n-1,r)+nCr(n-1,r-1);
}
int main()
{
	int n,k;
	cin>>n>>k;
	unordered_set<int> a;
	for(int i=0;i<n;++i)
	{
		int t;
		cin>>t;
		a.insert(t);
	}
	unordered_set<int>::iterator i,j;
	unordered_set<int> ans,t1,t2;
	t1=ans=a;
	while(ans.size()<2047 && --k){
	
	for(i=t1.begin();i!=t1.end();++i)
	{
		for(j=a.begin();j!=a.end();++j)
		{
			int s=ans.size();
			ans.insert(*i | *j);
			if(ans.size()>s)
			{
				t2.insert(*i | *j);
			}
		}
	}
	t1=t2;
	t2.clear();	
	}
	cout<<ans.size()<<endl;
	// vector<vector<int> > v(a.size(),vector<int>(11,0));
	// unordered_set<int>::iterator it;
	// int x=0;
	// for(it=a.begin();it!=a.end();++it)
	// {
	// 	int temp=*it;
	// 	int y=10;
	// 	while(temp)
	// 	{
	// 		v[x][y--]=temp%2;
	// 		temp/=2;
	// 	}
	// 	x++;
	// }
	// vector<int> b(11,0);
	// for(int j=0;j<11;++j)
	// {
	// 	for(int i=0;i<v.size();++i)
	// 	{
	// 		b[j]=b[j] | v[i][j];
	// 	}
	// }
	// int count1=count(b.begin(),b.end(),1);
	// int ans=0;
	// if(k>=count1)
	// {
	// 	ans=pow(2,count1)-1;
	// }
	// else
	// {
	// 	for(int i=1;i<=k;++i)
	// 	{
	// 		ans+=nCr(count1,i);
	// 	}
	// }
	// cout<<ans<<endl;
}