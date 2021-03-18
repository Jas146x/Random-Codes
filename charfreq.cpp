#include<iostream>

using namespace std;

int p = 0; 


string noRepeats (string str, int n) 
{ 

   for (int i=0; i<n; i++) { 
           
     int j;   
     for (j=0; j<i; j++)  
        if (str[i] == str[j]) 
           break; 
       
       
     if (j == i) 
        str[p++] = str[i]; 
   } 
     
   return str; 
} 


int main(){
	
	string s;
	cin>>s;
	
	int i,j,k,l,m, n, x[26], count,flag,check;
	char temp;
	
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(i=0;i<26;i++){
        x[i]=0;
	}
	
	
	for(i=0;i<s.length();i++){
	    x[int(s[i])-97]= x[int(s[i])-97] + 1;
	}

	
	string updateds;
	updateds = noRepeats(s,s.length());
	

	for(i=0;i<p;i++){
        
		cout<<updateds[i]<<" "<< x[int(updateds[i])-97]<<" ";
    }
	



	for(i=0;i<n;i++){
	    cout<<endl;
	    
		for(j=0;j<p;j++){

			if(x[int(updateds[j])-97]==a[i]){
		 	    flag=0;
				for(k=j+1;k<p;k++){
				 	
				 if(x[int(updateds[k])-97]==a[i]){
				 	
					flag=k;
				 	break;
					}
					
			    }
				 
				 if(flag!=0){
		 		   while(flag){					
					if(x[int(updateds[j+1])-97]>a[i]){
					    
						for(l=j+1;l<p-1;l++){
							temp=updateds[l];
							updateds[l]=updateds[l+1];	
							updateds[l+1]=temp;
						}
					
					}
					
					if(x[int(updateds[j+1])-97]<a[i]){
					    
						
						
						for(l=j+1;l>=1;l--){
							temp=updateds[l];
							updateds[l]=updateds[l-1];
							updateds[l-1]=temp;
						}
						
					}
					
			        flag--;
		        }
	        } 
        }
        
		}
        
		for(m=0;m<p;m++){
        
		cout<<updateds[m]<<" "<<x[int(updateds[m])-97]<<" ";
    }
	
}

}
