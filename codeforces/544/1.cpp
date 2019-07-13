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

int main()
{
	double h1,m1,h2,m2;
	char ch;
	cin>>h1>>ch>>m1>>h2>>ch>>m2;
	double m=(m1+m2)/2,h=(h1+h2)/2;
	if(h!=(ll)h)
	{
		m+=30;
		h=(ll)h;
	}
	if(m>=60)
	{
		m-=60;
		h+=1;
	}
	if((ll)h/10==0)
		cout<<0;
	cout<<h<<":";
	if((ll)m/10==0)
		cout<<0;
	cout<<m<<endl;
}
