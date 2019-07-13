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
ll ans=0,k=1;
bool palindrome(string s,ll n)
{
	for(ll i=0,j=n-1;i<j;i++,j--)
		if(s[i]!=s[j])
			return false;
	return true;	
}
void f(string s,ll n)
{
	if(n%2==0)
	{
		ans++;
		if(palindrome(s,n/2))
			f(s,n/2);
	}
	else
	{
		ll t=1;
		for(ll i=0;i<n/2-1;++i)
		{
			if(s[i]!=s[i+1])
			{
				t=0;
				break;
			}
		}
		if(t)
		{
			cout<<"Impossible"<<endl;
		exit(0);
		}
		ans+=2;
		if(palindrome(s,n/2))
			f(s,n/2);
	}
}
int main()
{
	string s,a;
	cin>>s;
	ll t=1;
	for(ll i=0;i<s.size()-1;++i)
	{
		if(s[i]!=s[i+1])
		{
			t=0;
			break;
		}
	}
	if(t)
	{
		cout<<"Impossible"<<endl;
		exit(0);
	}
	// ll ans=0;
	// if(s.size()%2==0)
	// 	ans=1;
	// else
	// 	ans=2;
	f(s,s.size());
	cout<<ans<<endl;
}