#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007
// Multiplies str1 and str2, and prints result.
string multiply(string num1, string num2)
{
    ll n1 = num1.size();
    ll n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";
 
    // will keep the result number in vector
    // in reverse order
    vector<ll> result(n1 + n2, 0);
 
    // Below two indexes are used to find positions
    // in result. 
    ll i_n1 = 0; 
    ll i_n2 = 0; 
 
    // Go from right to left in num1
    for (ll i=n1-1; i>=0; i--)
    {
        ll carry = 0;
        ll n1 = num1[i] - '0';
 
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0; 
         
        // Go from right to left in num2             
        for (ll j=n2-1; j>=0; j--)
        {
            // Take current digit of second number
            ll n2 = num2[j] - '0';
 
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position. 
            ll sum = n1*n2 + result[i_n1 + i_n2] + carry;
 
            // Carry for next iteration
            carry = sum/10;
 
            // Store result
            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
 
        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
 
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }
 
    // ignore '0's from the right
    ll i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
       return "0";
 
    // generate the result string
    string s = "";
    while (i >= 0)
        s += to_string(result[i--]);
 
    return s;
}

ll mod(string num, ll a)
{
    // Initialize result
    ll res = 0;
 
    // One by one process all digits of 'num'
    for (ll i = 0; i<num.size(); i++)
         res = (res*10 + (ll)num[i] - '0') %a;
 
    return res;
}
 
ll power(ll num, ll pow, ll m)
{
    ll test;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
        {
        	if(test>M && num>M)
        	{
        		string x=to_string(test),y=to_string(num);
        		string r=multiply(x,y);
        		test=mod(r,m);
        	}
        	else
        	{
        		test = (test%m * num%m) % m;
        	}
        }
        if(num>M)
        {
        	string x=to_string(num);
        	string r=multiply(x,x);
        	num=mod(r,m);
        }
        else
        {
        	num = (num%m * num%m) % m;
        }
    }
 
    return test%m;
 
}
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b%M;
    return gcd(b%a, a);
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b,n;
		cin>>a>>b>>n;
		ll c=abs(a-b);
		if(c==0)
		{
			cout<<(power(a,n,M)+power(b,n,M))%M<<endl;
			continue;
		}
		ll A=(power(a,n,c)+power(b,n,c))%c;
		ll B=c;
		cout<<gcd(A,B)<<endl;
	}
} 