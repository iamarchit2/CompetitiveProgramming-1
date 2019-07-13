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
string findsum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    ll n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    ll carry = 0; 
    for (ll i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        ll sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (ll i=n1; i<n2; i++) 
    { 
        ll sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t=1;
	// cin>>t;
	while(t--)
	{
		ll n;
		string a;
		cin>>n>>a;
		string b="",c="",d="",e="";
		for(ll i=0,j=n-1;i<=j;++i,--j)
		{
			if(i==j)
			{
				b+=a[i];
				e+=a[i];
				break;
			}
			b+=a[i];
			d+=a[i];
			c+=a[j];
			e+=a[j];
		}
		reverse(c.begin(), c.end());
		reverse(e.begin(), e.end());
		while(c[0]=='0')
		{
			b+=c[0];
			c.erase(c.begin());
		}
		while(e[0]=='0')
		{
			e.insert(0,1,d[d.size()-1]);
			d.pop_back();
		}
		// cout<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
		string x=findsum(b,c);
		string y=findsum(d,e);
		string ans=x;
		if(x.size()>y.size())
			ans=y;
		else if(y.size()>x.size())
			ans=x;
		else
		{
			for(ll i=0;i<x.size();++i)
			{
				if(x[i]<y[i])
				{
					ans=x;
					break;
				}
				else if(x[i]>y[i])
				{
					ans=y;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
}
