#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
bool spell(string x,string y,ll bc,ll oc,ll i)
{
	if(bc<0 || oc<0)
		return false;
	if(bc==0 && oc==0)
		return true;
	if(x[i]!='b' && x[i]!='o' && y[i]!='b' && y[i]!='o')
	{
		return false;
	}
	else if((x[i]=='o' && y[i]=='b')||(y[i]=='o' && x[i]=='b'))
	{
		if(spell(x,y,bc-1,oc,i+1))
			return true;
		if(spell(x,y,bc,oc-1,i+1))
			return true;
	}
	else if(x[i]=='b' || y[i]=='b')
	{
		bc--;
		if(spell(x,y,bc,oc,i+1))
			return true;
	}
	else if(x[i]=='o' || y[i]=='o')
	{
		oc--;
		if(spell(x,y,bc,oc,i+1))
			return true;
	}
	return false;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string x,y;
		cin>>x>>y;
		ll bc=2,oc=1;
		if(spell(x,y,bc,oc,0))
		{
			cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
	}
}