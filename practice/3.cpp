    #include<bits/stdc++.h>
    using namespace std;
    #define ull long long 
    int main()
    {
    	ull n;
    	cin>>n;
    	// if(n%2==1)
    	// {
    	// 	cout<<"No";
    	// 	exit(0);
    	// }
    	ull flag=0;
    	vector<pair<ull,ull> > a(n/2);
    	for(ull i=0;i<n/2;++i)
    	{
    		cin>>a[i].first;
    		cin>>a[i].second;
    		if(a[i].first>a[i].second)
    		{
    			flag=1;
    		}
    	}
    	if(flag==1)
    	{
    		cout<<"No";
    	}
    	else
    		cout<<"Yes";
     
     
    } 