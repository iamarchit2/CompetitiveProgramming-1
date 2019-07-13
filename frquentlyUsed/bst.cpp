#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
    node* left;
    node* right;
};
node* root=NULL;
node* newnode(int dat){
	node* temp=new node;
	temp->left=NULL;
	temp->right=NULL;
	temp->data=dat;
	return temp;
}
node *insert(node* root,node *temp)
{
	if(root==NULL)
		return temp;
	if(root->data > temp->data)
		root->left=insert(root->left,temp);
	else if(root->data < temp->data)
		root->right=insert(root->right,temp);
	return root;
}
void insert(int dat)
{
	node* temp=newnode(dat);
	root=insert(root,temp);
}

node *search(node* root,int a)
{
	if(root==NULL)
		return NULL;
	if(root->data==a)
		return root;
	if(root->data > a)
		return search(root->left,a);
	else if(root->data < a)
		return search(root->right,a);
}
bool search(int a)
{
	node* ptr=search(root,a);
	if(ptr==NULL)
		return false;
	else
		return true;
}
node* minInRight(node *x)
{
	while(x->left!=NULL)
		x=x->left;
	return x;
}
node* del(node* root,int a)
{
	if(root==NULL)
		return NULL;
	if(root->data > a)
		root->left=del(root->left,a);
	else if(root->data < a)
		root->right=del(root->right,a);
	else
	{
		if(root->right==NULL)
			return root->left;
		if(root->left==NULL)
			return root->right;

		node* temp=minInRight(root->right);
		root->data=temp->data;
		root->right=del(root->right,temp->data);
	}
	return root;
}
void del(int a)
{
	root=del(root,a);
}
int main()
{
	int n;
	cout<<"no. of elements:";
	cin>>n;
	cout<<"enter elements"<<endl;
	while(n--){
		int a;
		cin>>a;
		insert(a);
	}	
}