#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};
Node *head=NULL;

void insertEnd(int n){
	Node *temp=new Node;
	temp->data=n;
	
	if(head==NULL)
		head=temp;
	else{
		Node *temp1=new Node;
		temp1=head;
		while(temp1->next!=head)
			temp1=temp1->next;
		temp1->next=temp;
	}
	temp->next=head;
}

void insertStart(int n){
	Node *temp=new Node;
	Node *h=head;
	temp->data=n;
	if(head!=NULL){

		while(h->next!=head)
			h=h->next;
		h->next=temp;
		temp->next=head;
		head=temp;
	}
	else{
		head=temp;
		temp->next=head;
	}
}

void insertBetween(int n, int loc, int pos){
	Node *temp=head;
	Node *temp1=new Node();
	temp1->data=n;
	Node *prev=head;
	if (temp==NULL){
		cout<<"No list exists. Creating a new list...\n";
		insertStart(n);
		goto end;	
	}
	while(temp->data!=pos){
		if(temp->next==head){
			cout<<"Neighbour not present in the list.\n";
			goto end;
		}
		prev=temp;
		temp=temp->next;
	}
	if(loc==1){
		temp1->next=temp->next;
		temp->next=temp1;
	}
	else{
		temp1->next=temp;
		if(head==temp){
			Node *t=head;
			while(t->next!=head)
				t=t->next;
			head=temp1;
			t->next=head;
		}
		else
			prev->next=temp1;
	}
	cout<<"Element added.\n";
	end:;
}

void deleteStart(){
	Node *t=head;
	if(t==NULL){
		cout<<"List is empty. Cannot delete.\n";
		goto end;
	}
	if(t->next==head){
		cout<<"Only one element present -> "<<head->data<<" Emptying list...\n";
		head=NULL;
		goto end;
	}
	while(t->next!=head)
		t=t->next;
	cout<<"Deleted value -> "<<head->data<<endl;
	head=head->next;
	t->next=head;
	end:;
}

void deleteEnd(){
	Node *temp = head;
	if(temp==NULL){
		cout<<"List is empty. Cannot delete.\n";
		goto end;
	}
	if(temp->next==head){
		cout<<"Only one element present -> "<<head->data<<" Emptying list...\n";
		head=NULL;
		goto end;
	}	
	while((temp->next)->next!=head)
		temp=temp->next;
	cout<<"Deleted value -> "<<temp->next->data<<endl;
	temp->next=head;
	end:;
}

void deleteNode(int n){
	Node *temp=head;
	if(head==NULL){
		cout<<"List Empty. Cannot delete...\n";
		goto end;
	}
	if(head->data==n){
		deleteStart();
		goto end;
	}
	while(temp->next->data!=n){
		if(temp->next->next==head){
			cout<<"Given node not found.\n";
			goto end;
		}
		temp=temp->next;
	}
	if(head->next==head){
		cout<<"Only one element present -> "<<head->data<<" Emptying list...\n";
		head=NULL;
		goto end;
	}
	cout<<"Deleted node -> "<<temp->next->data<<endl;
	temp->next=temp->next->next;	
	end:;	
}

int search(int n){
	Node *temp=head;
	int i=1;
	if(head==NULL)
		return -2;
	while(temp->data!=n){
		if(temp->next==head){
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
	while(temp1->next!=head){
		cout<<temp1->data<<" -> ";
		temp1=temp1->next;
	}
	if(temp1->next==head){
		cout<<temp1->data<<" -> ";
	}		
	cout<<"..."<<endl;
}
