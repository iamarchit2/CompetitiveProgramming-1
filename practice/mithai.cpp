#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
vector<ll> taste;
void printPowerSet(vector<ll> set, int set_size)
{
    /*set_size of power set of a set with set_size
      n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    ll counter, j;
 
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
    	ll sum=0;
      for(j = 0; j < set_size; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
          if(counter & (1<<j))
            sum+=set[j];
       }
       taste.push_back(sum);
    }
}

int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	ll k;
	cin>>k;
	printPowerSet(a,n);
	sort(taste.begin(),taste.end());
	cout<<taste[k]<<endl;
}