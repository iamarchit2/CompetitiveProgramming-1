#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second 

ll getPairsCount(vector<ll> arr, ll n, ll sum)
{
    unordered_map<int, int> m;
    for (int i=0; i<n; i++)
        m[arr[i]]++;
 
    ll twice_count = 0;
    for (ll i=0; i<n; i++)
    {
        twice_count += m[sum-arr[i]];
        if (sum-arr[i] == arr[i])
            twice_count--;
    }
    return twice_count/2;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> a(n);
        unordered_set<ll> b;
        for(ll i=0;i<n;++i)
        {
            cin>>a[i];
            b.insert(a[i]);
        }
        ll count=0;
        for(ll i=0;i<b.size();)
        {
            ll sum=2*(*b.begin());
            count+=getPairsCount(a,n,sum);
            b.erase(b.begin());
        }
        cout<<count<<endl;
    }
}