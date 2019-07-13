#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
ll ceilSearch(vector<ll> arr, ll low, ll high, ll x)
{
  ll mid;    
 
  /* If x is smaller than or equal to the first element,
    then return the first element */
  if(x <= arr[low])
    return low; 
 
  /* If x is greater than the last element, then return -1 */
  if(x > arr[high])
    return -1;  
 
  /* get the index of middle element of arr[low..high]*/
  mid = (low + high)/2;  /* low + (high - low)/2 */
 
  /* If x is same as middle element, then return mid */
  if(arr[mid] == x)
    return mid;
     
  /* If x is greater than arr[mid], then either arr[mid + 1]
    is ceiling of x or ceiling lies in arr[mid+1...high] */ 
  else if(arr[mid] < x)
  {
    if(mid + 1 <= high && x <= arr[mid+1])
      return mid + 1;
    else
      return ceilSearch(arr, mid+1, high, x);
  }
 
  /* If x is smaller than arr[mid], then either arr[mid] 
     is ceiling of x or ceiling lies in arr[mid-1...high] */   
  else
  {
    if(mid - 1 >= low && x > arr[mid-1])
      return mid;
    else    
      return ceilSearch(arr, low, mid - 1, x);
  }
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,p;
		cin>>n>>p;
		vector<ll> s(n);
		for(ll i=0;i<n;++i){
			cin>>s[i];
		}
		sort(s.begin(),s.end());
		if(s[n-1]>=p)
		{
			for(ll i=0;i<n;++i)
				cout<<n<<" ";
			cout<<endl;
			continue;
		}
		vector<ll> ans(n+1),temp(n);
		for(ll f=1;f<=(n+1)/2;++f)
		{
			temp=s;
			ll l=p,r=p;
			l-=temp[n-1];
			r=l;
			temp.pop_back();
			ll j=f-1,i=f+1;
			while(1)
			{
				if(i>n)
					break;
				ll index=ceilSearch(temp,0,temp.size()-1,r);
				if(index==-1)
				{
					i++;
					r-=temp[temp.size()-1];
					temp.pop_back();
				}
				else
				{
					ans[f]+=n-i+1;
					temp.erase(temp.begin()+index);
					break;
				}
			}
			// for(ll i=0;i<temp.size();++i)
			// 	cout<<temp[i]<<" ";
			// cout<<endl;
			while(temp.size())
			{
				if(i>n || j<1)
					break;
				l-=temp[temp.size()-1];
				if(l<=0)
				{
					ans[f]+=j;
					break;
				}
				else
				{
					j--;
					temp.pop_back();
				}
			}			
		}
		for(ll i=1;i<=(n+1)/2;++i)
			cout<<ans[i]<<" ";
		if(n%2==0)
		{
			for(ll i=n/2;i>=1;--i)
				cout<<ans[i]<<" ";
		}
		else
		{
			for(ll i=(n-1)/2;i>=1;--i)
				cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}