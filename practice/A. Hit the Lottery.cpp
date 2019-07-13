#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    vector<ll> coins(5);
    coins =  {100,20, 10, 5, 1};
    ll V;
    cin>>V;
    ll ans=0,k=0;;
    while(V)
    {
      ans+=V/coins[k];
      V=V%coins[k];
      k++;
    }
    cout<<ans;
}