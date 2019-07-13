#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		vector<vector<ll> > b(n);
		b[0]=a;
		for(ll i=1;i<n;++i)
		{
			for(ll j=0,k=i;k<b[0].size();++j,++k)
			{
				b[i].push_back(((b[i-1][j]%M)*(b[0][k]%M))%M);
			}
		}
		
		ll sum=0;
		vector<ll> c(n);
		for(ll i=0;i<n-2;++i)
		{
			ll temp=*(b[i].begin())+*(b[i].end()-1);
			c[i]=accumulate(b[i].begin(),b[i].end(),temp)%M;
			c[i]=(((ll)((pow(2,n-3-i)))%M)*(c[i]%M))%M;
			sum=(sum%M+c[i]%M)%M;
		}
		sum=(sum%M+b[n-2][0]%M+b[n-2][1]%M+b[n-1][0]%M)%M;
		cout<<sum<<endl;
	}
}