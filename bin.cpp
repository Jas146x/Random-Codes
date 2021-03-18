#include<iostream>
using namespace std;


int main(){
	
	int t,n,no=0,i,k,j;
	j=0;
	char alpha[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','\0'};
	char ans[100];
	cin>>t;
	while(t>0){
	cin>>n;
	int arr[n];
	
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	k=1;
	while(k<n){
		no=(arr[k-1]*8)+(arr[k]*4)+(arr[k+1]*2)+(arr[k+2]*1);
	    ans[j]=alpha[no];
	    j++;
		k=k+4;
        }
        t--;
    }
    for(i=0;i<j;i++){
    	cout<<ans[i];
	}    
    return 0;
}
