#include<bits/stdc++.h>
using namespace std;
#define ull  long long 
#define m 1000000007
void rotate(ull i,ull &x,ull &y,vector<pair<ull,ull> > p,vector<ull> a)
{
   ull vx=x-p[i].first;
	ull vy=y-p[i].second;
	
	
		if(a[i]==90) { ull temp=vx;
		         vx=-vy;
		         vy=temp;
		        }
		else if(a[i]==180) {vx=-vx;
		          vy=-vy;
		          }

		else if(a[i]==270){ull temp=vx;
		          vx=vy;
		          vy=-temp;
		         }  
		else{vx=vx;
		       vy=vy;
		       }
	
	x=vx+p[i].first;
	y=vy+p[i].second;
//	cout<<x<<" "<<y<<endl;
}
int main()
{
	ull n;
	cin>>n;
	vector<pair<ull,ull> > p(n);
	vector<ull> a(n);
	for(ull i=0;i<n;++i)
	{
		cin>>p[i].first>>p[i].second>>a[i];
		a[i]=a[i]%360;
	} 
	ull q;
	cin>>q;
	while(q--)
	{
		ull ch;
		cin>>ch;
		if(ch==1)
		{
		
			ull x,y,l,r;
			cin>>x>>y>>l>>r;
			for(ull i=l-1;i<r;++i)
			{
//cout<<"@";				
				rotate(i,x,y,p,a);

			}
//cout<<"*";	
            if(x<0)
            x=m+x;
            if(y<0)
            y=y+m;		
			cout<<x%m<<" "<<y%m<<endl;
		}
		else if(ch==2)
		{
			ull u,x,y,b;
			cin>>u>>x>>y>>b;
			p[u-1].first=x;
			p[u-1].second=y;
			a[u-1]=b%360;
		}
	}
}