#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll n,m;
	cin>>n>>m;
	vector<vector<ll> > a(m+1);
	vector<ll> cnt(m+1);
	vector<pair<ll,ll> >cost;
	for(ll i=0;i<n;++i){
		ll x,y;
		cin>>x>>y;
		if(x!=1)	
		{
			cost.push_back(make_pair(y,x));
		}
		a[x].push_back(y);
		cnt[x]++;
	}
	for(ll i=2;i<=m;++i)
	{
		sort(a[i].begin(),a[i].end());
	}
	sort(cost.begin(),cost.end());
	ll ans=0;
	ll max=0,index=-1;
	for(ll i=1;i<=m;++i)
	{
		if(cnt[i]>max)
		{
			max=cnt[i];
			index=i;
		}
	}
	while(max>=cnt[1])
	{
		if(max==cnt[1])
		{
			for(ll i=2;i<=m;++i)
			{
				if(max==cnt[i])
				{
					ans+=cost[0].f;
					break;
				}
			}
			break;
		}
		else
		{
				
				if(a[index][0]<cost[0].f+cost[1].f)
				{
					ans+=a[index][0];
					a[index].erase(a[index].begin());
					cnt[1]++;
					cnt[index]--;
					for(ll i=1;i<=m;++i)
					{
						if(cnt[i]>max)
						{
							max=cnt[i];
							index=i;
						}
					}
				}
				else if(cost.size()>=3 && cnt[index]-cnt[1]>=2 && a[index][0]<cost[1].f+cost[2].f)
				{
					ans+=a[index][0]+cost[0].f;
					a[index].erase(a[index].begin());
					cnt[1]+=2;
					cnt[index]--;
					cnt[cost[0].s]--;
					cost.erase(cost.begin());
					for(ll i=1;i<=m;++i)
					{
						if(cnt[i]>max)
						{
							max=cnt[i];
							index=i;
						}
					}
				}
				else
				{
					ans+=cost[0].f+cost[1].f;
					cnt[cost[0].s]--;
					cnt[cost[1].s]--;
					cnt[1]+=2;
					cost.erase(cost.begin());
					cost.erase(cost.begin());
				}
				
			
		}
	}
	cout<<ans;
}