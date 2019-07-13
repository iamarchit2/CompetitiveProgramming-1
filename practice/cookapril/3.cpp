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
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		string res;
		if(n%2)
		{
			res="Win";
		}
		else
		{
			ll k=0,i=n;
			while(i%2==0)
			{
				k++;
				i/=2;
			}
			if(k%2)
			{
				res="Lose";
			}
			else
			{
				res="Win";
			}
		}
		cout<<res<<endl;;
		if(res=="Lose")
		{
			string check;
			cin>>check;
			if(check=="WA")
				exit(0);
			else
				continue;
		}
		else
		{
			while(n)
			{
				if(n==1)
				{
					cout<<"-1";
					n-=1;
				}
				else if(n%2==0)
				{
					cout<<"/2";
					n/=2;
				}
				else
				{
					if(((n+1)/2)%2)
					{
						cout<<"+1";
						n+=1;
					}
					else
					{
						cout<<"-1";
						n-=1;
					}
				}
				cout<<endl;
				string x;
				cin>>x;
				if(x=="WA")
				{
					exit(0);
				}
				else if(x=="GG")
				{
					break;
				}
				else 
				{
					if(x=="/2")
					{
						n/=2;
					}
					else if(x=="+1")
					{
						n+=1;
					}
					else
					{
						n-=1;
					}
					if(n==0)
					{
						exit(0);
					}
				}
			}
		}
	}
}
