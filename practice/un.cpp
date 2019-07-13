#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
int validate(vector<pair<pair<ull,ull>,pair<ull,ull> > > s,ull i,vector<ull> temp)
{
	ull a=s[i].first.second,b=s[i].second.first,c=s[i].second.second;
	temp[0]-=c;temp[1]-=c;temp[2]-=c;
	while(b--)
	{
		temp[1]--;
		if(temp[1]<0)
		{
			return 0;
		}
		temp[2]--;
		sort(temp.begin(),temp.end());
	}
	if(temp[0]+temp[1]+temp[2]==a)
		return 1;
	else
		return 0;
}
int main()
{
	ull t;
	cin>>t;
	while(t--)
	{
		vector<ull> pos(3),temp(3);
		ull A,B,C;
		for(ull i=0;i<3;++i)
		{
			cin>>pos[i];
		}
		cin>>A>>B>>C;
		ull a,b,c;
		vector<pair<pair<ull,ull>,pair<ull,ull> > > s;
		sort(pos.begin(),pos.end());
	    temp=pos;
	    ull bmax=0;
	    ull energy;
	    while(temp[1]!=0)
	    {
	    	bmax++;
	    	temp[1]--;
	    	temp[2]--;
	    	sort(temp.begin(),temp.end());
	    }
	    for(c=0;c<=(pos[0]+pos[1]+pos[2])/3 && c<=pos[0];c++)
	    {
	    	for(b=0; b<=(pos[0]+pos[1]+pos[2]-3*c)/2;++b)
	    	{
	    		a=pos[0]+pos[1]+pos[2]-3*c-2*b;
                energy=a*A+b*B+c*C;
                s.push_back(make_pair(make_pair(energy,a),make_pair(b,c)));
	    	}
	    }
	    sort(s.begin(),s.end());
	    for(ull i=0;i<s.size();++i)
	    {
	    	if(validate(s,i,pos))
	    	{
	    		cout<<s[i].first.first<<endl;
	    		break;
	    	}
	    }
	}
}