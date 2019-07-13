#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second 
#define M 1000000007
ll cnt=0;
map<pair<ll,ll>,ll> u;
void gooddeed(ll c,ll good,ll bad,ll score,ll gl,ll bl);
void baddeed(ll c,ll good,ll bad,ll score,ll gl,ll bl);

bool pairfound(ll p,ll q)
{
	pair<ll,ll> temp=make_pair(p,q);
	if(u[temp]==1)
		return true;
	else 
		return false;

}
void gooddeed(ll c,ll good,ll bad,ll score,ll gl,ll bl)
{
//cout<<"*";	
	if(pairfound(good,bad))
		return;
//cout<<"*";		
	if(gl==0 && bl==0)
	{
		cnt=(cnt+1)%M;
		return;
	}
	if(gl!=0)
	{
		gooddeed(c,good+1,bad,score+1,gl-1,bl);
	}
	if(bl!=0 && score>c)
	{
		baddeed(c,good,bad+1,score-1,gl,bl-1);
	}
}
void baddeed(ll c,ll good,ll bad,ll score,ll gl,ll bl)
{
	if(pairfound(good,bad))
		return;
	if(gl==0 && bl==0)
	{
		cnt=(cnt+1)%M;
		return;
	}
	if(gl!=0)
	{
		gooddeed(c,good+1,bad,score+1,gl-1,bl);
	}
	if(bl!=0 && score>c)
	{
		baddeed(c,good,bad+1,score-1,gl,bl-1);
	}
}
int main()
{
	ll t=1;
	while(t--)
  {	ll p,q,c,m;
	cin>>p>>q>>c>>m;
	vector<pair<ll,ll> > a(m);
	//vector<pair<ll,ll> > a(m),b(m);
	for(ll i=0;i<m;++i)
	{
		cin>>a[i].f>>a[i].s;
		u[a[i]]=1;
		//a[i].s=b[i].s=i;
	}
	// sort(a.begin(),a.end());
	// sort(b.begin(),b.end());
	if(p-q<c && q!=0)
		{cout<<0<<endl;continue;}
	if(q==0)
	{
		ll flag=0,i=0;
		for( i=0;i<m;++i)
		{
			if(a[i].s==0 && a[i].f<=p)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			{cout<<0<<endl;continue;}
		else
			{cout<<1<<endl;continue;}
	}
	ll flag=0,i=0;
	for( i=0;i<m;++i)
	{
		if(a[i].s==0 && a[i].f<=c+1)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		{cout<<0<<endl;continue;}
	ll good=c,bad=0,score=c,gl=p-c,bl=q;
	gooddeed(c,good+1,bad,score+1,gl-1,bl);
	cout<<cnt<<endl;
  }
}