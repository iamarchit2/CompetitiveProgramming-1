#include <bits/stdc++.h>
using namespace std;
void print1D(vector<int > a)
{
	for(int i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int books(vector<int> &A, int B) {
    int n=A.size();
    if(B>n)
        return -1;
    if(B==n)
        return *max_element(A.begin(),A.end());
    for(int i=1;i<n;++i)
    {
        A[i]+=A[i-1];
    }
    print1D(A);
    int l=0,h=A[n-1];
    vector<int> ans;
    while(1)
    {
        cout<<l<<" "<<h<<endl;
        vector<int> t;
        int pos=-1,prev=0;
        int m=(l+h)/2;
        int k=m;
        int c=B;
        while(c && pos!=n-1)
        {
            pos=lower_bound(A.begin(),A.end(),k)-A.begin();
            if(pos==n)
                pos--;
            else if(A[pos]!=k)
                pos--;
            t.push_back(A[pos]-prev);
            prev=A[pos];
            k=A[pos]+m;
            c--;
        }
        if(pos==n-1)
        {
            ans.push_back(*max_element(t.begin(),t.end()));
        }
        // else
        {
            if(pos==n-1)
            {
                h=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        if(l>h)
        {
        	break;
        }
    }
    // return ans.size();
    return *min_element(ans.begin(),ans.end());
}
int main()
{
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;++i)
	{
		cin>>A[i];
	}
	int B;
	cin>>B;
	cout<<books(A,B);
}