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

int main()
{
	ll t;
	t=1;
	// cin>>t;
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		// vi a(n);
		// for(ll i=0;i<n;++i)
		// {
		// 	cin>>a[i];
		// }
		vpi a(q);
		for(ll i=0;i<q;++i)
		{
			cin>>a[i].f>>a[i].s;
		}
		vector<vi> two(n+1);
		for(ll i=0;i<q;++i)
		{
			for(ll j=a[i].f;j<=a[i].s;++j)
			{
				two[j].pb(i);
			}
		}
		// for(ll i=1;i<=n;++i)
		// {
		// 	for(ll j=0;j<two[i].size();++j)
		// 	{
		// 		cout<<two[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		vi temp(q,0);
		for(ll i=1;i<=n;++i)
		{
			if(two[i].size()==1)
			{
				temp[two[i][0]]++;
			}
		}
		// for(ll i=0;i<q;++i)
		// {
		// 	cout<<temp[i]<<" ";
		// }
		ll min=100000;
		ll ctr=0;
		ll index=-1;
		for(ll i=0;i<q;++i)
		{
			if(temp[i]<min)
			{
				min=temp[i];
				index=i;
			}
		}
		ctr+=min;
		// cout<<ctr<<endl;
		// temp.clear();
		for(ll i=1;i<=n;++i)
		{
			if(two[i].size()==2 && (two[i][0]==index || two[i][1]==index))
			{
				if(two[i][0]==index)
				{
					temp[two[i][1]]++;
				}
				else
				{
					temp[two[i][0]]++;
				}
			}
		}
		// for(ll i=0;i<q;++i)
		// {
		// 	cout<<temp[i];
		// }
		min=100000;
		for(ll i=0;i<q;++i)
		{
			if(temp[i]<min && i!=index)
			{
				min=temp[i];
			}
		}
		ctr+=min;
		for(ll i=1;i<=n;++i)
		{
			if(two[i].size()==0)
				ctr++;
		}
		// cout<<min<<" "<<ctr;
		cout<<n-ctr<<endl;
	}
}
