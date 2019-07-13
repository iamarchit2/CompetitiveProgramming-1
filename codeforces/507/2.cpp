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
	ll n,k;
	cin>>n>>k;
	ll a=2*k+1;
	ll b=n%a;
	if(n<a && b<k)
	{
		cout<<1<<endl<<1;
		exit(0);
	}
	vector<ll> ans;
	if(b>k || b==0)
	{
		ll i=k+1;
		
		while(i<=n)
		{
			ans.push_back(i);
			i+=a;
		}

	}	
	else
	{
		ll i,j,temp=0;;
		for(i=k+1;i<=2*k;++i)
		{
			for(j=1;j<=2*k;++j)
			{
				if((n-(i+j))%a==0)
				{
					temp=1;
					break;
				}
			}
			if(temp==1)
				break;
		}
		ll z=i-k;
		while(z<=n)
		{
			ans.push_back(z);
			z+=a;
		}
	}
	cout<<ans.size()<<endl;
	for(ll i=0;i<ans.size();++i)
	{
		cout<<ans[i]<<" ";
	}
}