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
		ll n;
		cin>>n;
		vpi a(n);
		vi b;
		for(ll i=0;i<n;++i)
		{
			cin>>a[i].f;
			a[i].s=i+1;
		}
		if(n<=3)
		{
			cout<<1<<endl;
			continue;
		}
		sort(a);
		for(ll i=1;i<n;++i)
		{
			b.pb(a[i].f-a[i-1].f);
		}
		print1D(b);
		if(n==4)
		{
			if(b[1]==b[2])
			{
				cout<<a[0].s<<endl;
				continue;
			}
			if(b[0]==b[1])
			{
				cout<<a[3].s<<endl;
				continue;
			}
			else
			{
				ll k=*max_element(b.begin(),b.end());
			cout<<k<<endl;;
			ll ans=1,f=0,x=1;
			for(ll i=0;i<b.size();++i)
			{
				if(b[i]==k)
					continue;
				else if(x)
				{
					x=0;
					// if(i==0)
					// {
					// 	f=1;
					// 	ans=a[0].s;
					// }
					else if(i==b.size()-1)
					{
						f=1;
						ans=a[i+1].s;
					}
					else if((b[i]+b[i+1])==k)
					{
						f=1;
						ans=a[i+1].s;
						i++;
					}
					else
					{
						f=0;
						break;
					}
				}
				else
				{
					f=0;
					break;
				}
			}
			if(f)
				cout<<ans<<endl;
			else if(x)
				cout<<1<<endl;
			else
				cout<<-1<<endl;	
			continue;
			}
		}
		if(n==5)
		{
			if(b[1]==b[2]&& b[2]==b[3])
			{
				cout<<a[0].s<<endl;
				continue;
			}
			if(b[0]==b[1] && b[1]==b[2])
			{
				cout<<a[4].s<<endl;
				continue;
			}
			else
			{
				ll k=*max_element(b.begin(),b.end());
			// cout<<k<<endl;;
			ll ans=1,f=0,x=1;
			for(ll i=0;i<b.size();++i)
			{
				if(b[i]==k)
					continue;
				else if(x)
				{
					x=0;
					if(i==0)
					{
						f=1;
						ans=a[0].s;
					}
					else if(i==b.size()-1)
					{
						f=1;
						ans=a[i+1].s;
					}
					else if((b[i]+b[i+1])==k)
					{
						f=1;
						ans=a[i+1].s;
						i++;
					}
					else
					{
						f=0;
						break;
					}
				}
				else
				{
					f=0;
					break;
				}
			}
			if(f)
				cout<<ans<<endl;
			else if(x)
				cout<<1<<endl;
			else
				cout<<-1<<endl;	
			continue;
			}
		}
		// print1D(b);
		ll k=*max_element(b.begin()+1,b.end()-1);
		// cout<<k<<endl;;
		ll ans=1,f=0,x=1;
		for(ll i=0;i<b.size();++i)
		{
			if(b[i]==k)
				continue;
			else if(x)
			{
				x=0;
				if(i==0)
				{
					f=1;
					ans=a[0].s;
				}
				else if(i==b.size()-1)
				{
					f=1;
					ans=a[i+1].s;
				}
				else if((b[i]+b[i+1])==k)
				{
					f=1;
					ans=a[i+1].s;
					i++;
				}
				else
				{
					f=0;
					break;
				}
			}
			else
			{
				f=0;
				break;
			}
		}
		if(f)
			cout<<ans<<endl;
		else if(x)
			cout<<1<<endl;
		else
			cout<<-1<<endl;
	}
}

