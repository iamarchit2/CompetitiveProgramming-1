#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<=b ; i++)
#define mp make_pair
#define INF 1000000000000000000
#define mod 1000000007
#define pi pair<ll,ll>
#define vi vector<ll>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>
ll check(vector<string> &a/*vector<vi> &a*/,ll i,ll j,ll fi,ll fj)
{
	// cout<<endl<<a.size()<<" "<<a[0].size();
	ll v=0;
	if(a[i][j]==a[i-1][j-1] && a[i][j]!=a[i-1][j] && a[i][j]!=a[i][j-1])
		return 0;
	if(a[i-fi][j-fj]!=a[i][j])
	{
		a[i][j]=a[i-fi][j-fj];
		v++;
	}
	if(a[i-fi][j-fj]!=a[i-1][j-1])
	{
		a[i-1][j-1]=a[i-fi][j-fj];
		v++;
	}
	if(a[i-fi][j-fj]==a[i-1][j])
	{
		if(a[i-fi][j-fj])
			a[i-1][j]=0;
		else
			a[i-1][j]=1;
		v++;
	}
	if(a[i-fi][j-fj]==a[i][j-1])
	{
		if(a[i-fi][j-fj])
			a[i][j-1]=0;
		else
			a[i][j-1]=1;
		v++;
	}
	return v;
}

int main()
{
	ll n,m;
	cin>>n>>m;
	ll k=min(n,m);
	vector<string> a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	// vector<vi> a(n,vi(m,0));
	vector<vi> M(n+1,vi(m+1,1));
	for(ll i=1;i<n;++i)
	{
		for(ll j=1;j<m;++j)
		{
			if(a[i][j]==a[i-1][j-1] && a[i][j]!=a[i-1][j] && a[i][j]!=a[i][j-1])
			{
				M[i][j]=min(M[i-1][j-1],min(M[i][j-1],M[i-1][j]))+1;
			}
			else
			{
				M[i][j]=1;
			}
		}
	}
	ll mx=1,ctr=0;
	ll x,y;
	for(ll i=1;i<n;++i)
	{
		for(ll j=1;j<m;++j)
		{
			if(M[i][j]>mx)
			{
				mx=M[i][j];
				x=i;y=j;
				ctr=0;
			}
			if(M[i][j]==mx)
			{
				ll t=(M[i-1][j-1]==mx)+(M[i-1][j]==mx)+(M[i-1][j+1]==mx)+(M[i][j-1]==mx)+(M[i+1][j-1]==mx)+(M[i+1][j]==mx)+(M[i][j+1]==mx)+(M[i+1][j+1]==mx);
				if(t>ctr)
				{
					ctr=t;
					x=i;y=j;
				}
			}
		}
	}
	// cout<<x<<y;
	vi ans(201,-1);
	ans[mx]=0;
	ll c=0;
	while(mx!=k)
	{
		ll p,q,r,s;
		p=q=r=s=INF;
		vector<string> pa,qa,ra,sa;
		// vector<vi> pa,qa,ra,sa;
		pa=qa=ra=sa=a;
		ll x1=x-mx+1,y1=y-mx+1;
		if(x1!=0 && y1!=0)
		{
			p=0;
			for(ll i=x1,j=y1;i<=x;++i)
			{
				p+=check(pa,i,j,0,0);
			}
			for(ll i=x1,j=y1;j<=y;++j)
			{
				p+=check(pa,i,j,0,0);
			}
			
		}
		
		if(x+1!=n && y1!=0)
		{
			q=0;
			for(ll i=x+1,j=y;j>=y1;--j)
			{
				q+=check(qa,i,j,1,1);
			}
			for(ll i=x,j=y1;i>x1;--i)
			{
				q+=check(qa,i,j,0,0);
			}
		}

		if(x1!=0 && y+1!=m)
		{
			r=0;
			for(ll i=x1,j=y1+1;j<=y;++j)
			{
				r+=check(ra,i,j,0,0);
			}
			for(ll i=x1,j=y+1;i<=x;++i)
			{
				r+=check(ra,i,j,1,1);
			}
		}

		if(x+1!=n && y+1!=m)
		{
			s=0;
			for(ll i=x+1,j=y+1;i>x1;--i)
			{
				s+=check(sa,i,j,1,1);
			}
			for(ll i=x+1,j=y+1;j>y1;--j)
			{
				s+=check(sa,i,j,1,1);
			}
		}
		ll t=min(p,min(q,min(r,s)));
		if(t==p)
		{
			mx++;
			a=pa;
		}
		else if(t==q)
		{
			x=x+1;
			mx++;
			a=qa;
		}
		else if(t==r)
		{
			y=y+1;mx++;
			a=ra;
		}
		else if(t==s)
		{
			x=x+1;
			y=y+1;
			mx++;
			a=sa;
		}
		c+=t;
		ans[mx]=c;
	}
	// for(ll i=0;i<200;++i)
	// {
	// 	cout<<ans[i]<<" ";
	// }
	ll q;
	cin>>q;
	while(q--)
	{
		ll c;
		cin>>c;
		ll i=k;
		while(1)
		{
			if(c>=ans[i])
			{
				cout<<i<<endl;
				break;
			}
			i--;
		}
	}
}