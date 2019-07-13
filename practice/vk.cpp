    #include<bits/stdc++.h>
    using namespace std;
    #define ull unsigned long long int
    #define m 1000000
    int main()
    {
        ull t;  
        vector<ull> b(m+1),c(2*m+1,0);
        ull k=1,rno,temp=0;
        long long int diam=0;
        
        for(ull i=2;i<=2*m;++i)
        {
          rno=i;
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
             c[i]=diam;
        }
        b[k++]=2;
        ull tempd=0;
        ull a=2;
        temp=b[1];
        for(ull i=3;i<=2*m;++i)
        {
          if(i%2==0)
          {
            a++;
            tempd-=2*c[a];
            temp+=c[i];
            b[k++]=temp;
            tempd+=2*c[i];
            temp+=tempd;
          }
          else
          {
            tempd+=2*c[i];
            temp+=2*c[i];
          }
        }      
        cin>>t;
        
        while(t--)
        {
          ull n;
          cin>>n;
          cout<<b[n]<<endl;
        }
    } 