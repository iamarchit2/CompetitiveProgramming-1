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
		um u,u2;
		ll n;
		cin>>n;
		vi a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			u[a[i]]++;
		}
		if(u[0]>=2)
		{
			cout<<"cslnb"<<endl;
				exit(0);
		}
		sortA(a);
		ll z=0,ind=-1;
		for(ll i=0;i<n;++i)
		{
			if(u2[a[i]])
				continue;
			u2[a[i]]=1;
			if(u[a[i]]>=3)
			{
				cout<<"cslnb"<<endl;
				exit(0);
			}
			if(u[a[i]]==2)
			{
				ind=i;
				z++;
				if(z>=2)
				{
					cout<<"cslnb"<<endl;
					exit(0);
				}
			}
		}
		// cout<<"!";
		ll c=0;
		if(z==1)
		{
			if(u[a[ind]-1])
			{
				cout<<"cslnb"<<endl;
				exit(0);
			}
			else
			{
				a[ind]--;
				c++;
			}
		}
		// cout<<c<<endl;
		for(ll i=0;i<n;++i)
		{
			c+=max((ll)0,a[i]-i);
		}
		// cout<<c<<endl;
		if(c%2==0)
		{
			cout<<"cslnb"<<endl;
		}
		else
		{
			cout<<"sjfnb"<<endl;
		}
	}
}
