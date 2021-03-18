#include<iostream>
using namespace std;


struct Node
{
	int data;
	Node *next;
	
};
Node *head=NULL;
Node *Nodetable[1001];
int *freqtable=new int[1001]; 

void initialize()
{
	int i;
    for(int i=0;i<1001;i++){freqtable[i]=0;}
    for(int i=0;i<1001;i++){Nodetable[i]=NULL;}
}


int circ=0;



void checkfreq()
    {
	    int i=1000;
        while(i>=1)
        {
           if(Nodetable[i]!=NULL)
           {
                if(Nodetable[i]->next!=NULL)
                {
                    freqtable[Nodetable[i]->next->data]++;
                }
           }
           i--;
        }
    }


void I0x(int x)
{
	Node *temp=new Node;
	temp->data=x;
	Nodetable[x]=temp;
	if(head==NULL)
	{
		head=temp;
		freqtable[head->data]=0;
		
	}
	else
	{
		Node *temp1;
		temp1=head;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=temp;
	}
	temp->next=NULL;

}



void I1yx(int y,int x)
{
	Node *tempslow=head;
	Node *tempfast=head->next;
	Node *temp = new Node;
	
	if (head->data==x)
	{
		temp->data=y;
		Nodetable[y]=temp;
		temp->next=head;
		head=temp;
	}
	
	else if (head->data==y)
	{
		temp->data=x;
		Nodetable[x]=temp;
		temp->next=head->next;
		head->next=temp;
	
	}
	
	else
	{
	    while(tempfast!=NULL)
		{
		    if(tempfast->data=x)
			{
		    	temp->data=y;
		    	Nodetable[y]=temp;
	            temp->next=tempfast;
				tempslow->next=temp;
				break;
			}
			
			else if(tempfast->data=y)
			{
				temp->data=x;
				Nodetable[x]=temp;
				temp->next=tempfast->next;
				tempfast->next=temp;
				break;
			}     
	        
			tempfast=tempfast->next;
	        tempslow=tempslow->next;
	    
	    }
    }
	

}


void I2zyx(int z , int y , int x)
{
	int count=0;
	Node *tempz=head;
	Node *tempy=head;
	Node *temp = new Node;
	temp->data=x;
	Nodetable[x]=temp;
	
	while(tempz->data!=z)
	{	if(tempz==NULL){
			goto exit;
		}
		tempz=tempz->next;
		tempy=tempy->next;
	
		
	}
	
	while(tempy->data!=y)
	{	
	    if(tempy==NULL){
		    goto exit;
		}
		tempy=tempy->next;
		count++;
	
	}
	
	count=count/2;
	
	while(count!=0)
	{
		tempz=tempz->next;
		count--;
	}
	temp->next=tempz->next;
	tempz->next=temp;

exit:
	return;
}



void Uxp(int x, int p)
{
	int i;
	Node *tempx=head;
	Node *tempp=head;
		
	while(tempx->data!=x)
	{
	    tempx=tempx->next;
	    tempp=tempp->next;
	
	    if(tempx==NULL)
        {
            return;
        }
	}
	
	for(i=0;i<p;i++)
	{
		tempp=tempp->next;
	
		if(tempp->next==NULL)
		{
			tempp->next=head; 
			circ=1;
		}
	}
	tempx->next=tempp;

}


void display(){

Node *temp1=head;
	/*if(temp1==NULL){
		cout<<endl;
	}*/
	while(temp1!=NULL){
		cout<<temp1->data<<" ";
		temp1=temp1->next;
	}

}



int main()
{
	initialize();
	int n,x,y,z,p,m,count;
	int i,j; 
	char c;
	
	cin>>n;
	
	for(i=0;i<n;i++)
	{
	    cin>>c;
	    if(c=='I')
	    {
	   	    cin>>m;
	   	
		    if(m==0)
	   	    {
	   		    cin>>x;
	   		    I0x(x);
		    }
		
		    else if(m==1)
		    {
		    	cin>>y;
				cin>>x;
				I1yx(y,x); 
			}
			
			else if(m==2)
		    {
		    	cin>>z;
		    	cin>>y;
				cin>>x;
				I2zyx(z,y,x); 
			}
			
		}
		
		else if(c=='U')
		{
			cin>>x;
			cin>>p;
			Uxp(x, p);
			
		} 	
	}
	
	checkfreq();
	
	cout<<circ<<endl;
    
	for(int i=1;i<=1000;i++)
    {
        if(freqtable[i]>=2) 
        {
            count++;
        }
    }
    if(count==0) 
    { 
        cout<<"0"<<endl;
		display(); 
    }
    else 
    {
        cout<<count<<endl;
        for(int i=1;i<=1001;i++)
        {
            if(freqtable[i]>=2) cout<<i<<" ";
        }
        cout<<endl;
        for(int i=1;i<=1001;i++)
        {
            if(freqtable[i]>=2) cout<<freqtable[i]<<" ";
        }
    }
    cout<<endl;
}

