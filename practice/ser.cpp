#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

void SieveOfEratosthenes(ll n,vector<ll> &a)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    vector<bool> prime(n+1,true);
 
    for (ll p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (ll i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (ll p=2; p<=n; p++)
       if (prime[p])
       {
          a.push_back(p*p*p*p);
       }
}
ll binarySearchCount(vector<ll> arr, ll n, ll key)
{
    ll left = 0, right = n;
 
    ll mid;
    while (left < right)
    {
        mid = left + (right-left)/2;
 
        // Check if key is present in array
        if (arr[mid] == key)
        {
            // If duplicates are present it returns
            // the position of last element
            while (arr[mid+1] == key && mid+1<n)
                 mid++;
            break;
        }
 
        // If key is smaller, ignore right half
        else if (arr[mid] > key)
            right = mid;
 
        // If key is greater, ignore left half
        else
            left = mid + 1;
    }
 
    // If key is not found in array then it will be
    // before mid
    while (arr[mid] > key)
        mid--;
 
    // Return mid + 1 because of 0-based indexing
    // of array
    return mid + 1;
} 
// Driver Program to test above function
int main()
{
    ll k=31623;
    vector<ll> a;
    SieveOfEratosthenes(k,a);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n<16)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<binarySearchCount(a,a.size(),n)<<endl;
    }

}