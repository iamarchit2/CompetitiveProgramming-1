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
#define sort(a) sort(a.begin(),a.end())
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
		ll n,m;
		cin>>n>>m;
		priority_queue <ll> pq;
		priority_queue <int, vector<int>, greater<int> > pqmin;  
		vi a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		// b[0]=a[0];
		// for(ll i=1;i<n;++i)
		// {
		// 	b[i]=a[i]+b[i-1];
		// }
		// print1D(b);
		ll sum=0,count=0;
		for(ll i=0;i<n;++i)
		{
			sum+=a[i];
			while(sum>m)
			{
				ll k=pq.top();
				pqmin.push(k);
				pq.pop();
				sum-=k;
				count++;
			}
			while(1)
			{
				if(pqmin.size())
				{
					ll k=pqmin.top();
					sum+=k;
					if(sum<=m)
					{
						pq.push(k);
						count--;
						pqmin.pop();
					}
					else
					{
						sum-=k;
						break;
					}
				}
				else
					break;
				// cout<<pqmin.size();
			}
			cout<<count<<" ";
			pq.push(a[i]);
		}
		cout<<endl;
	}
}

