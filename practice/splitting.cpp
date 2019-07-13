#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 

ull  _mergeSort(vector<ull> arr, vector<ull> temp, ull left, ull right);
ull merge(vector<ull> arr, vector<ull> temp, ull left, ull mid, ull right);
 

ull mergeSort(vector<ull> arr, ull array_size)
{
    //int *temp = (int *)malloc(sizeof(int)*array_size)
    vector<ull> temp(array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 

ull _mergeSort(vector<ull> arr, vector<ull> temp, ull left, ull right)
{
  ull mid, inv_count = 0;
  if (right > left)
  {
    
    mid = (right + left)/2;
 
    
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
 
    
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}
 

ull merge(vector<ull> arr, vector<ull> temp, ull left, ull mid, ull right)
{
  ull i, j, k;
  ull inv_count = 0;
 
  i = left; 
  j = mid; 
  k = left; 
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
 
     
      inv_count = inv_count + (mid - i);
    }
  }
 
  
  while (i <= mid - 1)
    temp[k++] = arr[i++];
 
  
  while (j <= right)
    temp[k++] = arr[j++];
 
 
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
 
  return inv_count;
}
int main()
{
 	int t;
 	cin>>t;
 	while(t--)
 	{
 	ull n;
 	cin>>n;
 	vector<ull> a(n),temp;
 	vector<vector<ull> > b(n,vector<ull> (n));
 	for(ull i=0;i<n;++i)
 	{
 		cin>>a[i];
 	}
 	for(ull i=0;i<n;++i)
 	{
 		a.push_back(a[0]);
 		a.erase(a.begin());
 		temp=a;
 		for(ull i=0;i<n;++i)
 		{
 			cout<<temp[i]<<" ";
 		}
 		cout<<endl;
 		//cout<<mergeSort(temp,n)<<" ";
 	}
    }
 	
}