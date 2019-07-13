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
ll A,B;
ll ceilSearch(vi a, ll s,ll e,ll x) 
{     
  if(x<=a[s]) 
    return s;   
  if(x>a[e])
  	return -1;
  ll mid=(s+e)/2;
  if(a[mid]==x)
  	return mid;
  else if(a[mid] < x) 
  { 
    if(mid + 1 <= e && x <= a[mid+1]) 
      return mid + 1; 
    else 
      return ceilSearch(a, mid+1, e, x); 
  } 
  else
  { 
    if(mid - 1 >= s && x > a[mid-1]) 
      return mid; 
    else     
      return ceilSearch(a, s, mid - 1, x); 
  } 
} 
ll floorSearch(vi a, ll s,ll e,ll x) 
{     
  if(x>=a[e]) 
    return e;   
  if(x<a[s])
  	return -1;
  ll mid=(s+e)/2;
  if(a[mid]==x)
  	return mid;
  else if(a[mid] < x) 
  { 
    if(mid + 1 <= e && x < a[mid+1]) 
      return mid; 
    else 
      return ceilSearch(a, mid+1, e, x); 
  } 
  else
  { 
    if(mid - 1 >= s && x >= a[mid-1]) 
      return mid-1; 
    else     
      return ceilSearch(a, s, mid - 1, x); 
  } 
} 
ll noavenger(vi a,ll s,ll e)
{
	ll p=floorSearch(a,0,a.size()-1,e),q=ceilSearch(a,0,a.size()-1,s);
	if(p!=-1 && q!=-1)
	{
		return (p-q+1);
	}
	else 
		return 0;
}
ll f(vi a,ll s,ll e)
{
	ll x=noavenger(a,s,e);
	if(s==e)
	{
		if(x)
		{
			return B;
		}
		else
		{
			return A;
		}
	}

	if(x==0)
	{
		return A;
	}
	ll mid=s+(e-s)/2;
	ll ans=min(f(a,s,mid)+f(a,mid+1,e),B*x*(e-s+1));
	return ans;
}
int main()
{
	ll n,k;
	cin>>n>>k>>A>>B;
	vi a(k);
	REP(i,0,k)
	{
		cin>>a[i];
	}
	sort(a.begin(), a.end());
	cout<<a[upper_bound(a.begin(), a.end(),(1<<n))-a.begin()];
	// ll ans=f(a,1,(ll)pow(2,n));
	// cout<<ans<<endl;
}