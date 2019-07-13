#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;
#define inf 1000000000000000000


int main()
{
    

    int n;
    cin>>n;

    ll a[n+1];
    
    
    
    
    ll b[n+1];
    
    
    
    
    ll c[n+1];
    
    
    

    
    for(int i=1;i<=n;i++)
    {
    
    
    
        cin>>a[i];
    
    
    
    
        c[i]=a[i]*i*(n-i+1);
    
        
        
        
    }
    sort(c+1,c+n+1);

    for(ll i=1;i<=	n;++i)
    {
    	cout<<c[i]<<" ";
    }
    cout<<endl;

    for(int i=1;i<=n;i++)
        cin>>b[i];

    sort(b+1,b+n+1,greater<ll>());



    ll ans=0;
    for(int i=1;i<=n;i++)
    {


        ll tmp= (c[i]%mod*b[i]%mod)%mod;
        
        
        
        
        ans= (ans%mod+tmp%mod)%mod;
    }
    
    
    
    
    
    
    

    cout<<ans%mod<<endl;



    return 0;
}