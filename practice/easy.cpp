#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;++i)
    {
        cin>>a[i];
    }
    ll m;
    cin>>m;
    vector<ll> c(m);
    for(ll i=0;i<m;++i)
    {
        cin>>c[i];
    }
    set<ll> ans;
    set<ll>:: iterator itr;
    for(ll i=0;i<101;++i)
        ans.insert(i);
    for(ll i=0;i<n;++i)
    {
        unordered_set<ll> s;
        for(ll j=0;j<m;++j)
        {
            s.insert(c[j]-a[i]);
        }
        for(itr=ans.begin(); ans.end() != itr;++itr)
        {
            if(s.end() == s.find(*itr))
            {
                ans.erase(*itr);
            }
        }
    }
    for(itr=ans.begin(); ans.end() != itr; ++itr)
    {
        cout<<*itr<<" ";
    }
}