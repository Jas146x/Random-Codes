#include<iostream>
using namespace std;

struct Node{
	char data;
	Node *previous;
	Node *next;
};
Node *head=NULL;

void insertStart(char n){
	Node *temp=new Node;
	temp->data=n;
	temp->previous=NULL;
	temp->next=NULL;
	if(head!=NULL){
	    temp->next=head;
		head->previous=temp;
	}
	head=temp;
}

int checkPalindrome(int n){
	int i;
	Node* last=head;
	Node* first=head;
	while(last->next!=NULL)
		last=last->next;
	
	if(n%2!=0)
	while(first!=last){
		if(first->data!=last->data)
			return 0;
		first=first->next;
		last=last->previous;
	}
	
	if(n%2==0)
	for(i=0;i<n/2;i++){
		if(first->data!=last->data)
			return 0;
		first=first->next;
		last=last->previous;
	}
	return 1;
}

int main(){
	cout<<"Enter the data"<<endl;
	string s;
	cin>>s;
	for(int i=s.length()-1;i>=0;i--)
		insertStart(s[i]);
	if(checkPalindrome(s.length()))
		{
		cout<<"The list of characters is a palindrome"<<endl;}
	
	else{
		cout<<"The list of characters is not a palindrome"<<endl;}
	
	
	return 0;
}
