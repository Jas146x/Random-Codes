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
		Node *temp1;
		temp1=head;
		while(temp1->next!=head){
			temp1=temp1->next;
		}
		temp1->next=temp;
	}
	temp->next=head;
}


int size(){
	int count=0;
	Node* ptr=head;
	if(head==NULL){
		count=0;
	}
	else if(head!=NULL){
		while(ptr->next!=head){
			ptr=ptr->next;
			count++;			
		}
	}
	return (count+1);
}

int main(){
		insertEnd(55);
		insertEnd(58);
		insertEnd(57);
		insertEnd(56);
		insertEnd(60);
	
	cout<<"The size of the list is "<<size()<<endl;
}
