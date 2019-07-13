#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};
class linkedlist
{
	node *head;
public:
    int size;
	linkedlist()
	{
		head=NULL;
		size=0;
	}
	node* gethead()
	{
		return head;
	}
	void insert(int pos,int value)
	{
		node* temp;
		temp=new node;
		temp->data=value;
		temp->next=NULL;
		node* i;
		i=head;
		if(pos==1)
		{
			temp->next=head;
			head=temp;
			size++;
			return;
		}
		if(pos>size+1)
		{
			cout<<"wrong position";
			return;
		}
		--pos;
		while(--pos)
		{
			i=i->next;
		}
		temp->next=i->next;
		i->next=temp;
	    size++;
	}
	void sort()
	{
		for(node* i=head;i!=NULL;i=i->next)
		{
			int min=i->data;
			node* pos=i;
			for(node* j=i;j!=NULL;j=j->next)
			{
				if(j->data < min)
				{
					min=j->data;
					pos=j;
				}
			}
			int temp=i->data;
			i->data=pos->data;
			pos->data=temp;
		}
	}
	void reverse()
	{
		node *i,*j,*k;
		if(head==NULL)
		{
			cout<<"list is empty";
			return;
		}
		if(head->next==NULL)
		{	
			return;
		}
		i=head;
		j=head->next;
		while(j!=NULL)
		{ 
			k=j->next;
			j->next=i;
			if(i->next==j)
				i->next=NULL;
			i=j;
			j=k;
		}
		head=i;
	}
	
	// void reverse(node *i,node*j)
	// {
	// 	if(j==NULL)
	// 	{
	// 		head=i;
	// 		return;
	// 	}
	// 	reverse(i->next,j->next);
	// 	j->next=i;
	// 	i->next=NULL;
	// }
	
	void display()
	{
		node* temp;
		temp=head;
		if(temp==NULL)
			cout<<"list is empty";
		else
		{
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
	}
};
int main()
{
	linkedlist l1,l2;
	cout<<"enter number of elements:";
	int n;
	cin>>n;
	cout<<"enter elements"<<endl;
	int temp;
	for(int i=0;i<n;++i)
	{
		cin>>temp;
		l1.insert(1,temp);
		l2.insert(1,temp);
	}
	l1.sort();
	l2.sort();
	l2.reverse();
	//l2.reverse(l2.gethead(),l2.gethead()->next);
	node* temp1=l1.gethead();
	node* temp2=l2.gethead();
	while(n)
	{
		if(n==1)
		{
			cout<<temp2->data;
			break;	
		}
		cout<<temp2->data<<" ";
		cout<<temp1->data<<" ";
		n-=2;
		temp2=temp2->next;
		temp1=temp1->next;
	}
}