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
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>
// #define sort(a) sort(a.begin(),a.end())
void print1D(vpi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i].f<<" "<<a[i].s<<endl;
	}
	// cout<<endl;
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
bool fun(pi a,pi b)
{
	if(a.f>b.f)
		return true;
	else if(a.f==b.f && a.s>b.s)
		return true;
	else return false;

}
int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t=1;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vpi a(n);
		vpi b(n+1);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i].f;
			cin>>a[i].s;
			b[a[i].f].f++;
			if(a[i].s==1)
				b[a[i].f].s++;
		}
		sort(b.begin(), b.end(),fun);
		// for(ll i=1;i<n;++i)
		// {

		// }
		// print1D(b);
		ll k=b[0].f,i=0,ans=0,a2=0;
		while(k && i<b.size()&& b[i].f)
		{
			k=min(k,b[i].f);
			if(i+1<b.size() && b[i+1].f==k && b[i+1].s>b[i].s)
			{
				i++;
				continue;
			}
			ans+=k;
			a2+=min(k,b[i].s);
			k--;
			i++;
		}
		cout<<ans<<" "<<a2<<endl;
	}
}
