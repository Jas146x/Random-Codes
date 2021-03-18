#include<iostream>

using namespace std;

int main(){
	int z,i,j,p,q,n,I,J,l,m,x,flag,out;
	
	cin>>p;
	cin>>q;
	cin>>n;
	
	int total=p*q;
	
	int t[n][3] , s[p][q], sing[n], dir[n] ;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>t[i][j];
		}
	}
	
	cin>>I;
	cin>>J;
	
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			s[i][j]=0;
		}
	}
	

    for(i=0;i<n;i++)
	{
        
		s[t[i][0]][t[i][1]]=t[i][2];
		
	}	
	/*
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
    }*/
    
    l=1;m=1,z=0;
        //cout<<s[I][J]<<endl;
    if(s[I][J]!=0){
    	sing[z]=s[I][J];
	    dir[z]=1;
		z++;
	}
	total--;
    while(total>1)
	{
		
		if(total<=1){
			break;
		}
		for(i=0;i<l;i++)
		{
			total--;
		   	I++;
		   	if(I>=p){
		   		I--;
		   		total=total-l;
				l--;
			    break;
		   	}
		    //cout<<s[I][J]<<endl;
			if(s[I][J]!=0)
			{
				for(x=0;x<z;x++)
			    {
				    flag = 0;
				    if(sing[x]==s[I][J])
				    {
					    flag = 1;
	                    
				    }
				}    
				    
				if(flag==0)
				{
					sing[z]=s[I][J];
			        dir[z]=1;
			        z++;
				}
			
	        }
        }
	    
		l++; 
		
		if(total<=1){
			break;
		}
		   
	    for(j=0;j<m;j++)
		{
		   	total--;
			J++;
			if(J>=q){
		   		J--;
				total=total-m;
		   		m--;
		   		
			    break;
		   	}
		    //cout<<s[I][J]<<endl;
			if(s[I][J]!=0)
			{
				for(x=0;x<z;x++)
			    {
				    flag = 0;
				    if(sing[x]==s[I][J])
				    {
					    flag = 1;
	                    
				    }
				}    	
				
				if(flag==0)
				{
					sing[z]=s[I][J];
			        dir[z]=2;
			        z++;
				}
			
	        }
			
		}
		
		
		m++;
		
		if(total<=1){
			break;
		}
		
		
		for(i=0;i<l;i++)
		{
		   	total--;
			I--;
			if(I<0){
		   	    I++;
				total=total-l;
		   	    l--;
		   	    
			    break;
		   	}
		    //cout<<s[I][J]<<endl;
			if(s[I][J]!=0)
			{ 
			    flag = 0;
				for(x=0;x<z;x++)
			    {
				    if(sing[x]==s[I][J])
				    {
					    flag = 1;
	                    
				    }
				}    
				
				if(flag==0)
				{
					sing[z]=s[I][J];
			        dir[z]=3;
			        z++;
				}
			
	        }
		}
	    l++; 
		
		if(total<=1){
			break;
		}  
		 
	    for(j=0;j<m;j++)
		{
			total--;
		   	J--;
		   	if(J<0){
		   		J++;
				total=total-m;
		   		m--;
		   		
			    break;
		   	}
		    //cout<<s[I][J]<<endl;
			if(s[I][J]!=0)
			{   
			    flag = 0;
				for(x=0;x<z;x++)
			    {
				    if(sing[x]==s[I][J])
				    {
					    flag = 1;
	                    
				    }
				}    
				    
				    
				    	
					
			    if(flag==0)
				{
					sing[z]=s[I][J];
			        dir[z]=4;
			        z++;
				}
	        }
			
		}
		
		
		m++;
		
	}
	
	for(i=0;i<z;i++)
	{
		for (j=0;j<n;j++)
		if(sing[i]==t[j][2])
		{
		cout<<t[j][0]<<" "<<t[j][1]<<" "<< sing[i] <<" "<< dir[i]<<endl;
	    }
	}
    
}
