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
				case 1: cout<<"Enter the value to insert in the start."<<endl;
						cin>>data;
						insertStart(data);
				break;
				case 2: cout<<"Enter the value to insert in the end."<<endl;
						cin>>data;
						insertEnd(data);
				break;
				case 3: cout<<"Enter the value to insert."<<endl;
						cin>>data;
						cout<<"Enter the neighbouring node value."<<endl;
						cin>>neigh;
						cout<<"Enter 0 for inserting before and 1 for inserting after the neighbouring node."<<endl;
						cin>>loc;
						insertBetween(data,loc,neigh);
				break;
				default: cout<<"Wrong choice"<<endl;
			}
			break;
			case 2: cout<<"\t1. Delete Start\n\t2. Delete End\n\t3. Delete Between"<<endl;
					cin>>ch1;
			switch(ch1){
				case 1:	deleteStart();
				break;
				case 2: deleteEnd();
				break;
				case 3: cout<<"Enter the value to be deleted."<<endl;
						cin>>data;
						deleteNode(data);
				break;
				default: cout<<"Wrong choice"<<endl;
			}
			break;
			case 3: cout<<"Enter the value to be searched"<<endl;
			cin>>data;
			if(search(data)==-1)
				cout<<"Node not found."<<endl;
			else if(search(data)==-2)
				cout<<"List is empty. Cannot perform search."<<endl;
			else
				cout<<"Node found at "<<search(data)<<" position from the head"<<endl;
			break;
			case 4: cout<<"Updated linked list -> ";
					display();
			break;
			case 5: goto end;
			default: cout<<"Wrong choice!"<<endl;			
		}
	}
	end: return 0;
}
