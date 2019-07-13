#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<double> a(n),b;
		unordered_map<ll,ll> m,u;
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			m[a[i]]++;
		}
		double p,q;
		double temp=10000000000000.0;
		double x,y;
		for(ll i=0;i<n;++i)
		{
			if(m[a[i]]>=4)
			{
				x=y=a[i];
				temp=1;
				break;
			}
			if(m[a[i]]>=2 && u[a[i]]==0)
			{
				b.push_back(a[i]);
				u[a[i]]=1;
			}
		}
		if(temp==1)
		{
			cout<<x<<" "<<x<<" "<<y<<" "<<y<<endl;
			continue;
		}
		sort(b.begin(), b.end());
		for(ll i=0;i<b.size()-1;++i)
		{
			
			p=b[i];
			ll j=i+1;
			q=b[j];
			double w=4*(p+q)*(p+q)/(p*q);
			if(w<temp)
			{
				x=p;
				y=q;
				temp=w;
			}
				
			
		}
		cout<<x<<" "<<x<<" "<<y<<" "<<y<<endl;
	}
}


//  #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace std;
// using namespace __gnu_pbds;

// typedef long long int ll ;
// typedef vector<long long int> vi;
// typedef pair<ll,ll> pi;
// typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

// #define PB push_back
// #define EB emplace_back
// #define REP(i,a,b) for(long long int i=a ; i<=b ; i++)
// #define F first
// #define S second
// #define MP make_pair
// #define INF 1000000000000000000
// #define MOD 1000000007
// #define MT make_tuple



// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll n,t,a,tmp,ti,tj;
//     long double ta,an;
//     cin>>t;
//     unordered_map<ll,ll> m;
//     vi v;
//     while (t--)
//     {
//         cin>>n;
//         m.clear();
//         v.clear();
//         REP(i,1,n)
//         {
//             cin>>a;
//             m[a]++;
//         }
//         tmp=0;
//         for(auto x:m)
//         {
//             if(x.S>=4)
//             {
//                 cout<<x.F<<" "<<x.F<<" "<<x.F<<" "<<x.F<<"\n";
//                 tmp=1;
//                 break;
//             }
//             else if(x.S>=2)
//             {
//                 v.EB(x.F);
//             }
//         }
//         if(tmp==1)
//             continue;
//         sort(v.begin(),v.end());
//         n=v.size();
//         an=100000;
//         REP(i,0,n-1)
//         {
//         	cout<<v[i]<<" ";
//         }
//         cout<<endl;
//         REP(i,1,n-1)
//         {
//             if(v[i]<v[i-1])
//             {
//                 ta=double(v[i-1])/double(v[i]);
//             }
//             else
//             {
//                 ta=double(v[i])/double(v[i-1]);
//             }
//             cout<<ta<<endl;
//             if(ta<an)
//             {
//                 an=ta;
//                 ti=v[i];
//                 tj=v[i-1];
//             }
//         }
//         cout<<ti<<" "<<ti<<" "<<tj<<" "<<tj<<"\n";
//     }
//     return 0;
// }