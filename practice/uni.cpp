#include<bits/stdc++.h>
using namespace std;
#define ull long long int
vector<ull> pos(3),e(3),temp(3);
vector<pair<pair<ull,ull>,pair<ull,ull> > > six(7);
vector<pair<pair<ull,ull>,pair<ull,ull> > > five(5);
vector<pair<pair<ull,ull>,pair<ull,ull> > > four(4);
vector<pair<pair<ull,ull>,pair<ull,ull> > > three(3);
vector<pair<pair<ull,ull>,pair<ull,ull> > > two(2);
vector<pair<pair<ull,ull>,pair<ull,ull> > > one(1);
int check(ull a,ull b,ull c)
{
	if(temp[0]>=c && temp[1]>=c && temp[2]>=c)
	{
		temp[0]-=c;temp[1]-=c;temp[2]-=c;
		for(int i=0;i<b;++i)
		{
			temp[2]--;
			temp[1]--;
			sort(temp.begin(),temp.end());
		}
		if(temp[0]>=0 && temp[1]>=0 && temp[2]>=0)
		{
			if(temp[0]+temp[1]+temp[2]>=a)
			{
				while(temp[0]!=0 && a!=0)
				{
					temp[0]--;
					a--;
				}
				while(temp[1]!=0 && a!=0)
				{
					temp[1]--;
					a--;
				}
				while(temp[2]!=0 && a!=0)
				{
					temp[2]--;
					a--;
				}
				return 1;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
}
int main()
{
	ull t;
	cin>>t;
	while(t--)
	{
		
		for(int i=0;i<3;++i)
			cin>>pos[i];
		for(int i=0;i<3;++i)
			cin>>e[i];

		six[0].first.first=6*e[0];six[0].first.second=6;six[0].second.first=0;six[0].second.second=0;
//cout<<"*";
		six[1].first.first=3*e[1];six[1].first.second=0;six[1].second.first=3;six[1].second.second=0;
		six[2].first.first=2*e[2];six[2].first.second=0;six[2].second.first=0;six[2].second.second=2;		
		six[3].first.first=e[0]+e[1]+e[2];six[3].first.second=1;six[3].second.first=1;six[3].second.second=1;
		six[4].first.first=4*e[0]+e[1];six[4].first.second=4;six[4].second.first=1;six[4].second.second=0;
		six[5].first.first=3*e[0]+e[2];six[5].first.second=3;six[5].second.first=0;six[5].second.second=1;
		six[6].first.first=2*e[0]+2*e[1];six[6].first.second=2;six[6].second.first=2;six[6].second.second=0;
//cout<<"*";
		five[0].first.first=5*e[0];five[0].first.second=5;five[0].second.first=0;five[0].second.second=0;
		five[1].first.first=3*e[0]+e[1];five[1].first.second=3;five[1].second.first=1;five[1].second.second=0;
		five[2].first.first=2*e[0]+e[2];five[2].first.second=2;five[2].second.first=0;five[2].second.second=1;
		five[3].first.first=e[1]+e[2];five[3].first.second=0;five[3].second.first=1;five[3].second.second=1;
		five[4].first.first=e[0]+2*e[1];five[4].first.second=1;five[4].second.first=2;five[4].second.second=0;

		four[0].first.first=4*e[0];four[0].first.second=4;four[0].second.first=0;four[0].second.second=0;
		four[1].first.first=2*e[0]+e[1];four[1].first.second=2;four[1].second.first=1;four[1].second.second=0;
		four[2].first.first=e[0]+e[2];four[2].first.second=1;four[2].second.first=0;four[2].second.second=1;
		four[3].first.first=2*e[1];four[3].first.second=0;four[3].second.first=2;four[3].second.second=0;

		three[0].first.first=3*e[0];three[0].first.second=3;three[0].second.first=0;three[0].second.second=0;
		three[1].first.first=e[0]+e[1];three[1].first.second=1;three[1].second.first=1;three[1].second.second=0;
		three[2].first.first=e[2];three[2].first.second=0;three[2].second.first=0;three[2].second.second=1;

		two[0].first.first=2*e[0];two[0].first.second=2;two[0].second.first=0;two[0].second.second=0;
		two[1].first.first=e[1];two[1].first.second=0;two[1].second.first=1;two[1].second.second=0;\

		one[0].first.first=e[0];one[0].first.second=1;one[0].second.first=0;one[0].second.second=0;
//cout<<"*";
		sort(six.begin(),six.end());
		sort(five.begin(),five.end());
		sort(four.begin(),four.end());
		sort(three.begin(),three.end());
		sort(two.begin(),two.end());
       
        sort(pos.begin(),pos.end());
        temp=pos;
        ull ans=0;

        while(temp[0]+temp[1]+temp[2]!=0)
        {
// cout<<"*";        	
        	if(temp[0]+temp[1]+temp[2]>=6)
        	{

        		for(int i=0;i<7;++i)
        		{
  //cout<<"@";
        			if(check(six[i].first.second,six[i].second.first,six[i].second.second))
        			{

        				ans+=six[i].first.first;
        				break;
        			}
        		}
        	}
        	else if(temp[0]+temp[1]+temp[2]==5)
        	{
        		for(int i=0;i<5;++i)
        		{
        			if(check(five[i].first.second,five[i].second.first,five[i].second.second))
        			{
        				ans+=five[i].first.first;
        				break;
        			}
        		}
        	}
        	else if(temp[0]+temp[1]+temp[2]==4)
        	{
        		for(int i=0;i<4;++i)
        		{
        			if(check(four[i].first.second,four[i].second.first,four[i].second.second))
        			{
        				ans+=four[i].first.first;
        				break;
        			}
        		}
        	}
        	else if(temp[0]+temp[1]+temp[2]==3)
        	{
  // cout<<"+";      		
        		for(int i=0;i<3;++i)
        		{
        			if(check(three[i].first.second,three[i].second.first,three[i].second.second))
        			{
        				ans+=three[i].first.first;
        				break;
        			}
        		}
        	}
        	else if(temp[0]+temp[1]+temp[2]==2)
        	{
        		for(int i=0;i<2;++i)
        		{
        			if(check(two[i].first.second,two[i].second.first,two[i].second.second))
        			{
        				ans+=two[i].first.first;
        				break;
        			}
        		}
        	}
        	else
        	{
        		for(int i=0;i<1;++i)
        		{
        			if(check(one[i].first.second,one[i].second.first,one[i].second.second))
        			{
        				ans+=one[i].first.first;
        				break;
        			}
        		}
        	}
         }         
         cout<<ans<<endl;
	}
}


