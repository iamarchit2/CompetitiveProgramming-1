//deletion is wrong

#include<bits/stdc++.h>
using namespace std;
#define RED true
#define BLACK false
struct node{
	char value;
	node* left,*right,*parent;
	bool colour;
};
class redBlackTree{
	node* root;
	node* rotateleft(node*);
	node* rotataeright(node*);
	void fix(node*);
public:
	redBlackTree()
	{
		root=NULL;
	}
	redBlackTree(int val)
	{
		root->value=val;
		root->left=root->right=root->parent=NULL;
		root->colour=RED; 
	}
	node* getroot()
	{
		return root;
	}
	void insert(int val);
	node* insert(node*,node*);
	void del(int a);
	node* del(node* root,int a);
	void prin(node *root);
};
void redBlackTree::prin(node *root)
{
	if(root==NULL)
		return;
	prin(root->left);
	cout<<root->value;
	prin(root->right);
}
node* redBlackTree::rotateleft(node* ptr)
{
	node* h=ptr->parent;
	h->right=ptr->left;
	ptr->left=h;
	ptr->parent=h->parent;
	h->parent=ptr;
	ptr->colour=h->colour;
	h->colour=RED;

	if(ptr->parent==NULL)
		root=ptr;
	else if (ptr->parent->left == h)
		ptr->parent->left=ptr;
	else
		ptr->parent->right=ptr;
	ptr=h;
	return ptr;
}
node* redBlackTree::rotataeright(node* ptr)
{
	node* h=ptr->parent;
	h->left=ptr->right;
	ptr->right=h;
	ptr->parent=h->parent;
	h->parent=ptr;
	ptr->colour=h->colour;
	h->colour=RED;
	if(ptr->parent==NULL)
		root=ptr;
	else if (ptr->parent->left == h)
		ptr->parent->left=ptr;
	else
		ptr->parent->right=ptr;
	ptr=h;
	return ptr;
}

void redBlackTree::fix(node* ptr)
{
	if(ptr==root)
		return;
	if(ptr->parent->left!=NULL && ptr->parent->right!=NULL)
	{
		if(ptr->parent->left->colour==RED && ptr->parent->right->colour==RED)
		{
			ptr->parent->left->colour=BLACK;
			ptr->parent->right->colour=BLACK;
			ptr->parent->colour=RED;
			fix(ptr->parent);
		}
	}
	else if(ptr->parent->right==ptr)
	{
		ptr=rotateleft(ptr);
		fix(ptr);
	}
	else if(ptr->parent->colour==RED)
	{
		ptr=ptr->parent;
		if(ptr==root)
			return;
		ptr=rotataeright(ptr);
		fix(ptr);
	}
}
node* redBlackTree::insert(node* root,node *temp)
{
	if(root==NULL)
		return temp;
	if(root->value > temp->value)
		{
			root->left=insert(root->left,temp);
			root->left->parent=root;
		}
	else if(root->value < temp->value)
		{
			root->right=insert(root->right,temp);
			root->right->parent=root;
		}
	return root;
}
void redBlackTree::insert(int val)
{
	node* temp=new node;
	temp->value=val;
	temp->colour=RED;
	temp->left=temp->right=temp->parent=NULL;
	root=insert(root,temp);	
	fix(temp);
}

node* minInRight(node *x)
{
	while(x->left!=NULL)
		x=x->left;
	return x;
}
node* redBlackTree::del(node* root,int a)
{
	if(root==NULL)
		return NULL;
	if(root->value > a)
		{
			root->left=del(root->left,a);
			if(root->left->colour==RED)
			{
				fix(root->left);
			}
		}
	else if(root->value < a)
		{
			root->right=del(root->right,a);
			if(root->right->colour==RED)
			{
				fix(root->right);
			}
		}
	else
	{
		if(node->colour==RED)
		{
			if(root->right==NULL)
				return root->left;
			if(root->left==NULL)
				return root->right;
		}
		if(node->colour==BLACK)
		{
			if(root->left==NULL && root->right==NULL)
			{

			}
			else if(root->left==NULL)
			{
				root->right->colour=BLACK;
				return root->right;
			}
			else if(root->right==NULL)
			{
				root->left->colour=BLACK;
				return root->left;
			}
		}
		node* temp=minInRight(root->right);
		root->value=temp->value;
		root->right=del(root->right,temp->value);
	}
	return root;
}
void redBlackTree:: del(int a)
{
	root=del(root,a);
}


int main()
{
	redBlackTree t1;
	t1.insert('S');
	t1.insert('V');
	t1.insert('D');
	t1.insert('E');
	t1.insert('A');
	t1.insert('U');
	t1.insert('T');
	t1.prin(t1.getroot());

	cout<<endl;

}
