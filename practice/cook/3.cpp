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
		ll n;
		cin>>n;
		ui u;
		vi a(n),b(3);
		ll k=-1,sum=0,p=0;
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			p+=a[i];
			// if(a[i]==1 && k==-1)
			// {
			// 	k=i;
			// }
			// if(k!=-1)
			// {
			// 	sum+=a[i];
			// }
			b[a[i]]=1;
		}
		if(b[2]==0 || b[1]==0)
		{
			cout<<n<<endl;
		}
		else if(a[0]==1 || a[n-1]==1)
		{
			cout<<p<<endl;
		}
		else
		{
			ll i=0,q=0;
			while(a[i]!=1)
			{
				q+=a[i];
				i++;
			}
			ll j=n-1,w=0;
			while(a[j]!=1)
			{
				w+=a[j];
				j--;
			}
			sum=p-q-w;
			if(q>=w)
			{
				sum+=q;
				sum+=n-j-1;
			}
			else
			{
				sum+=w;
				sum+=i;
			}
			cout<<sum<<endl;
		}
	}
}