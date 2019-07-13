#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
int main()
{
	ull t;
	cin>>t;
	while(t--)
	{
		vector<ull> pos(3),temp(3);
		ull A,B,C;
		for(ull i=0;i<3;++i)
		{
			cin>>pos[i];
		}
		cin>>A>>B>>C;
		ull a=6*A,b=3*B,c=2*C;
        ull m=min(min(a,b),c);
        sort(pos.begin(),pos.end());
        temp=pos;
        ull ans=0;
        
        
        	if(m==a){ ans=(pos[0]+pos[1]+pos[2])*A;}
        	         
        	else if(m==b) {
        		        if(pos[0]+pos[1]<=pos[2])
        		        {
        		        	ans+=(pos[0]+pos[1])*B;
        		        	temp[2]-=(temp[0]+temp[1]);
        		        }
        		        else
                       	{
                       		ans+=((pos[0]+pos[1]+pos[2])/2)*B;
                       		temp[2]=(pos[0]+pos[1]+pos[2])%2;
                        }
                        if(A+B>C)
                       	{
                       		if(temp[2]>pos[0])
                       		{
                       			ans-=pos[0]*B;
                       		    ans+=pos[0]*C;
                       		    ans+=(temp[2]-pos[0])*A;
                       	    }
                       	    else
                       	    {
                       	    	ans-=temp[2]*B;
                       	    	ans+=temp[2]*C;
                       	    }
                       	}
                       	else
                       	{
                       		ans+=(temp[2])*A;
                       	}
                       
        	        }
        	else if(m==c){
                       ans+=temp[0]*C;
                       temp[1]-=temp[0];temp[2]-=temp[0];temp[0]=0;
                       if(a<=b)
                       {
                       	ans+=(temp[1]+temp[2])*A;
                       }
                       else
                       {
                       	ans+=temp[1]*B;
                       	temp[2]-=temp[1];
                       	temp[1]=0;
                       	if(A+C>2*B)
                       	{
                       		if(temp[2]>pos[0])
                       		{
                       			ans-=pos[0]*C;
                       			ans+=2*pos[0]*B;
                       			ans+=(temp[2]-pos[0])*A;
                       		}
                       		else
                       		{
                       			ans-=temp[2]*C;
                       			ans+=2*temp[2]*B;
                       		}
                       	} 
                       	else
                       	{
                       		ans+=temp[2]*A;
                       	}            
                       }
                      
        	       }          

        
        cout<<ans<<endl;

	}
}