#include<iostream>

using namespace std;

int main(){
	
	int i , j , n , temp;
	
	cout<<"Enter the number of elements: ";
	cin>>n;
	
	int arr[n];
	
	cin<<"Enter the elements: ";
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	
	for(i=1;i<n;i++){
		for(j=i;j>=0;j--){
			if(arr[i]<arr[j]){
				temp=arr[i];
				
			}
			
		}
	}
}
