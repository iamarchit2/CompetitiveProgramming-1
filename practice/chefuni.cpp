#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
ull ans=0;
ull x,y,z,a,b,c,ta,tb,tc;
ull p,q;
vector<ull> v(3);
void fa()
{
	ans+=(v[0]+v[1]+v[2])*a;
}
int main()
{
	ull t;
	cin>>t;
	while(t--)
	{
		
		cin>>x>>y>>z>>a>>b>>c;
	    ta=6*a,tb=3*b,tc=2*c;
		ull m=min(min(ta,tb),tc);
		//p=min(min(x,y),z);
		//q=max(max(x,y),z);
		v[0]=x;v[1]=y;v[2]=z;
		sort(v.begin(),v.end());
		if(m==ta)
		{
			fa();
		}
		else if(m==tb)
		{
			while(v[2]!=0)
			{
				if(v[0]==0 && v[1]==0)
				{
					fa();
					v[2]=0;
					
				}
				else if(v[0]==0)
				{
					ans+=v[1]*b;
					v[1]=0;
					v[2]-=v[1];
				}
				else if(v[1]==1)
				{	
						ans+==min(min(2*b+(v[2]-2)*a,b+v[2]*a),c+(v[2]-1)*a);
						v[2]=0;
					
				}
				else 
				{
					if(v[0]+v[1]+v[2]>6)
					{
						ans+=b;
						v[2]--;
						v[1]--;
						sort(v.begin(),v.end());
					}
					else if(v[0]+v[1]+v[2]==6)
					{
						ans+=3*b
						v[2]=0;
					}
					else if(v[2]==2 && v[1]==2 && v[0]==1)
					{
						ans+=min(min(2*b+a,b+c),b+3*a);
						v[2]=0;
					}
					else if(v[2]==3 && v[1]==1 && v[0]==1)
					{
						ans+=min(min(2*b+a,2*a+c),b+3*a);
						v[2]=0;
					}
					else if(v[2]==2 && v[1]==1 && v[0]==1)
					{
						ans+=2*b;
						v[2]=0;
					}
					else if(v[2]==1 && v[1]==1 && v[0]==1)
					{
						ans+=min(b+a,c);
						v[2]=0;
					}
				}
			}
		}
		else if(m==tc)
		{

		}
	}
}