#include <iostream>

using namespace std;
class Node{
    int data;
    Node* next;
    Node* head=NULL;
    bool isCircular=false;
    int *table=new int[1001];
    Node* NodeTable[1001];
    int N=0;
public:
    int* getTable(){
        return table;
    }
    
    Node(){
        for(int i=0;i<1001;i++) {table[i]=0;};
        for(int i=0;i<1001;i++){NodeTable[i]=NULL;}
    }
    
void I0(int x){

    Node* temp2=new Node;
    temp2->data=x;
    temp2->next=NULL;

    NodeTable[x]=temp2;
    N++;


    if(head==NULL){
        head=temp2;
        table[head->data]=0;
        return;
    }

    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=temp2;
}
//case I1
void I1(int y,int x){
    N++;
    Search(y)?insertAfter(y,x):insertBefore(y,x);
}
void insertBefore(int y,int x){
    Node* temp=new Node;
    temp->data=y;
    temp->next=NULL;

    NodeTable[y]=temp;

	if(head->data==x){
        temp->next=head;
        head=temp;
        return;
    }

    Node* temp2=head;
    while(temp2->next->data!=x){
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;
}
//void InsertAfter
void insertAfter(int y,int x){

    Node* temp=new Node;
    temp->data=x;
    temp->next=NULL;

    NodeTable[x]=temp;

    Node* temp2=head;
    while(temp2->data!=y){
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;
}








void I2(int x,int y,int z){
   Node* temp2=new Node;
   temp2->data=z;
   temp2->next=NULL;

   NodeTable[z]=temp2;
   int distance=0;


   Node* temp=head;
   while(temp->data!=x){
    temp=temp->next;
   }


   Node* Initial=temp;
   while(temp->data!=y){
    temp=temp->next;
    distance++;
   }
   distance/=2;

   while(distance!=0){
    Initial=Initial->next;
    distance--;
   }

   temp2->next=Initial->next;
   Initial->next=temp2;
   N++;
}



// searching for a node
bool Search(int x){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==x){return true;}
        temp=temp->next;
    }
    if(temp==NULL) return false;

}

//printing element
void print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


void U(int x,int p){
    if(Search(x)==false){return;}


    Node* temp=NodeTable[x];
	while(p!=0){
		if(temp->next==NULL){ temp->next=head;
				     temp=head;
				     isCircular=true;
				     p--;}

		else{ temp=temp->next; p--;}

}
	NodeTable[x]->next=temp;
}
    void GenerateTable(){
        for(int i=1;i<1001;i++){
           if(NodeTable[i]!=NULL){
            if(NodeTable[i]->next!=NULL){
                table[NodeTable[i]->next->data]++;
            }
           }
    }
    }

    void printTable(){
        for(int i=1;i<10;i++){
            cout<<i<<" "<<table[i]<<endl;
        }
    }
    bool Circular(){
        return isCircular;
    }
    int length(){
        return N;
    }
};
int main()
{
    Node A;
    int N;
    cin>>N;
    char a;
    int b;
    for(int i=0;i<N;i++){
        cin>>a;
        cin>>b;
        if(a=='I' && b==0){
            int x;
            cin>>x;
            A.I0(x);
        }
        else if(a=='I' && b==1){
            int x,y;
            cin>>x>>y;
            A.I1(x,y);
        }

        else if(a=='I' && b==2){
            int x,y,z;
            cin>>x>>y>>z;
            A.I2(x,y,z);
        }
        else if(a=='U'){
            int p;
            cin>>p;
            A.U(b,p);
        }
    }
    A.GenerateTable();
    int* ansTable=A.getTable();
    int countMultiple=0;
    A.Circular()?cout<<1<<endl:cout<<0<<endl;
    for(int i=1;i<=1000;i++){
        if(ansTable[i]>=2) {countMultiple++;}
    }
    if(countMultiple==0) { cout<<"0"<<endl; A.print();}
    else {
            cout<<countMultiple<<endl;
        for(int i=1;i<=1000;i++){
            if(ansTable[i]>=2) cout<<i<<" ";
        }
        cout<<endl;
         for(int i=1;i<=1000;i++){
            if(ansTable[i]>=2) cout<<ansTable[i]<<" ";
        }
    }
    cout<<endl;
}
