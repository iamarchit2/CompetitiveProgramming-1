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
// int floorSearch(vi arr, ll low, ll high, ll x) 
// { 
//     // If low and high cross each other 
//     if (low > high) 
//         return -1; 
  
//     // If last element is smaller than x 
//     if (x >= arr[high]) 
//         return high; 
  
//     // Find the middle point 
//     ll mid = low+(high-low)/2; 
  
//     // If middle point is floor. 
//     if (arr[mid] == x) 
//         return mid; 
  
//     // If x lies between mid-1 and mid 
//     if (mid > 0 && arr[mid-1] <= x && x < arr[mid]) 
//         return mid-1; 
  
//     // If x is smaller than mid, floor must be in 
//     // left half. 
//     if (x < arr[mid]) 
//         return floorSearch(arr, low, mid-1, x); 
  
//     // If mid-1 is not floor and x is greater than 
//     // arr[mid], 
//     return floorSearch(arr, mid+1, high, x); 
// } 

ll printFloor(ll arr[], ll n, 
                ll find) 
{ 
    // Find and print the Floor Values 
    ll low; 
  
    // cout << "Floor : "; 
    // for (int i = 0; i < n2; i++) { 
  
        low = (lower_bound(arr, arr + n,find) - arr); 
  
        if (arr[low] > find) 
            // cout << arr[low - 1] << " ";
            return low-1;
        else
            // cout << arr[low] << " "; 
        	return low;
    // } 
  
    // cout << endl; 
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
		ll a[n];
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			a[i]=abs(a[i]);
		}
		sort(a, a+n);
		ll ans=0;
		for(ll i=0;i<n;++i)
		{
			if(2*a[i]>=a[n-1])
			{
				ans+=n-1-i;
				continue;
			}
			ll ind=printFloor(a,n,2*a[i]);
			ans+=ind-i;
		}
		cout<<ans<<endl;
	}
}
