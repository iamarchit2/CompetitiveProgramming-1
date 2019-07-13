#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
// CPP program to find element
// closet to given target.
#include <iostream>
using namespace std;
 
ll getClosest(ll, ll, ll);
 
// Returns element closest to target in arr[]
ll findClosest(vector<ll> arr, ll n, ll target)
{
    // Corner cases
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];
 
    // Doing binary search
    ll i = 0, j = n, mid = 0;
    while (i < j) {
        mid = (i + j) / 2;
 
        if (arr[mid] == target)
            return arr[mid];
 
        /* If target is less than array element,
            then search in left */
        if (target < arr[mid]) {
 
            // If target is greater than previous
            // to mid, return closest of two
            if (mid > 0 && target > arr[mid - 1])
                return getClosest(arr[mid - 1],
                                  arr[mid], target);
 
            /* Repeat for left half */
            j = mid;
        }
 
        // If target is greater than mid
        else {
            if (mid < n - 1 && target < arr[mid + 1])
                return getClosest(arr[mid],
                                  arr[mid + 1], target);
            // update i
            i = mid + 1; 
        }
    }
 
    // Only single element left after search
    return arr[mid];
}
 
// Method to compare which one is the more close.
// We find the closest by taking the difference
// between the target and both values. It assumes
// that val2 is greater than val1 and target lies
// between these two.
ll getClosest(ll val1, ll val2,
               ll target)
{
    if (target - val1 >= val2 - target)
        return val2;
    else
        return val1;
}
int main()
{
	ll t;
	cin>>t;
	vector<ll> a;
	for(ll i=1;i<=(ll)pow(2,30);i*=2)
	{
		for(ll j=i*2;j<=(ll)pow(2,30);j*=2)
		{
			ll temp=i+j;
			a.push_back(temp);
		}
	}
	sort(a.begin(),a.end());
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<abs(findClosest(a,a.size(),n)-n)<<endl;
	}
}