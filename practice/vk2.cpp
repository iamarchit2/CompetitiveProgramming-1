    #include<bits/stdc++.h>
    using namespace std;
    #define ull unsigned long long int
    #define m 10000
    int main()
    {
        ull t;  
        vector<ull> b(m);
        ull k=0,rno,diamt=0;
        long long int diam=0;
        ull temp;
        for(ull i=0;i<m;++i)
        {
           for(ull j=0; i>=j;++j)
           {
             rno=2+i+j;
             diam=0;
             while(rno!=0)
             {
               temp=rno%10;
               if(temp%2==0)
                diam+= temp;
               else
                diam-=temp;
               rno=rno/10;  
             }
             diam=abs(diam);
             if(i==j)
             {
               diamt+=diam;
             }
             if(i>j)
             {
               diamt=diamt + 2*diam;
             }  
           }
           b[k++]=diamt;
        }
         //cout<<"hey"<<endl;
       
        cin>>t;
        while(t--)
        {
           ull n;
           cin>>n;
           cout<<b[n-1]<<endl;
        }
    } 