#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char pro_Arr[50][50]={'\0'},*left,*right,*pro_alt,tmp[100]={'\0'};
	char lnt,Ans[50][50]={'\0'},chr[10]={'\0'},c[2]={'\0'};
	int i=0,j=0,k=0,l=0,m=0,n=0,max_prod,flag=0;

	printf("Enter the production rule:");
	scanf("%s",&tmp);

	left=strtok(tmp,"->");
	lnt=left[0];
	right=strtok(NULL,"->");
	pro_alt=strtok(right,"|");
	max_prod=strlen(pro_alt);

	while(pro_alt!=NULL)
	{
	   if(strlen(pro_alt)>max_prod)
	   max_prod=strlen(pro_alt);
	   strcpy(pro_Arr[i++],pro_alt);
	   pro_alt=strtok(NULL,"|");
	}

	strcpy(Ans[n],left);
	strcat(Ans[n],"->");
	chr[0]='X';

      for(k=0;k<max_prod;k++)
	  {
		flag=0;
		for(j=0;j<i;j++)
		{
		  for(l=0;l<i;l++)
		  {
		   if(pro_Arr[l][0]==pro_Arr[j][0] && l!=j && pro_Arr[l][0]!='\0')
		   {
		     flag++;
		     c[0]=pro_Arr[l][0];
		   }
		  }
		}
		if(flag>0)
		{
		   strcat(Ans[n],c);
		   strcat(Ans[n],chr);
		   for(l=0;l<i;l++)
		   {
		    if(pro_Arr[l][0]==c[0] && pro_Arr[l][0]!='\0')
		    {
		     for(m=0;m<strlen(pro_Arr[l]);m++)
		      pro_Arr[l][m]=pro_Arr[l][m+1];
		      pro_Arr[l][m-1]='\0';
		    }
		    else if(pro_Arr[l][0]!='\0')
		    {
		      if(Ans[n][strlen(Ans[n])-1]!='>')
		      strcat(Ans[n],"|");
		      strcat(Ans[n],pro_Arr[l]);
		      strcpy(pro_Arr[l],NULL);
		    }
		}
		strcat(Ans[++n],chr);
		strcat(Ans[n],"->");
		strcat(chr,"'");
		}
		else
		{
			for(j=0;j<i;j++)
			{
			   if(pro_Arr[j][0]!='\0')
			   {
			    if(Ans[n][strlen(Ans[n])-1]!='>')
			    strcat(Ans[n],"|");
			    strcat(Ans[n],pro_Arr[j]);
			    strcpy(pro_Arr[j],NULL);
			   }
			}
		}
	  }

       for(i=0;i<=n;i++)
       printf("\n%s",Ans[i]);
       return 0;
}


