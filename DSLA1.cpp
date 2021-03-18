#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};
Node *head1=NULL;
Node *head2=NULL;
Node *head3=NULL;


void createLL1(int n){
	Node *temp=new Node;
	temp->data=n;
	
	if(head1==NULL)
		head1=temp;
	else{
		Node *ptr=new Node;
		ptr=head1;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
	}
	temp->next=NULL;
}


void createLL2(int n){
	int i;
	Node *ptr;
    for(i=0;i<n-1;i++){
	Node *temp=new Node;
	temp->data=0;
	if(head2==NULL)
		head2=temp;
	else{
		ptr=head2;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
	}
	temp->next=NULL;
	}
	
	ptr=head2;
	Node *ptr1=head1;
	
	for(i=0;i<n-1;i++){
		ptr->data = ptr1->data + ptr1->next->next->data;
		ptr=ptr->next;
		ptr1=ptr1->next->next;
	}
	
}

void createLL3(int n){
	int i;
	Node *ptr;
    for(i=0;i<n-1;i++){
	Node *temp=new Node;
	temp->data=0;
	if(head3==NULL)
		head3=temp;
	else{
		ptr=head3;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
	}
	temp->next=NULL;
	}
	
	ptr=head3;
	Node *ptr1=head1->next;
	
	for(i=0;i<n-1;i++){
		ptr->data = ptr1->data + ptr1->next->next->data;
		ptr=ptr->next;
		ptr1=ptr1->next->next;
	}
	

}

void display(Node*ptr){
	Node *temp1 = ptr;
	if(temp1==NULL){
		cout<< " The list is empty. "<<endl;
	}
	while(temp1!=NULL){
		cout<<temp1->data<<" ";
		temp1=temp1->next;
	}		
}

int updatedLL1(int n){
	int i;
	Node *ptr,*ptr2,*ptr3,*temptail,*temp,*temp2,*temp3;
	temp=head1;
	temptail=head1;
	temp2=head2;
	temp3=head3;
	
	for(i=0;i<n-1;i++){
		ptr=temp;
		ptr2=temp2;
		temp= temp->next;
	    temp2= temp2->next;  
		ptr2->next = ptr->next;
	    ptr->next=ptr2;

	    
	}
	
	
	while(temptail->next!=NULL){
		temptail=temptail->next;
	}
	
	Node *newnode=new Node;
	newnode->data= head1->data + temptail->data;
	newnode->next=temp->next;
	temp->next=newnode;
	temp=temp->next->next;
		
	
    for(i=0;i<n-1;i++){
		ptr=temp;
		ptr3=temp3;
		temp= temp->next;
	    temp3= temp3->next;  
		ptr3->next = ptr->next;
	    ptr->next=ptr3;

	}
	return newnode->data;	
}

int main(){
	int n,i,x,mid;
	cin>>n;
	for(i=0;i<(2*n);i++){
		cin>>x;
		createLL1(x);
	}
	createLL2(n);
	createLL3(n);
	display(head2);
	cout<<endl;
	display(head3);
	cout<<endl;
	mid=updatedLL1(n);
	cout<<mid;
	cout<<endl;
	display(head1);
	cout<<endl;
	cout<<((4*n)-1);
}
