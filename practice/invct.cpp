#include<bits/stdc++.h>
using namespace std;
#define ull  unsigned long long int
ull ctr=0;
void merge1(vector<ull> &a,ull start,ull end)
{
	vector<ull> t1,t2;
	ull mid=start+(end-start)/2;
      for(ull i=start;i<=mid;++i)
	  {
		t1.push_back(a[i]);
	  }
	  for(ull i=mid+1;i<=end;++i)
	  {
	  	t2.push_back(a[i]);
	  }    
	  ull i,x,y;
	  for(i=start,x=0,y=0;x<t1.size() && y<t2.size();)
	  {
	  	if(t1[x]<=t2[y])
	  		a[i++]=t1[x++];
	  	else
	  		{
	  			a[i++]=t2[y++];
	  			ctr+=t1.size()-x;
	  		}
	  }
	  if(x==t1.size() )
	  {
	  	while(y!=t2.size())
	    {
	      a[i++]=t2[y++];
	    }
	  }
	  else
	  {
	  	while(x!=t1.size())
	  	{
	  		a[i++]=t1[x++];
	  	}
	  }
}


void mergeSort(vector<ull> &a,ull start,ull end)
{
	
	if(start>=end)
	{
		return;
	}
	ull mid= start + (end-start)/2;
	
	
	mergeSort(a,start,mid);
	mergeSort(a,mid+1,end);
	
	merge1(a,start,end);
}


int main()
{
	ull t;
	cin>>t;
	while(t--)
	{
	ull n;
	cin>>n;	
	vector<ull> ab(n),temp,p(n);
	vector<pair<ull,ull> > v(n);
	for(ull i=0;i<n;++i)
	{
		cin>>ab[i];
		v[i].first=ab[i];
		v[i].second=i;
	}
	sort(v.begin(),v.end());
	for(ull i=0;i<n;++i)
	{
		p[v[i].second]=i;
	}
	temp=ab;
	mergeSort(temp,0,n-1);
	for(ull i=0;i<n;++i)
	{
		ctr=ctr-p[i]+n-1-p[i];
		cout<<ctr<<" ";
	}
   

	cout<<endl;
    }	
}
