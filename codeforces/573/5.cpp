#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<b ; i++)
#define mp make_pair
#define INF 1000000000000000000
#define mod 1000000007
#define pi pair<ll,ll>
#define vi vector<ll>
#define vvi vector<vi>
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>
#define sortA(a) sort(a.begin(),a.end())
#define sortD(a) sort(a.begin(),a.end(),greater<int>())
#define all(a) (a.begin(),a.end())
void print1D(vi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void print2D(vector<vi> a)
{
	for(ll i=0;i<a.size();++i)
	{
		for(ll j=0;j<a[i].size();++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t=1;
	// cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		string x;
		cin>>x;
		vi a;
		ll b=k;
		ll c=0;
		for(ll i=0;i<n;++i)
		{
			for(;i<n && i<b;++i)
			{
				if(x[i]=='0')
					c++;
			}
			i--;
			a.pb(c);
			c=0;
			b+=k;
		}
		ll p=count(a.begin(), a.end(),0);
		ll q=count(a.begin(), a.end(),k);
		if(a[a.size()-1]==(n%k))
			q++;
		cout<<p<<" "<<q;
		if(p==((n/k)+((n%k)!=0)-1) || p==((n/k)+((n%k)!=0)))
		{
			cout<<"tokitsukaze"<<endl;
			exit(0);
		}
		if(q==((n/k)+((n%k)!=0)-1) || q==((n/k)+((n%k)!=0)))
		{
			cout<<"tokitsukaze"<<endl;
			exit(0);
		}
		if(a.size()>2)
		{
			cout<<"once again"<<endl;
			exit(0);
		}
		else
		{
			cout<<"quailty"<<endl;
		}
	}
}
