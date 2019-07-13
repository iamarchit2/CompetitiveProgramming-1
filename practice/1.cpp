

// C++ program for left rotation of matrix by 90
// degree wuthout using extra space
#include<bits/stdc++.h>
using namespace std;
#define ull long long
ull n; 
// After transpose we swap elements of column
// one by one for finding left rotation of matrix
// by 90 degree
void reverseColumns(vector<vector<ull> > &a)
{
    for (int i=0; i<n; i++)
        for (int j=0,  k=n-1; j<k; j++,k--)
        {
            ull temp=a[i][j];
            a[i][j]=a[i][k];
            a[i][k]=temp;
        }
}
 
 
// Function for do transpose of matrix
void transpose(vector<vector<ull> > &a)
{
    for (int i=0; i<n; i++)
        for (int j=i; j<n; j++)
            {
                ull temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
}
 
// Function for print matrix
void printMatrix(vector<vector<ull> > &a)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << a[i][j] << " ";
        cout<<'\n';
    }
}
 
// Function to anticlockwise rotate matrix
// by 90 degree
void rotate90(vector<vector<ull> > &a)
{
    transpose(a);
    reverseColumns(a);
}
 
//Driven code
int main()
{
    cin>>n;
    vector<vector<ull> > a(n,vector<ull>(n));
    for(ull i=0;i<n;++i)
    {
        for(ull j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
    
    rotate90(a);
    printMatrix(a);
    return 0;
}
