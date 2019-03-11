#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<b ; i++)
#define mp make_pair
#define INF 1000000000000000000
#define mod 1000000007
#define pi pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>
	
bool f(vi c,vi a,vi b,ll p,vi &va,vi &vb,ll n,ll carry)
{
	if(p==n)
		return true;
	for(ll i=0;i<n;++i)
	{
		if(va[i]==1)
			continue;
		va[i]=1;
		for(ll j=0;j<n;++j)
		{
			if(vb[j]==1)
				continue;
			if((b[j]+a[i]+carry)%10==c[p])
			{
				vb[j]=1;
				// carry=(b[j]+a[i]+carry)/10;
				if(f(c,a,b,p+1,va,vb,n,(b[j]+a[i]+carry)/10))
				{
					return true;
				}
				else
				{
					vb[j]=0;
				}
			}
		}
		va[i]=0;
	}
	return false;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a,b,c;
		cin>>a>>b>>c;
		vi av,bv,cv;
		vi x,y;
		while(a)
		{
			av.pb(a%10);
			a=a/10;
		}
		while(b)
		{
			bv.pb(b%10);
			b=b/10;
		}
		while(c)
		{
			cv.pb(c%10);
			c=c/10;
		}
		while(av.size()!=n)
			av.pb(0);
		while(bv.size()!=n)
			bv.pb(0);
		while(cv.size()!=n)
			cv.pb(0);
		vi va(n),vb(n);
		for(ll i=0;i<n;++i)
		{
			cout<<av[i]<<" "<<bv[i]<<" "<<cv[i]<<endl;
		}
		ll zero=0;
		if(f(cv,av,bv,zero,va,vb,n,zero))
		{
			cout<<"YES"<<endl;
		}	
		else
		{
			cout<<"NO"<<endl;
		}
	}
}