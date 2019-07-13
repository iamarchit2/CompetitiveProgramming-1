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
void print1D(vi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
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
		vector<pair<pair<ll,char>,string> > a(n),c;
		vi b(n);
		string x;
		// map<pair<ll,char>,ll> m;
		// map
		for(ll i=0;i<n;++i)
		{
			cin>>x;
			a[i].s=x;
			for(ll j=0;j<x.size();++j)
			{
				if(x[j]=='a' || x[j]=='e' || x[j]=='i' || x[j]=='o' || x[j]=='u' )
				{
					a[i].f.f++;
					a[i].f.s=x[j];
					b[i]++;
				}
			}
			// m[a[i]]+=1;
		}
		sort(a.begin(), a.end());
		// for(ll i=0;i<n;++i)
		// {
		// 	cout<<a[i].f.f<<" "<<a[i].f.s<<" "<<a[i].s<<endl;
		// }
		vector<vector<string> > lyrics(n,vector<string>(4," "));
		// cout<<lyrics.size()<<endl;
		// vector<string> temp(4);
		vector<ll> v(n);
		ll k=0;
		ll count=1;
		v[0]=1;
		lyrics[0][1]=a[0].s;
		ll i;
		for(i=1;i<n;++i)
		{
			// if(k>=lyrics.size())
			// 	break;
			// cout<<k;
			if(a[i].f.f==a[i-1].f.f && a[i].f.s==a[i-1].f.s)
			{
				v[i]=1;
				count++;
				if(count%2)
					lyrics[k][1]=a[i].s;
				else
				{
					lyrics[k][3]=a[i].s;
					k++;
				}

			}
			else
			{
				if(count%2)
				{
					v[i-1]=0;
					c.pb(a[i-1]);
					lyrics[k][1]=" ";
				}
				count=1;
				v[i]=1;
				lyrics[k][1]=a[i].s;
			}
		}
		if(count%2)
		{
			v[i-1]=0;
			c.pb(a[i-1]);
			lyrics[k][1]=" ";
		}
		// cout<<endl;
		// for(k=0;k<lyrics.size();++k)
		// {
		// 	cout<<lyrics[k][0]<<" "<<lyrics[k][1]<<endl<<lyrics[k][2]<<" "<<lyrics[k][3]<<endl;
		// }
		// cout<<endl<<lyrics[k][1]<<endl;
		sort(c.begin(), c.end());
		// for(ll i=0;i<c.size();++i)
		// {
		// 	cout<<c[i].f.f<<" "<<c[i].f.s<<" "<<c[i].s<<endl;
		// }
		k=0;
		count=1;
		if(c.size())
			lyrics[0][0]=c[0].s;
		for(i=1;i<c.size();++i)
		{
			if(c[i].f.f==c[i-1].f.f )
			{
				count++;
				if(count%2)
					lyrics[k][0]=c[i].s;
				else
				{
					lyrics[k][2]=c[i].s;
					k++;
				}
			}
			else
			{
				if(count%2)
				{
					lyrics[k][0]=" ";
				}
				count=1;
				lyrics[k][0]=c[i].s;
			}
		}
		if(count%2)
		{
			lyrics[k][0]=" ";
		}
		// for(k=0;k<lyrics.size();++k)
		// {
		// 	cout<<lyrics[k][0]<<" "<<lyrics[k][1]<<endl<<lyrics[k][2]<<" "<<lyrics[k][3]<<endl;
		// }
		ll p=0,q=0;
		k=0;
		while(1)
		{
			if(lyrics[k][1]==" ")
				break;
			else
				p++;
			if(lyrics[k][0]!=" ")
				q++;
			k++;
		}
		// cout<<p<<" "<<q<<endl;
		// p-=q;
		for(k=q;k<p-1;k+=2)
		{
			lyrics[k][0]=lyrics[k+1][1];
			lyrics[k][2]=lyrics[k+1][3];

			q++;
		}
		cout<<q<<endl;
		for(k=0,i=0;i<q;++k)
		{
			if(lyrics[k][0]==" ")
				continue;
			cout<<lyrics[k][0]<<" "<<lyrics[k][1]<<endl<<lyrics[k][2]<<" "<<lyrics[k][3]<<endl;
			i++;
		}
		// map<pair<ll,char>,ll>::iterator it;
	}
}

