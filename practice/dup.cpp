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
		ull a,b,c;
		for(ull i=0;i<3;++i)
		{
			cin>>pos[i];
		}
		cin>>a>>b>>c;
		ull p=6*a,q=3*b,r=2*c;
        ull m=min(min(p,q),r);
        sort(pos.begin(),pos.end());
        temp=pos;
        ull ans=0;
        
        
        	if(m==p){ ans=(pos[0]+pos[1]+pos[2])*a;}
        	         
        	else if(m==q) {
        		         if(pos[2]>=(pos[1]+pos[0]))

                                                 ans=(pos[0]+pos[1])*b+(pos[2]-pos[1]-pos[0])*a;

                                          else if((pos[0]+pos[1]+pos[2])%2==0)

                                                 ans=(pos[0]+pos[1]+pos[2])*b/2;

                                          else

                                          {      

                                                 if(a+b<=c)

                                                 ans=(((pos[0]+pos[1]+pos[2])/2)*b)+a;

                                                 else

                                                 ans=((((pos[0]+pos[1]+pos[2])/2)-1)*b)+c;

                                          }

                                          

                              }
                       
        	        
        	else if(m==r){
                        if(a*2<=b)

                                                ans=(pos[0]*c)+(pos[2]+pos[1]-(2*pos[0]))*a; 

                                           else if (a+c<=2*b)

                                                ans=(pos[0]*c)+((pos[1]-pos[0])*b)+((pos[2]-pos[1])*a);

                                           else

                                           {

                                                  if(pos[2]<=(pos[0]+pos[1]))

                                                        ans=(pos[0]+pos[1]-pos[2])*c+(2*pos[2]-pos[1]-pos[0])*b;

                                                  else

                                                        ans=(pos[0]+pos[1])*b+(pos[2]-pos[1]-pos[0])*a;

                                           }

                                           


        	       }          

        
        cout<<ans<<endl;

	}
}