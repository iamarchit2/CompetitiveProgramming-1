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
#define sort(a) sort(a.begin(),a.end())
void print1D(vpi a)
{
	for(ll i=0;i<a.size();++i)
	{
		cout<<a[i].f<<" ";
	}
	cout<<endl;
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
struct node
{
	vpi v;
	node* left;
	node* right;
};
node* build(vpi a)
{
	node *k=new node;
	k->v=a;
	k->left=NULL;
	k->right=NULL;
	if(a.size()==1)
		return k;
	vpi b,c;
	for(ll i=0;i<a.size()-1;i+=2)
	{
		ll x=(a[i].f+a[i+1].f);
		ll y=a[i].s+a[i+1].s;
		if(x>=10)
		{
			y++;
			x%=10;
		}
		b.pb(mp(x,y));
	}
	for(ll i=1;i<a.size()-1;i+=2)
	{
		ll x=(a[i].f+a[i+1].f);
		ll y=a[i].s+a[i+1].s;
		if(x>=10)
		{
			y++;
			x%=10;
		}
		c.pb(mp(x,y));
	}
	if(b.size())
		k->left=build(b);
	if(c.size())
		k->right=build(c);
	return k;
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
		vpi a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i].f;
		}
		node* root=new node;
		root->left=NULL;
		root->right=NULL;
		root->v=a;
		root=build(a);
		// print1D(root->v);
		// print1D(root->right->left->v);
		ll q;
		cin>>q;
		while(q--)
		{
			ll l,r;
			cin>>l>>r;
			node* k=root;
			ll ans=0;
			while(l!=r)
			{
				if(l%2)
				{
					k=k->left;
					l=(l+1)/2;
					r=(r+1)/2;
				}
				else
				{
					k=k->right;
					l=(l)/2;
					r=(r)/2;
				}
			}
			ans=k->v[l-1].s;
			// cout<<l<<endl;
			cout<<ans<<endl;
		}
	}
}
