#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *back;
	Node *next;
};
Node *head=NULL;

void insertEnd(int n){
	Node *temp=new Node;
	temp->data=n;
	temp->back=NULL;
	temp->next=NULL;
	
	if(head==NULL)
		head=temp;
	else{
		Node *temp1=head;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=temp;
		temp->back=temp1;
	}
}

void insertStart(int n){
	Node *temp=new Node;
	temp->data=n;
	temp->back=NULL;
	temp->next=head;
	if(head!=NULL)
		head->back=temp;
	head=temp;
}

bool insertBetween(int n, int loc, int pos){
	Node *temp=head;
	Node *newNode=new Node;
	newNode->data=n;
	if(head!=NULL){
		while(temp->data!=pos){
			if(temp->next==NULL)
				return false;
			temp=temp->next;
		}
		if(loc==1){
			newNode->next=temp->next;
			newNode->back=temp;
			if(temp->next!=NULL)
				temp->next->back=newNode;
			temp->next=newNode;
		}
		else{
			newNode->next=temp;
			newNode->back=temp->back;
			if(temp->back!=NULL)
				temp->back->next=newNode;
			else
				head=newNode;
			temp->back=newNode;
		}
	}
	else
		insertEnd(n);
	return true;
}

int* deleteStart(){
	int *del=new int;
	if(head!=NULL){
		*del=head->data;
		if(head->next!=NULL)
			head->next->back=NULL;
		head=head->next;				
	}
	else
		del=NULL;
	return del;
}

int* deleteEnd(){
	Node *temp = head;
	int* del=new int;
	while(temp!=NULL&&temp->next!=NULL)
		temp=temp->next;
	if(temp!=NULL){
		*del=temp->data;
		if(temp->back!=NULL)
			temp->back->next=NULL;
		else
			head=NULL;
	}
	else{
		del=NULL;
		head=NULL;
	}
	return del;
}

bool deleteNode(int n){
	Node *temp=head;
	int *d=new int;
	if(head!=NULL){
		while(temp->data!=n){
			if(temp->next==NULL)
				return false;
			temp=temp->next;
		}
		if(temp==head)
			d=deleteStart();
		else if(temp->next==NULL)
			d=deleteEnd(); 
		else{
			temp->back->next=temp->next;
			temp->next->back=temp->back;
		}
		return true;
	}
	else
		return false;
}

int search(int n){
	Node *temp=head;
	int i=1;
	if(head==NULL)
		return -2;
	while(temp->data!=n){
		if(temp->next==NULL){
			return -1;
		}
		temp=temp->next;
		i++;	
	}
	return i;
}

void display(){

Node *temp1=head;
	if(temp1==NULL){
		cout<< " The list is empty. "<<endl;
	}
	while(temp1!=NULL){
		cout<<temp1->data<<" -> ";
		temp1=temp1->next;
	}
cout<<"..."<<endl;
}
