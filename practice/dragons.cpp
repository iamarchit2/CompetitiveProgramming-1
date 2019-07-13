#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

// ll ceilSearch(vector<ll> arr, ll low, ll high, ll x)
// {
//   ll mid;    
 
//   /* If x is smaller than or equal to the first element,
//     then return the first element */
//   if(x <= arr[low])
//     return low; 
 
//   /* If x is greater than the last element, then return -1 */
//   if(x > arr[high])
//     return -1;  
 
//   /* get the index of middle element of arr[low..high]*/
//   mid = (low + high)/2;  /* low + (high - low)/2 */
 
//   /* If x is same as middle element, then return mid */
//   if(arr[mid] == x)
//     return mid;
     
//    If x is greater than arr[mid], then either arr[mid + 1]
//     is ceiling of x or ceiling lies in arr[mid+1...high]  
//   else if(arr[mid] < x)
//   {
//     if(mid + 1 <= high && x <= arr[mid+1])
//       return mid + 1;
//     else
//       return ceilSearch(arr, mid+1, high, x);
//   }
 
//   /* If x is smaller than arr[mid], then either arr[mid] 
//      is ceiling of x or ceiling lies in arr[mid-1...high] */   
//   else
//   {
//     if(mid - 1 >= low && x > arr[mid-1])
//       return mid;
//     else    
//       return ceilSearch(arr, low, mid - 1, x);
//   }
// }
ll ceilSearch(vector<ll> arr, ll n, ll x)
{
    // search space is A[low..high]
    ll low = 0, high = n - 1, mid;

    // initialize ceil to -1
    ll ceil = -1;

    // iterate till search space contains at-least one element
    while (low <= high)
    {
        // find the mid value in the search space
        mid = (low + high) / 2;

        // if x is equal to mid element, it is the ceil
        if (arr[mid] == x)
            return mid;

        // if x is less than the mid element, ceil exists in the
        // sub-array A[low..mid]. We update ceil to the mid element
        // and reduce our search space to left subarray A[low..mid-1]
        else if (x < arr[mid])
        {
            ceil = mid;
            high = mid - 1;
        }

        // if x is more than the mid element, ceil exists in the
        // right sub-array A[mid+1..high]
        else
            low = mid + 1;
    }

    return ceil;
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
		vector<ll> temp(n),c;
		temp=s;
		ll x=p;
		while(x>0)
		{
			ll index=ceilSearch(temp,temp.size(),x);
			if(index==-1)
			{
				c.push_back(temp[temp.size()-1]);
				x-=temp[temp.size()-1];
				temp.erase(temp.begin()+temp.size()-1);
			}
			else
			{
				c.push_back(temp[index]);
				x-=temp[index];
				temp.erase(temp.begin()+index);
			}
			if(temp.size()==0)
			{
				break;
			}
		}
		if(temp.size()==0 && x!=0)
		{
			for(ll i=0;i<n;++i)
				cout<<"0 ";
			cout<<endl;
			continue;
		}
		ll left=0;
		ll sum=c[0];
		ll right=n-c.size()+1;
		while(temp.size())
		{
			c.push_back(temp[0]);
			temp.erase(temp.begin());
		}
		// for(ll i=0;i<c.size();++i)
		// 	cout<<c[i]<<" ";
		// cout<<endl;
		ll ptr=n-1;
		vector<ll> ans;
		ans.push_back(-1);
		for(ll f=1;f<=(n+1)/2;++f)
		{
			ans.push_back(left+right);
			right--;
			ll zero=0;
			right=max(zero,right);
			sum+=c[ptr];
			ptr--;
			if(sum>=p)
				left++;
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