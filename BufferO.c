#include<stdio.h>
#include<string.h>

int main ()
{
	char buff[7];
	int password;
	int check=0;
	
	printf("Enter the password to gain access: ");
	gets(buff);
	
	check= strcmp(buff,"hithere");
	
	if(check){
		printf("\nWrong password");
	}
	
    else{
		printf("\nCorrect password");
		password=1;
	}
	
	
	if(password){
		printf("\nAccess granted");
	}

	return 0;
	
}
