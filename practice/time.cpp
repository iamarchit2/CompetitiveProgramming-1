#include<bits/stdc++.h>
using namespace std;

int main()
{
	clock_t t1,t2;
	t1=clock();
	unsigned long long int t=1000;
	while(t)
	{
		cout<<t<<" ";
		t--;
	}
	t2=clock();
	double time=((double)t2-(double)t1)/CLOCKS_PER_SEC;
	cout<<endl<<time;
    return 0;
}