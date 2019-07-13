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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,x,m;
		cin>>n>>x>>m;
		vi a(n+1);
		for(ll i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		ll mf=1,sf=0,df=1;
		ll ans=0;
		while(x)
		{
			ans=((ans%mod)+(a[x]%mod)*(mf%mod))%mod;
			x--;
			ll p,q;
			gcd_extended(df,mod,&p,&q);
			mf=((mf%mod)*((m+sf)%mod))%mod;
			// cout<<mf<<" "<<p;
			mf*=p; mf%=mod;
			// cout<<mf<<endl;
			// mf=((mf*(m+sf))/df)%mod;
			sf++;
			df++;
		}
		if(ans<0)
			ans+=mod;
		cout<<ans<<endl;
	}
}