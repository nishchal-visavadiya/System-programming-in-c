#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char s[100],*lhs,*rhs,*pro_alt,A[100]={'\0'},B[100]={'\0'};
	int flag=0,i=0,j=0;
	printf("Enter the production:");
	scanf("%s",&s);
	
	lhs = strtok(s,"->");
	rhs = strtok(NULL,"->");
	pro_alt = strtok(rhs,"|");
	strcat(A,lhs);
	strcat(A,"->");
	strcat(B,lhs);
	strcat(B,"'->");
	
	while(pro_alt!=NULL)
	{
		if(s[0]==pro_alt[0])
		{
			flag=1;
			if(i==0)
			{
             strcat(B,pro_alt+1);
			 strcat(B,lhs);
			 strcat(B,"'");
			 i++;
			}
			else
			{
			 strcat(B,"|");
             strcat(B,pro_alt+1);
			 strcat(B,lhs);
			 strcat(B,"'");
			}			
		}
		else
		{
			if(j==0)
			{
             strcat(A,pro_alt);
			 strcat(A,lhs);
		 	 strcat(A,"'");
		 	 j++;
			}
			else
			{
		     strcat(A,"|");
             strcat(A,pro_alt);
		     strcat(A,lhs);
			 strcat(A,"'");
			}
		}
	    pro_alt= strtok(NULL,"|");
	}
	strcat(B,"|");
	strcat(B,"\356\0");
	if(flag==1)
	{
		printf("%s\n%s",A,B);
	}
	else
	printf("Provided production does not containt left recursion");
	return 0;
}
