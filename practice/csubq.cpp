#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ull unsigned long long int
ull n, q, L, R, l, r, x, y, ctr = 0, ans;
vector < pair<ull, double> > a(n+1);
vector < pair<ull, ull> > leftright(n);
ull k = 0;
 
void left(ull i)
{
	
	for (ull j = i - 1; j >=l; --j)
	{
		if (a[j] < a[i])
			leftright[k].first++;
		else return;
	}
}
void right(ull i)
{
	
	for (ull j = i + 1; j <= r; ++j)
	{
		if (a[j] <= a[i])
			leftright[k].second++;
		else return;
	}
}
int main()
{
 
	cin >> n>>q>>L>>R;
	a.resize(n+1);
	leftright.resize(n+1);
	while(q--)
	{
		int query;
		cin >> query;
		if (query == 1)
		{
			cin >> x >> y;
		
			a[x].first = y;
			if (y >= L&&y <= R)
			{
				a[x].second = 1;
			
			}
			// else if (y <= L)
			// 	a[x].second = 0.5;
			else
				a[x].second = 0;
		}
		else
		{
		
		    k = 0;
			for (ull i = 0; i < n; ++i)
				leftright[i].first = leftright[i].second = 0;
			cin >> l >> r; 
			ctr = 0;
			for (ull i = l; i <= r; ++i)
			{
				
				if (a[i].second == 1)
				{
					ctr++;
					left(i);
					right(i);
					k++;
				}
			}
			ans = ctr;
			//for (ull i = 0; i < k; ++i)
			//{
				//cout << leftright[i].first << " " << leftright[i].second << endl;
			//}
			for (ull i = 0; i < k; ++i)
				ans += leftright[i].first*(leftright[i].second + 1) + leftright[i].second;
			cout << ans << endl;
		}
	}
	//char ch;
	//cin >> ch;
} 