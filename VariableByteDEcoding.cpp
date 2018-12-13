// Program for Variable Byte Decoding
// Coded By Shiva Ram Dam, MScISE-Batch 2018, Gandaki College of Engineering and Science, Pokhara, Nepal.


#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
	char VB[128];
	int sm,dec,itv[1000];
	int i,j,m=0,x=0,p,b,ctr=0;
	int tempID=0;
	long int ID=0;
	
// CODE FOR TAKING VB CODE STREAM
	
	printf("\nEnter the Variable Byte Code\n\n");
	scanf("%s",&VB);
	int l=strlen(VB);
	//int n = l/8;

//code for taking out intermediate values before taking out GAP values
	
	printf("\n------------------------------------------------------------------\n");
	printf("The Intermediate values before taking out the gap are:\n");
		for(i=0;i<l;i=i+8)
		{
			p=8;		//for power
			x=m;		//for loop j
			sm=0;		// for summing or accumulating
			for(j=x;j<x+8;j++)
			{
				p=p-1;
				//printf("%d\t",p);	
				if(VB[j]=='1')
					{
						b=1;
						dec=b*pow(2,p);
						sm=sm+dec;
						//printf("%d\t",dec);
					}
				m=m+1;
			}
			itv[ctr]=sm;
			printf("%d\t",itv[ctr]);		//itv[] refers intermediate values
			ctr=ctr+1;
		}

//code for arranging the intermediate values in 2-D array
		
		int gp[100][100];
		int r=0,k=0,c=0;
		for(i=0;i<ctr;i++)
		{
			if(itv[i]<128)
			{
				gp[r][k]=itv[i];
				//printf("gp[%d][%d]=%d\n",r,k,gp[r][k]);
				//printf("%d\t",gp[r][k]);
				r=c;
				k=k+1;
			}
			else
			{
				gp[r][k]=itv[i];
				//printf("gp[%d][%d]=%d\n",r,k,gp[r][k]);
				//printf("%d\t",gp[r][k]);
				c=c+1;
				r=c;
				k=0;				
			}
			
		}
		
//code for calculating the gaps
		
		
		printf("\n------------------------------------------------------------------\n");
		printf("\n The gaps in reverse order are:\n");
		int pr=0,gap[100];
		for(i=ctr-1;i>=0;i--)
		{
			gap[i]=0;
			pr=0;
			for(j=ctr-1;j>=0;j--)
			{
				//printf("gp[%d][%d]=%d\n",i,j,gp[i][j]);
				if(gp[i][j]==0)
					gap[i]=0;
				else if(gp[i][j]>=128)
				{
					gp[i][j]=gp[i][j]-128;
					//printf("TEST %d",gp[i][j]);
					gap[i]=gap[i]+gp[i][j]*pow(128,pr);
					pr++;
				}
				else
				{
					gap[i]=gap[i]+gp[i][j]*pow(128,pr);	
					pr++;
				}
			}
			printf("%d\t",gap[i]);
		}
		
		
//code for calculating and printing the docIDs
		printf("\n------------------------------------------------------------------\n");
		printf("\nThe docIDs are:\n");	
		long int docID[100];
		docID[0]=0;
		for(i=0;i<ctr;i++)
		{
			if(gap[i]==0)
				break;
			//printf("%d\n",sum[i]);			
			docID[i]=docID[i-1]+gap[i];
			printf("%ld\t",docID[i]);
		}	
		printf("\n------------------------------------------------------------------\n");		
}

/*
For Testing:
0000011010001001000000010000010011000110
000001101000100100000001000001001100011000010000011011101110010100001110011000010011110111010100
*/
