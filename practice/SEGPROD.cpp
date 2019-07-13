// https://www.codechef.com/NOV17/problems/SEGPROD

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

struct node{
	int key;
	node *left,*right;
};
node * newNode(int k)
{
    node *temp = new node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}
node* build(vector<ll> &a,vector<vector<pair<ll,ll> > > &v,ll p,ll level,ll s,ll e,node* root)
{
	if(s>e)
		return NULL;
	ll m=(s+e)/2;
	root=newNode(m);
	v[m][level].f=a[m]%p;
	v[m][level].s=m;
	for(ll i=m-1;i>=s;--i)
	{
		v[i][level].f=(a[i]*v[i+1][level].f)%p;
		v[i][level].s=m;
	}
	if(m+1<=e)
		{
			v[m+1][level].f=a[m+1]%p;
			v[m+1][level].s=m;
		}
	for(ll i=m+2;i<=e;++i)
	{
		v[i][level].f=((a[i]*v[i-1][level].f))%p;
		v[i][level].s=m;
	}
	root->left=build(a,v,p,level+1,s,m-1,root->left);
	root->right=build(a,v,p,level+1,m+1,e,root->right);

	return root;
}
void eulerTour(node *root, ll l,vector<ll> &euler,vector<ll> &level,vector<ll> &firstOccurrence,ll &ind)
{
    
    if (root)
    {
        euler[ind] = root->key; 
        level[ind] = l;         
        ind++;                  
        if (firstOccurrence[root->key] == -1)
            firstOccurrence[root->key] = ind-1;
        if (root->left)
        {
            eulerTour(root->left, l+1,euler,level,firstOccurrence,ind);
            euler[ind]=root->key;
            level[ind] = l;
            ind++;
        }
        if (root->right)
        {
            eulerTour(root->right, l+1,euler,level,firstOccurrence,ind);
            euler[ind]=root->key;
            level[ind] = l;
            ind++;
        }
    }
}
void buildSparseTable(vector<ll> &level, ll n,vector<vector<ll> > &lookup)
{
    for (ll i = 0; i < n; i++)
        lookup[i][0]=level[i];//           lookup[i].push_back(level[i]);
    for (ll j = 1; (1 << j) <= n; j++) {       
        for (ll i = 0; (i + (1 << j) - 1) < n; i++) {            
            lookup[i][j]=min(lookup[i][j-1],lookup[i+(1 << (j - 1))][j-1]);//  lookup[i].push_back(min(lookup[i][j-1],lookup[i+(1 << (j - 1))][j-1]));             
        }
    }
}
ll RMQ(ll L, ll R,vector<vector<ll> > &lookup)
{
    ll j = (ll)log2(R - L + 1);
    return min(lookup[L][j],lookup[R - (1 << j) + 1][j]);
}
// void print(vector<ll> a)
// {
// 	for(ll i=0;i<a.size();++i)
// 		cout<<a[i]<<" ";
// 	cout<<endl;
// }
// void printv(vector<vector<ll> > v)
// {
// 	for(ll i=0;i<v.size();++i)
// 	{
// 		for(ll j=0;j<v[i].size();++j)
// 		{
// 			cout<<v[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// }
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,p,q;
		cin>>n>>p>>q;
		vector<ll> a(n),b((q/64)+2),l(q),r(q);
		vector<vector<pair<ll,ll> > > v(n,vector<pair<ll,ll> >((ll)log2(n)));
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		node* root;
		root=build(a,v,p,0,0,n-1,root);
		vector<ll> euler(2*n-1),level(2*n-1),firstOccurrence(n,-1);
		ll ind=0;

		eulerTour(root, 0,euler,level,firstOccurrence,ind);
		vector<vector<ll> > lookup(2*n-1,vector<ll>((ll)log2(2*n-1)+1));
		buildSparseTable(level,2*n-1,lookup);
		for(ll i=0;i<b.size();++i)
		{
			cin>>b[i];
		}
		ll x=0;
		// printv(v);
		// print(a);
		// print(euler);
		// print(level);
		// print(firstOccurrence);
		for(ll i=0;i<q;++i)
		{
			if(i%64==0)
			{
				l[i]=(b[i/64]+x)%n;
				r[i]=(b[i/64+1]+x)%n;
			}
			else
			{
				l[i]=(l[i-1]+x)%n;
				r[i]=(r[i-1]+x)%n;
			}
			if (firstOccurrence[l[i]]>firstOccurrence[r[i]])
       			swap(l[i], r[i]);
       		ll index=RMQ(firstOccurrence[l[i]],firstOccurrence[r[i]],lookup);
       		cout<<l[i]<<" "<<r[i]<<" "<<index<<" ";
       		if(l[i]>r[i])
			{
				swap(l[i], r[i]);
			}
			ll ans;
			if(v[r[i]][index].s==r[i])
			{
				ans=v[l[i]][index].f%p;
			}
			ans=((v[l[i]][index].f%p)*(v[r[i]][index].f%p))%p;
       		x=(ans+1)%p;
       		cout<<x<<endl;;
			
		}
		cout<<x%p<<endl;
	}
}