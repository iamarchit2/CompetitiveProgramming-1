#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

void extendedEuclid(ll A, ll B,ll &x,ll &y,ll &d) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B,x,y,d);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
ll modExponent(ll a,ll b,ll m)
{
	if(b==0)
		return 1;
	if(b%2==0)
		return modExponent((a*a)%m,b/2,m);
	if(b%2==1)
	{
		return (a*modExponent((a*a)%m,(b-1)/2,m))%m;
	}
}
int main()
{
	ll a,b,c,m;
	cin>>a>>b>>c>>m;
	ll x,y,d;
	extendedEuclid(c,m,x,y,d);
	ll z=modExponent(a,b,m);
	cout<<(z*x)%m;
}