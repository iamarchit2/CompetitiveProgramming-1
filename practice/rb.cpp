#include<bits/stdc++.h>
using namespace std;
#define ull  long long int
ull temp,x,y;
void f1(ull size,vector<pair<ull,ull> > points,vector<pair<ull,ull> > line,ull i,ull j,vector<pair<ull,ull> > &n,vector<pair<ull,ull> > &p)
{
  for(ull k=0;k<size;++k)
  {
//cout<<"f1";    
    x=points[k].first;
    y=points[k].second;
    temp=(y-line[i].second)*(line[i].first-line[j].first)-(x-line[i].first)*(line[i].second-line[j].second);
    if(temp<0)
    {
      n.push_back(points[k]);
    }
    else if(temp>0)
    {
      p.push_back(points[k]);
    }
  }
}
void f2(ull size,vector<pair<ull,ull> > &points,vector<pair<ull,ull> > line,ull i,ull j,vector<pair<ull,ull> > &n,vector<pair<ull,ull> > &p)
{
  for(ull k=0;k<size;++k)
  {
//cout<<"f2";    
    x=points[k].first;
    y=points[k].second;
    temp=(y-line[i].second)*(line[i].first-line[j].first)-(x-line[i].first)*(line[i].second-line[j].second);
    if(temp<0)
    {
      ;
    }
    else if(temp>0)
    {
      p.push_back(n[k]);
      n.erase(n.begin()+k);
      k--;
      size--;
    }
    else
    {
      n.erase(n.begin()+k);
      k--;
      size--;
    }
 }
}
void f3(ull size,vector<pair<ull,ull> > &points,vector<pair<ull,ull> > line,ull i,ull j,vector<pair<ull,ull> > &n,vector<pair<ull,ull> > &p)
{
  for(ull k=0;k<size;++k)
  {
//cout<<"f3";    
    x=points[k].first;
    y=points[k].second;
    temp=(y-line[i].second)*(line[i].first-line[j].first)-(x-line[i].first)*(line[i].second-line[j].second);
    if(temp>0)
    {
      ;
    }
    else if(temp<0)
    {
      n.push_back(p[k]);
      p.erase(p.begin()+k);
      k--;
      size--;
    }
    else
    {
      p.erase(p.begin()+k);
      k--;
      size--;
    }
  }
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    ull n,m;
    cin>>n>>m;
    vector<pair<ull,ull> > red(n),blue(m),nr,pr,nb,pb;;
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
//cout<<"*";    
    ull j,p,q,s=0,t=0;
    for(ull i=0;i<n;++i)
    {
      nb.clear();
      pb.clear();
      nr.clear();
      pr.clear();
//cout<<"@";      
        j=i+1;
        if(j<n)
        {
//cout<<"#";          
          f1(m,blue,red,i,j,nb,pb);
          f1(n,red,red,i,j,nr,pr);
          p=nb.size()+pr.size();
          q=nr.size()+pb.size();
          mr[s++]=min(p,q);
        } 
      for(j=i+2;j<n;++j)
      {
//cout<<"&";        
          x=red[j].first;
          y=red[j].second;
          temp=(y-red[i].second)*(red[i].first-red[j-1].first)-(x-red[i].first)*(red[i].second-red[j-1].second);
          if(temp<0)
          {
            pr.push_back(red[j-1]);
            f2(nb.size(),nb,red,i,j,nb,pb);
            f2(nr.size(),nr,red,i,j,nr,pr);
          }
          else if(temp>0)
          {
            nr.push_back(red[j-1]);
            f3(pb.size(),pb,red,i,j,nb,pb);
            f3(pr.size(),pr,red,i,j,nr,pr);  
          }
        
         if (j==3 && i==1)
          {  cout<<"\n\n";
            for(ull i=0;i<pr.size();++i)
            cout<<pr[i].first<<","<<pr[i].second<<"  ";
          cout<<endl;
           for(ull i=0;i<nr.size();++i)
            cout<<nr[i].first<<","<<nr[i].second<<"  ";
          cout<<endl;
           for(ull i=0;i<pb.size();++i)
            cout<<pb[i].first<<","<<pb[i].second<<"  ";
          cout<<endl;
           for(ull i=0;i<nb.size();++i)
            cout<<nb[i].first<<","<<nb[i].second<<"  ";
          cout<<endl;
          cout<<"\n\n";
        }

         
        p=nb.size()+pr.size();
        q=nr.size()+pb.size();
        mr[s++]=min(p,q); 
      }
    }
    
    
    for(ull i=0;i<m;++i)
    {
      nb.clear();
      pb.clear();
      nr.clear();
      pr.clear();
        j=i+1;
        if(j<m)
        {
          f1(m,blue,blue,i,j,nb,pb);
          f1(n,red,blue,i,j,nr,pr);
          p=nb.size()+pr.size();
          q=nr.size()+pb.size();
          mb[t++]=min(p,q);
        } 
      for(j=i+2;j<m;++j)
      {
          x=blue[j].first;
          y=blue[j].second;
          temp=(y-blue[i].second)*(blue[i].first-blue[j-1].first)-(x-blue[i].first)*(blue[i].second-blue[j-1].second);
          if(temp<0)
          {
            pb.push_back(blue[j-1]);
            f2(nb.size(),nb,blue,i,j,nb,pb);
            f2(nr.size(),nr,blue,i,j,nr,pr);
          }
          else if(temp>0)
          {
            nb.push_back(blue[j-1]);
            f3(pb.size(),pb,blue,i,j,nb,pb);
            f3(pr.size(),pr,blue,i,j,nr,pr);  
          }
        p=nb.size()+pr.size();
        q=nr.size()+pb.size();
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