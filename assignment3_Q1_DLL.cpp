#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *previous;
	Node *next;
};
Node *head=NULL;

void insertEnd(int n){
	Node *temp=new Node;
	temp->data=n;
	temp->previous=NULL;
	temp->next=NULL;
	
	if(head==NULL)
		head=temp;
	else{
		Node *temp1=head;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=temp;
		temp->previous=temp1;
	}
}

void insertStart(int n){
	Node *temp=new Node;
	temp->data=n;
	temp->previous=NULL;
	temp->next=head;
	if(head!=NULL)
		head->previous=temp;
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
			newNode->previous=temp;
			if(temp->next!=NULL)
				temp->next->previous=newNode;
			temp->next=newNode;
		}
		else{
			newNode->next=temp;
			newNode->previous=temp->previous;
			if(temp->previous!=NULL)
				temp->previous->next=newNode;
			else
				head=newNode;
			temp->previous=newNode;
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
			head->next->previous=NULL;
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
		if(temp->previous!=NULL)
			temp->previous->next=NULL;
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
			temp->previous->next=temp->next;
			temp->next->previous=temp->previous;
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

int main(){
    int ch, ch1, data, neigh, loc, n;
	cout<<"Enter the number of nodes in the initial link list: "<<endl;
	cin>>n;
	cout<<"Enter the data(node-wise)"<<endl;
	for(int i=0;i<n;i++){
		cin>>data;
		insertEnd(data);
	}
	while(true){
		cout<<endl<<"Enter your choice"<<endl;
		cout<<"1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
		cin>>ch;
		switch(ch){
			case 1: cout<<"\t1. Insert Start\n\t2. Insert End\n\t3. Insert Between"<<endl;
					cin>>ch1;
			switch(ch1){
				case 1:{
					cout<<"Enter the value to insert in the start."<<endl;
					cin>>data;
					insertStart(data);
					break;
				}
				case 2:{
					cout<<"Enter the value to insert in the end."<<endl;
					cin>>data;
					insertEnd(data);
					break;
				}
				case 3:{
					cout<<"Enter the value to insert."<<endl;
					cin>>data;
					cout<<"Enter the neighbouring node value."<<endl;
					cin>>neigh;
					cout<<"Enter 0 for inserting before and 1 for inserting after the neighbouring node."<<endl;
					cin>>loc;
					if(insertBetween(data,loc,neigh))
						cout<<"Element added successfully."<<endl;
					else
						cout<<"Neighbour not found in the list"<<endl;
					break;
				}
				default: cout<<"Wrong choice"<<endl;
			}
			break;
			case 2: cout<<"\t1. Delete Start\n\t2. Delete End\n\t3. Delete Between"<<endl;
					cin>>ch1;
			switch(ch1){
				case 1:{ 
					int *d=deleteStart();
					if(d==NULL)
						cout<<"List is empty. Cannot delete.\n";
					else
						cout<<"Deleted value -> "<<*d<<endl;					
					break;
				}
				case 2:{
					int *d=deleteEnd();
					if(d==NULL)
						cout<<"List is empty. Cannot delete.\n";
					else
						cout<<"Deleted value -> "<<*d<<endl;					
					break;
				}

				case 3: {
					cout<<"Enter the value to be deleted."<<endl;
					cin>>data;
					bool d=deleteNode(data);
					if(d)
						cout<<"Deleted value -> "<<data<<endl;
					else
						cout<<"Element not found."<<endl;
					break;
				}
				default: cout<<"Wrong choice"<<endl;
			}
			break;
			case 3:{
				cout<<"Enter the value to be searched"<<endl;
				cin>>data;
				if(search(data)==-1)
					cout<<"Node not found."<<endl;
				else if(search(data)==-2)
					cout<<"List is empty. Cannot perform search."<<endl;
				else
					cout<<"Node found at "<<search(data)<<" position from the head"<<endl;
				break;
			}
			case 4: cout<<"Updated linked list -> ";
					display();
			break;
			case 5: return 0;
			default: cout<<"Wrong choice!"<<endl;			
		}
	}
	return 0;
}
