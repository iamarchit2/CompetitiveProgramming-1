#include<bits/stdc++.h>
using namespace std;
#define ll long long int

template<typename E>
class treeExpression
{
	public:
    auto operator[](size_t i) const 
    { 
    	return static_cast<E const&>(*this)[i];     
    }
    size_t size() const 
    { 
    	return static_cast<E const&>(*this).size(); 
    }
    operator E& () 
    { 
     	return static_cast<E&>(*this); 
    }
    operator const E& () const 
    { 
     	return static_cast<const E&>(*this); 
    }
}

template<typename T>
class genericSegmentTree: public treeExpression<genericSegmentTree>
{
	vector<T> tree;
public:
	function<T(T)>leaf;//T (*leaf)(T);
	function<T(T,T)>node;//T (*node)(T,T);
	genericSegmentTree(vector<T> arr,T n,function<T(T)>f1,function<T(T, T)> f2 /* T (*f1)(T),T (*f2)(T,T) */);//f1:what to put in leaf;f2:what to do with children
	T &operator[](size_t i) 
	{ 
		return tree[i]; 
	}
    T operator[](size_t i) const 
    { 
    	return tree[i]; 
    }
    size_t size()
	{
		return tree.size();
	}
    T query(size_t l,size_t r) ; //l and r are based on 1-based indexing
	void updateElement(size_t index,T newValue);
	
};
template<class T>
genericSegmentTree<T>::genericSegmentTree(vector<T> arr,T n,function<T(T)>f1,function<T(T, T)> f2 /* T (*f1)(T),T (*f2)(T,T)*/)//f1:what to put in leaf;f2:what to do with children
{
	leaf=f1;
	node=f2;
	for(size_t i=0;i<n;++i)
	{
		tree[i+n]=leaf(arr[i]);
	}
	for(size_t i=n-1;i>0;--i)
	{
		tree[i]=node(tree[2*i],tree[2*i+1])
	}
}

template<class T>
T genericSegmentTree<T>::query(size_t l,size_t r)  //l and r are based on 1-based indexing
{
	l=l-1;
	size_t n=(tree.size()+1)/2,ctr=0;
	l+=n;r+=n;
	T res;
    
   	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
   	{
      	if (l&1) 
       	{
       		if(ctr==0)
       		{
       			res=leaf(tree[l++]);ctr++;
        	}
        	else
           		res = node(res,tree[l++]);
	    }
     
        if (r&1) 
	    {
   	    	if(ctr==0)
       			{
       				res=leaf(tree[--r]);ctr++;
       			}	
           	else
           		res = node(res,tree[--r]);
       	}
    }
     
   	return res;
}
template<class T>
void genericSegmentTree<T>::updateElement(size_t index,T newValue)
{
	size_t n=(tree.size()+1)/2;
	tree[index+n]=newValue;
	for(size_t i=index+n;i>1;i=i/2)
	{
		tree[i/2]=node(tree[i],tree[i+1]);
	}
} 	
template <typename E1, typename E2>
class treeNode : public treeExpression<treeNode<E1, E2> > {
    E1 const& a;
    E2 const& b;

public:
    treeNode(E1 const& u, E2 const& v) : a(u), b(v) {
        assert(u.size() == v.size());
    }

    auto operator[](size_t i) const { return genericSegmentTree::node(a,b) }
};
  
template <typename E1, typename E2>
treeNode<E1,E2> const
operator+(E1 const& u, E2 const& v) {
   return treeNode<E1, E2>(u, v);
}