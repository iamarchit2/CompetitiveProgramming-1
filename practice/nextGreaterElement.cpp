/*Find all the next greater numbers for array elements(no duplicates).
The Next Greater Number of a number x  is the first greater number to its right. 
If it does not exist, output -1 for this number.
if array is 10 4 2 6 7  9 3  2 
then answer -1 6 6 7 9 -1 -1 -1
*/

#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main()
{
	int n;
	cin>>n;
	vector<pair<int,int> > a(n);
	for(int i=0;i<n;++i)
	{
		cin>>a[i].f;
	}
	a[n-1].s=-1;
	for(int j=n-2;j>=0;--j)
	{
		if(a[j+1].f>a[j].f)
		{
			a[j].s=j+1;
		}
		else
		{
			int next=a[j+1].s;
			while(next!=-1)
			{
				if(a[next].f>a[j].f)
				{
					a[j].s=next;
					break;
				}
				next=a[next].s;
			}
			if(next==-1)
				a[j].s=-1;
		}
	}
	for(int i=0;i<n-1;++i)
	{
		cout<<a[a[i].s].f<<" ";
	}
	cout<<-1<<endl;
}