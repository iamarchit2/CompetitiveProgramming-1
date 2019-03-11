#include<bits/stdc++.h>
#define pb   push_back
#define mp   make_pair
#define f    first
#define s    second
#define ll   long long
#define vi vector< int >
#define vl vector< ll >
#define rep(i,j,n)  for(int (i) = (j); i < n; i++)
#define MAX(a, b)     ((a) > (b) ? (a) : (b))
#define MIN(a, b)     ((a) < (b) ? (a) : (b))
#define all(v) v.begin(), v.end()
#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define Max  INT_MAX
#define Min  INT_MIN
#define mod  1000000007
using namespace std;
 
ll seg[1000000], lazy[1000000];
int query( ll qs , ll qe , ll ns , ll ne , ll ind )
{
	if(lazy[ind]!=0)
	{
		seg[ind]=max(seg[ind],lazy[ind]);
        if (ns != ne)
        {
            lazy[ind*2] = max(lazy[ind*2],lazy[ind]);
            lazy[ind*2 + 1] = max(lazy[ind*2 + 1],lazy[ind]);
        }
        lazy[ind] = 0;
	}
 
	if(qs<=ns && qe>=ne)
		return seg[ind];
 
	if(ne<qs || ns>qe || ns>ne )
		return 0;
 
	ll mid=(ns+ne)>>1;
 
	ll l=query(qs,qe,ns,mid,ind<<1), r=query(qs,qe,mid+1,ne,ind<<1|1);
 
	return max(l,r);
}
 
void rangeupdate(ll us, ll ue, ll ns, ll ne, ll ind, ll val)
{
	if(lazy[ind]!=0)
	{
		seg[ind]=max(seg[ind],lazy[ind]);
        if (ns != ne)
        {
            lazy[ind*2] = max(lazy[ind*2],lazy[ind]);
            lazy[ind*2 + 1] = max(lazy[ind*2+1],lazy[ind]);
        }
        lazy[ind] = 0;
	}
 
    if (ns>ne || ns>ue || ne<us)
        return ;
 
    if (ns>=us && ne<=ue)
    {
        seg[ind]=max(val,seg[ind]);
        if (ns != ne)
        {
            lazy[ind*2] =max(lazy[ind*2],val) ;
            lazy[ind*2+1] = max(lazy[ind*2+1],val);
        }
        return;
    }
 
	ll mid = (ns+ne)>>1;
	rangeupdate(us,ue,ns,mid,ind<<1,val);
	rangeupdate(us,ue,mid+1,ne,ind<<1|1,val);
 
	ll  l=seg[ind<<1], r=seg[ind<<1|1];
	seg[ind]=max(l,r);
}
 
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--)
	{
		memset(seg,0,sizeof(seg));
		memset(lazy,0,sizeof(lazy));
		
		int n,q; cin>>n>>q;
		
		int l,r,x;
		while(q--)
		{
			cin>>x;
			if(x==0)
			{
				cin>>l>>r;
				cout<<query(l,r,1,n,1)<<"\n";
			}
			else
			{
				cin>>l>>r;
				ll y = query(l,l+r,1,n,1);
				rangeupdate(l,l+r,1,n,1,y+r);
			}
		}
	}
}