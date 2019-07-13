#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll ;
typedef vector<long long int> vi;
typedef pair<ll,ll> pi;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define PB push_back
#define EB emplace_back
#define REP(i,a,b) for(long long int i=a ; i<=b ; i++)
#define REV(i,a,b) for(long long int i=a ; i>=b ; i--)
#define F first
#define S second
#define MP make_pair
#define INF 10000000000000000
#define MOD 1000000007
#define MT make_tuple

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t,m, q, ct, t1, t2,r1=1,r2;
    cin >> n >> m;
    r2=n;
    while(r1<r2){
        REP(i,1,m){
            cout<<r1<<" "<<i<<"\n";
            cout<<r2<<" "<<m-i+1<<"\n";
        }
        r1++;
        r2--;
    }
    if(r1==r2){
        REP(i,1,m/2){
            cout<<r1<<" "<<i<<"\n";
            cout<<r1<<" "<<m-i+1<<"\n";
        }
        if(m%2==1){
            cout<<r1<<" "<<(m+1)/2;
        }
    }
}