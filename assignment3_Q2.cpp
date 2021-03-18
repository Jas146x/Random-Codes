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


void display1(){
	Node *temp1=head;
	if(temp1==NULL){
		cout<< " The list is empty. "<<endl;
	}
	while(temp1->next!=head){
		cout<<temp1->data<<" ";
		temp1=temp1->next;
	}

	cout<<temp1->data<<" ";
	cout<<head->data<<" ";
		
	cout<< endl;
}

int main(){
	int data, n;
    cout<<"Enter the number of nodes in the initial link list: "<<endl;
	cin>>n;
	cout<<"Enter the data(node-wise)"<<endl;
	for(int i=0;i<n;i++){
		cin>>data;
		insertEnd(data);
	}
	display1();
}
