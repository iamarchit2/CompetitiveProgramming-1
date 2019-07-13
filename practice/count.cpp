#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<=b ; i++)
#define mp make_pair
#define INF 1000000000000000000
#define mod 1000003
#define pi pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>
void gcd_extended(ll a,ll b,ll*x,ll*y){
	if(b==0){
		*x=1;	*y=0;	return;
	}
	ll x1,y1;
	gcd_extended(b,a%b,&x1,&y1);
	*x=y1;	*y=x1-(a/b)*y1;	return;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll N,l,r;
		cin>>N>>l>>r;
		ll n=r-l+1;
		N=min(N,n);
		ll k=n,ans=0;
		for(ll i=1,j=N;i<=N;++i,j--)
		{
			ans+=((j%mod)*(i%mod)*(k%mod)*(k%mod))%mod;
			ans%=mod;
			k=((k%mod)*((n-i)%mod))%mod;
			ll p,q;
			gcd_extended(i+1,mod,&p,&q);
			k*=p; k%=mod;
		}
		ll p,q;
		gcd_extended(n,mod,&p,&q);
		ans*=p; ans%=mod;
		if(ans<0)
			ans+=mod;	
		cout<<ans<<endl;
	}
}