// Program for Gamma  Encoding
// Coded By Shiva Ram Dam, MScISE-Batch 2018, Gandaki College of Engineering and Science, Pokhara, Nepal.
// 14 December 2018

#include<stdio.h> 

//function to convert decimal value to binary
int decToBinary(int num) 
{ 
	int remainder, base = 1, binary = 0;
		while (num > 0)
	    {
	        remainder = num % 2;
	        binary = binary + remainder * base;
	        num = num / 2;
	        base = base * 10;
	    }
	return binary;
} 

int binaryToOffset(int num) 
{ 
	int rem, base = 1, binary = 0;
		while (num > 0)
	    {
	        rem = num % 2;
	        binary = binary + rem * base;
	        num = num / 2;
	        base = base * 10;
	    }
	return binary;
} 

//function to convert integer to string and remove the most significant digit
void tostring( int num)
{
    int i, rem, len = 0, n;
    char str[10];
    n = num;
    while (n>0)
    {
        len++;
        n =n/10;
    }
    
    for (i = 0; i <len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[i] = rem + '0';
    }
    str[len] = '\0';
    
	for (i = len-2; i >=0; i--)
    {
        printf("%c",str[i]);
    }  
}

main()
{
	long int i,j, ID[100], num, gap[100],r[100][100],q[100];
	int gap_bin[100];
	printf("enter how many DocIDs?\n");
	scanf("%ld",&num);
	printf("\nEnter the Posting sequence:\n");
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
	
	
	//for displaying gap values in binary 
	printf("\nGap value in binary value:\n");

	for(i=0;i<num;i++)
	{
		gap_bin[i]=decToBinary(gap[i]) ;
	    printf("%d\t",gap_bin[i]);
	}
	
	
	//for calculating offset
	int offset[100];
	for(i=0;i<num;i++)
	{

		offset[i]=binaryToOffset(gap[i]);
	    //printf("%d\t",offset[i]);		
	}
	
	
	//for calculating length value
	int length[100];
	for(i=0;i<num;i++)
	{
		int len=0,c=1,temp,rem;
		temp=offset[i];
		while(temp>0)
		{
			temp=temp/10; 
			c=c*10;
			len=len+c;
		}
		length[i]=len;
	}
	printf("\n");
	
	
	
	//displaying postinglist, binary value, length, offset and gamma code
	

	printf("\n------------------------------------------------------------------------------------\n");	
	printf("\nPosting List\t\t Gap\t\t Binary Value\t\t\tGamma code\n");
	printf("\n------------------------------------------------------------------------------------\n");
	for (i=0;i<num;i++)
		{
			printf("%d\t\t\t%d\t\t\t%d\t\t\t",ID[i],gap[i],gap_bin[i]);
			tostring(length[i]);
			printf("\t");
			tostring(offset[i]);
			printf("\n");
		}
}


//For testing:
/* No of Doc IDs : 5
Posting list:
5	15	18	77	84

*/






