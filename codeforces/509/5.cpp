#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<=b ; i++)
#define mp make_pair
#define INF 1000000000000000000
#define mod 1000000007
#define pi pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>
ll countMinReversals(string expr) 
{ 
    ll len = expr.length(); 
  
    // length of expression must be even to make 
    // it balanced by using reversals. 
    if (len%2) 
       return -1; 
  
    // After this loop, stack contains unbalanced 
    // part of expression, i.e., expression of the 
    // form "}}..}{{..{" 
    stack<char> s; 
    ll swaps=0;
    for (ll i=0; i<len; i++) 
    { 
        if (expr[i]==')' && !s.empty()) 
        { 
            if (s.top()=='(') 
                s.pop(); 
            else
                s.push(expr[i]); 
        } 
        else if(expr[i]==')' && s.empty())
        {
        	s.push('(');
        	swaps++;
        }
        else
            s.push(expr[i]); 
    } 
  
    // Length of the reduced expression 
    // red_len = (m+n) 
    ll red_len = s.size(); 
  
    // count opening brackets at the end of 
    // stack 
    ll n = 0; 
    while (!s.empty() && s.top() == ')') 
    { 
        s.pop(); 
        n++; 
    } 
  	swaps+=red_len/2 + n%2;
    // return ceil(m/2) + ceil(n/2) which is 
    // actually equal to (m+n)/2 + n%2 when 
    // m+n is even. 
    return (swaps); 
} 
  
int main()
{
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll t=countMinReversals(s);
	ll o=0,c=0;
	for(ll i=0;i<n;++i)
	{
		if(s[i]==')')
			c++;
		else
			o++;
	}
	ll ans=0;
	if(t!=1)
	{
		cout<<0<<endl;
	}
	else
	{
		for(ll i=0;i<s.size();++i)
		{
			if(s[i]==')' && i==0)
			{
				ans=1;
				break;
			}
			else if(s[i]=='(' && i==n-1)
			{
				ans=1;
				break;
			}
			else if(s[i]=='(' && i!=0)
			{
				if(o-1==c+1)
				{
					ans++;
				}
			} 
			else if(s[i]==')' && i!=n-1)
			{
				if(o+1==c-1)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}

}