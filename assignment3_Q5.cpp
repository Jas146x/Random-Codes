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
		while(temp1->next!=NULL){
			temp1=temp1->next;
		}
		temp1->next=temp;
	}
	temp->next=NULL;
}


int check(){
	int i;
	Node *temp = head;
	
	while(temp->next!=NULL&&temp->next!=head){
		temp=temp->next;
	}
	
	if(temp->next==NULL){
		cout<<"It is not a circular link list.\n\n";
	}
	
	if(temp->next==head){
		cout<<"It is a circular link list.\n";
	}
}

void makeCircular(){   
    Node *temp = head;
    
    while (temp->next!=NULL){
    	temp=temp->next;
	}
	
	temp->next= head;
    
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
	check();
	makeCircular();
	cout<<"Now we make the list circular and check."<<endl<<endl;
	check();
}
