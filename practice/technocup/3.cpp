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

int main()
{
	ll n;
	cin>>n;
	string p;
	cin>>p;
	if(n==1)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	vi a(n);
	ll m=0,sum=0;
	for(ll i=0;i<n;++i)
	{
		a[i]=p[i]-'0';
		sum+=a[i];
		m=max(m,a[i]);
	}
	if(sum==1)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	if(sum==0)
	{
		cout<<"YES"<<endl;
		exit(0);
	}
	for(ll i=m;i<=sum/2;++i)
	{
		if(sum%i!=0)
		{
			continue;
		}
		ll t=0,temp=1;
		for(ll j=0;j<n;++j)
		{
			temp=1;
			t+=a[j];
			if(t==i)
			{
				t=0;
			}
			else if(t>i)
			{
				temp=0;
				break;
			}
		}
		if(temp==1)
		{
			cout<<"YES";
			exit(0);
		}
	}
	cout<<"NO";
}