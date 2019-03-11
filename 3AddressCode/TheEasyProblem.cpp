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
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		string s;
		cin>>s;
		vi a(26);
		for(ll i=0;i<n;++i)
		{
			a[s[i]-'a']++;
		}
		ll ma=0,in=-1;

		for(ll i=0;i<26;++i)
		{
			if(a[i]>ma)
			{
				ma=a[i];
				in=i;
			}
		}
		char ch=in+'a';
		cout<<ch<<endl;
	}
}