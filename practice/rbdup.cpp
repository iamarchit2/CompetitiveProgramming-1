    #include<bits/stdc++.h>
    using namespace std;
    #define ull  long long int
    int main()
    {
      int t;
      cin>>t;
      while(t--)
      {
        ull n,m;
        cin>>n>>m;
        vector<pair<ull,ull> > red(n),blue(m);
        vector<ull> mr(((n-1)*n)/2);
        vector<ull> mb(((m-1)*m)/2);
        for(ull i=0;i<n;++i)
        {
          cin>>red[i].first>>red[i].second;
        }
        for(ull i=0;i<m;++i)
        {
          cin>>blue[i].first>>blue[i].second;
        }
        ull temp,x,y,p,q,s=0,t=0;
        for(ull i=0;i<n;++i)
        {
          for(ull j=i+1;j<n;++j)
          {
            p=q=0;
            for(ull k=0;k<m;++k)
            {
              x=blue[k].first;
              y=blue[k].second;
              temp=(y-red[i].second)*(red[i].first-red[j].first)-(x-red[i].first)*(red[i].second-red[j].second);
              if(temp<0)
              {
                p++;
              }
              else if(temp>0)
              {
                q++;
              }
            }
            for(ull k=0;k<n;++k)
            {
              x=red[k].first;
              y=red[k].second;
              temp=(y-red[i].second)*(red[i].first-red[j].first)-(x-red[i].first)*(red[i].second-red[j].second);
              if(temp<0)
              {
                q++;
              }
              else if(temp>0)
              {
                p++;
              }
            }
            mr[s++]=min(p,q); 
          }
        }
        for(ull i=0;i<m;++i)
        {
          for(ull j=i+1;j<m;++j)
          {
            p=q=0;
            for(ull k=0;k<m;++k)
            {
              x=blue[k].first;
              y=blue[k].second;
              temp=(y-blue[i].second)*(blue[i].first-blue[j].first)-(x-blue[i].first)*(blue[i].second-blue[j].second);
              if(temp<0)
              {
                p++;
              }
              else if(temp>0)
              {
                q++;
              }
            }
            for(ull k=0;k<n;++k)
            {
              x=red[k].first;
              y=red[k].second;
              temp=(y-blue[i].second)*(blue[i].first-blue[j].first)-(x-blue[i].first)*(blue[i].second-blue[j].second);
              if(temp<0)
              {
                q++;
              }
              else if(temp>0)
              {
                p++;
              }
            }
            mb[t++]=min(p,q); 
          }
        }

        for(ull i=0;i<mr.size();++i)
      cout<<mr[i]<<" ";
    cout<<endl;
    for(ull i=0;i<mb.size();++i)
      cout<<mb[i]<<" ";
    cout<<endl;
        if(n==1 && m==1)
        {
          cout<<0<<endl;
        }
        else if(n==1)
        {
          cout<<*min_element(mb.begin(),mb.end())<<endl;
        }
        else if(m==1)
        {
          cout<<*min_element(mr.begin(),mr.end())<<endl;
        }
        else
        {
          ull a=*min_element(mr.begin(),mr.end()),b=*min_element(mb.begin(),mb.end());
          ull ans=min(a,b);
          cout<<ans<<endl;
        }
        
      }
    } 