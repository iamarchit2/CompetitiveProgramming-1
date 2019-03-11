#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<b ; i++)
#define mp make_pair
#define INF 1000000000000000000
#define mod 1000000007
#define pi pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pi>
#define ui unordered_set<ll>
#define um unordered_map<ll,ll>

/* method returns minimum step for deleting the string, 
where in one step a palindrome is removed */
int minStepToDeleteString(string str) 
{ 
	int N = str.length(); 

	// declare dp array and initialize it with 0s 
	int dp[N + 1][N + 1]; 
	for (int i = 0; i <= N; i++) 
		for (int j = 0; j <= N; j++) 
			dp[i][j] = 0; 

	// loop for substring length we are considering 
	for (int len = 1; len <= N; len++) 
	{ 
		// loop with two variables i and j, denoting 
		// starting and ending of substrings 
		for (int i = 0, j = len - 1; j < N; i++, j++) 
		{ 
			// If substring length is 1, then 1 step 
			// will be needed 
			if (len == 1) 
				dp[i][j] = 1; 
			else
			{ 
				// delete the ith char individually 
				// and assign result for subproblem (i+1,j) 
				if(str[i]==str[j])
					dp[i][j]=min(dp[i+1][j],dp[i][j-1]);
				else
					dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
			} 
		} 
	} 

	/* Uncomment below snippet to print actual dp tablex 
	for (int i = 0; i < N; i++, cout << endl) 
		for (int j = 0; j < N; j++) 
			cout << dp[i][j] << " "; */

	return dp[0][N - 1]; 
} 

// Driver code to test above methods 
int main() 
{ 
	// string str = "abcddcba"; 
	// cout << minStepToDeleteString(str) << endl; 
	// return 0; 

	int n;
	cin>>n;
	string s;
	cin>>s;
	cout<<minStepToDeleteString(s);
} 
