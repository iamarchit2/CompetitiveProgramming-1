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

int main()
{
	ll q;
	cin>>q;
	while(q--)
	{
		ll ans=0;
		ll n,m,k;
		cin>>n>>m>>k;
		n=abs(n);m=abs(m);
		ans+=min(n,m);
		ll t=max(n,m)-min(n,m);
		k-=min(n,m);
		if(t%2==0)
		{
			ans+=t;
			k-=t;
			if(k<0)
			{
				cout<<-1<<endl;
				continue;
			}
			if(k%2==0)
			{
				ans+=k;
			}
			else
			{
				ans-=1;
				k++;
				ans+=k-2;
			}
		}
		else
		{
			ans+=t-1;
			k-=t-1;
			if(k<1)
				{cout<<-1<<endl;
				 continue;}
			ans+=k-1;
		}
		cout<<ans<<endl;
	}
}