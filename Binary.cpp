#include<iostream>

using namespace std;

int main(){
	int n,mid,i,j,key;
	
	int a[10] = { 3, 5, 2, 65, 79, 101, 136, 186, 249, 353 };
	
	cout<<"Enter the element you want to search for: " ;
	cin>>key;
	
	n= sizeof(a)/sizeof(int);
	
	i=0;
	
	j=n-1;
	
	while (mid >= 0){
		
        mid=(i+j)/2;
		
		if(key==a[mid]){
		cout<<"The element is present at the position: " ;
		cout<<mid+1;
		break;	
		}
		
		if(key<a[mid]){
			i=0;
			j=mid-1;
			mid=(i+j)/2;
		}
		
		if(key>a[mid]){
			i=mid+1;
			j=n;
			mid=(i+j)/2;
		}		
	
    }

}
