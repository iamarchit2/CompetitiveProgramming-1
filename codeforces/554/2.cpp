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
void print1D(vi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i]<<" ";
	}
}
void print2D(vector<vi> a)
{
	for(ll i=0;i<a.size();++i)
	{
		for(ll j=0;j<a[i].size();++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

ll nextPowerOf2(ll n)  
{  
    ll count = 0;  
      
    // First n in the below condition  
    // is for the case where n is 0  
    if (n && !(n & (n - 1)))  
        return n;  
      
    while( n != 0)  
    {  
        n >>= 1;  
        count += 1;  
    }  
      
    return 1 << count;  
}  

// function to convert decimal to binary 
void decToBinary(int n) 
{ 
    // array to store binary number 
    int binaryNum[32]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
} 

int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t=1;
	// cin>>t;
	while(t--)
	{
		ll n;
		
		cin>>n;
		ll ans=nextPowerOf2(n);
		// if(ans==n)
			// ans*=2;
		ans-=1;
		if(ans==n)
		{
			cout<<"0"<<endl;
			continue;
		}
		vi a;
		while(n)
		{
			a.pb(n%2);
			n/=2;
		}
		vi b(a.size());
		for(ll i=0;i<a.size();++i)
			b[i]=a[a.size()-1-i];
		vi ans2;
		ll c=0;
		while(1)
		{
			// ll flag=1;
			
			for(ll i=0;i<b.size();++i)
			{
				if(b[i]==0)
				{
					c++;
					ans2.pb(b.size()-i);
					for(ll j=i;j<b.size();++j)
					{
						if(b[j])
							b[j]=0;
						else
							b[j]=1;
					}
					for(ll j=b.size()-1;j>=0;j--)
					{
						if(b[j]==0)
						{
							b[j]=1;
							break;
						}
						else
						{
							b[j]=0;
						}
					}
					c++;
					break;
				}

			}
			if(b[0]==0)
			{
				c--;
				break;
			}
			if(count(b.begin(),b.end(),1)==b.size())
				break;
		}
		cout<<c<<endl;
		print1D(ans2);
		// while(n)
		// {
		// 	a.pb(n%2);
		// 	n/=2;
		// }
		// for(ll i=0;i<a.size();++i)
		// {
		// 	if(a[a.size()-1-i])
		// 	{
		// 		b.pb(0);
		// 	}
		// 	else
		// 		b.pb(1);
		// }
		// for(ll i=0;i<b.size();++i)
		// {
		// 	if(b[i]==1)
		// 	{
		// 		flag=1;
		// 		brak;
		// 	}
		// }
		// vi a(n);
		// for(ll i=0;i<n;++i)
		// {
		// 	cin>>a[i];
		// }

	}
}
