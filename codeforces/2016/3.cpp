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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;cin>>n;
		vi a(n);
		ll neg=0,neg1=0,pos=0,pos1=0,temp=0;
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			if(a[i]<-1)
			{
				neg++;
				if(neg==2)
				{
					temp=1;
				}
			}
			else if(a[i]==-1)
			{
				neg1++;
			}
			else if(a[i]>1)
			{
				pos++;
				if(pos==2)
				{
					temp=1;
				}
			}
			else if(a[i]==1)
			{
				pos1++;
			}
		}
		if(temp)
		{
			cout<<"no"<<endl;
			continue;
		}
		if(neg==1 && (neg1>=1 || pos==1))
		{
			cout<<"no"<<endl;
		}
		else if((neg1>=1 && pos==1) || (neg1>1 && pos1==0))
		{
			cout<<"no"<<endl;
		}
		else
		{
			cout<<"yes"<<endl;
		}
	}
}