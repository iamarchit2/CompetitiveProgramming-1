#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
using namespace std;
 
/* function to find and print the longest common 
   substring of X[0..m-1] and Y[0..n-1] */
ll LCSubStr(string X, string Y, ll m, ll n)
{
    ll LCSuff[m + 1][n + 1];
 
   
    ll len = 0;
 
    
    ll row, col;
 
    /* Following steps build LCSuff[m+1][n+1] in bottom
       up fashion. */
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                if (len < LCSuff[i][j]) {
                    len = LCSuff[i][j];
                    row = i;
                    col = j;
                }
            } else
                LCSuff[i][j] = 0;
        }
    }
 
   return len;
 
    // allocate space for the longest common substring
    // char* resultStr = (char*)malloc((len + 1) * sizeof(char));
    // resultStr[len] = '&#092;&#048;';
 
    // // traverse up diagonally form the (row, col) cell
    // // until LCSuff[row][col] != 0
    // while (LCSuff[row][col] != 0) {
    //     resultStr[--len] = X[row - 1]; // or Y[col-1]
 
    //     // move diagonally up to previous cell
    //     row--;
    //     col--;
    // }
 
    // // required longest common substring
    // cout << resultStr;
}
 
/* Driver program to test above function */
int main()
{
    // char X[] = "OldSite:GeeksforGeeks.org";
    // char Y[] = "NewSite:GeeksQuiz.com";
 
    // int m = strlen(X);
    // int n = strlen(Y);
 
    // printLCSubStr(X, Y, m, n);
    // return 0;
    ll n;
    cin>>n;
    vector<string> a(n);
    ll ctr=0;
    for(ll i=0;i<n;++i)
    {
        cin>>a[i];
        ll m=a[i].size();
        ll s=LCSubStr(a[i],"chef",m,4);
        if(s>=2)
            ctr++;
    }
    cout<<ctr;

}