#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second 

bool sortinrev(const pair<int,int> &a, 
               const pair<int,int> &b)
{
       return (a.first > b.first);
}

int main(){
	ll t,x=1;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<pair<ll,ll> > a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i].f;
			a[i].s=i;
		}
		sort(a.begin(), a.end(), sortinrev);
		
		for(int i=0; i<a.size(); ++i){
			cout<<a[i].first<<" "<<a[i].second<<endl;
		}
		bool flag = true;
		int i = 0;
		for(; i<a.size(); ++i){
			if(abs(a[i].second-i)%2 == 1){
				flag = false;
				break;
			}
		}
		if(flag)
			cout<<"Case #"<<x<<":"<<" OK"<<endl;
		else cout<<"Case #"<<x<<":"<<" "<<i<<endl;
		++x;
	}
}