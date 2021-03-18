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
		while(temp1->next!=NULL){
			temp1=temp1->next;
			}
		temp1->next=temp;
		temp->previous=temp1;
	}
}

int size(){
	int count=0;
	Node* ptr=head;
	while(ptr!=NULL){
		ptr=ptr->next;
		count++;
	}
	return count;
}

int main(){
		insertEnd(67);
		insertEnd(77);
		insertEnd(56976);
		insertEnd(56);
	cout<<"The size of the list is "<<size()<<endl;
}
