// Program for Varible Byte Encoding
// Coded By Shiva Ram Dam, MScISE-Batch 2018, Gandaki College of Engineering and Science, Pokhara, Nepal.
// 10 December 2018

#include<stdio.h>

//function to convert decimal inot binary
int decToBinary(int n) 
{ 
    for (int i = 7; i >= 0; i--) 
	{ 
        int k = n >> i; 
        if (k & 1) 
            printf("1"); 
        else
            printf("0"); 
    } 
    printf("\n");
} 
  

main()
{
	long int i,j, ID[100], num, gap[100],r[100][100],q[100];
	printf("enter how many DocIDs?\n");
	scanf("%ld",&num);
	printf("\nEnter the DocIds\n");
	for(i=0;i<num;i++)
	{
		scanf("%ld",&ID[i]);
	}
	
	// for finding gap values
	gap[0]=ID[0];
	for(i=1;i<num;i++)
	{
		gap[i]=ID[i]-ID[i-1];
	}
	
	//for displaying gap values
	printf("\nGap value in decimal value:\n");
	for(i=0;i<num;i++)
	{
		printf("%ld\t",gap[i]);
	}
	
	printf("\n");
	
	//for processing to find the VB codes
	for(i=0;i<num;i++)
	{
		j=0;
		if(gap[i]<128)
		{
			r[i][j]=gap[i];
		}
		
		else
		{
			while(gap[i]>127)
			{
				r[i][j]=gap[i]%128;			
				q[i]=gap[i]/128;
				gap[i]=q[i];
				j++;
				if (q[i]<128)
					break;
			}
		}		
	}
	
	// for printing variable byte codes in binary digits
	printf("\nVB code in decimal value:\n");
	for(i=0;i<num;i++)
	{
		int n=q[i];
		decToBinary(n);
		for(j=i;j>=0;j--)
		{
			if(j==0)
			{
				r[i][j]+=128;
				n=r[i][j];				
			}
			else
				n=r[i][j];
				
			if(n!=0)
				decToBinary(n);
		}
		printf("\n");
	}
}


/*
for Testing
docIDs:
777	17743	294068	31251336
*/





