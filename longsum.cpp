#include<iostream>
using namespace std;

int main(){
    short int n,i;
    cin>>n;
    long long int arr[n] ,sum=0;
    for(i=0;i<n;i++){
    	cin>>arr[i];
    	sum=sum+arr[i];
	}
	cout<<sum;
}
