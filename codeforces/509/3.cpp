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
ll floorSearch(vi arr, ll low, ll high, ll x) 
{ 
    // If low and high cross each other 
    if (low > high) 
        return -1; 
  
    // If last element is smaller than x 
    if (x >= arr[high]) 
        return high; 
  
    // Find the middle point 
    ll mid = (low+high)/2; 
  
    // If middle point is floor. 
    if (arr[mid] == x) 
        return mid; 
  
    // If x lies between mid-1 and mid 
    if (mid > 0 && arr[mid-1] <= x && x < arr[mid]) 
        return mid-1; 
  
    // If x is smaller than mid, floor must be in 
    // left half. 
    if (x < arr[mid]) 
        return floorSearch(arr, low, mid-1, x); 
  
    // If mid-1 is not floor and x is greater than 
    // arr[mid], 
    return floorSearch(arr, mid+1, high, x); 
}
int main()
{
	ll n,k;
	cin>>n>>k;
	if(k>n)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	vi a;
	for(ll i=1;i<=n;i*=2)
	{
		a.pb(i);
	}
	multiset <int, greater <int> > b;
	// ll sum=0;
	while(n!=0)
	{
		ll ind=floorSearch(a,0,a.size()-1,n);
		n-=a[ind];
		b.insert(a[ind]);
		k--;
	}
	if(k<0)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	while(k!=0)
	{
		ll temp=*b.begin();
		b.erase(b.begin());
		b.insert(temp/2);
		b.insert(temp/2);
		k--;
	}
	multiset <int, greater <int> >::iterator it;
	cout<<"YES"<<endl;
	for(it=b.begin();it!=b.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}