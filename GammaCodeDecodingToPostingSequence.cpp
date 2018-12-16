// Program for Gamma  Decoding
// Coded By Shiva Ram Dam, MScISE-Batch 2018, Gandaki College of Engineering and Science, Pokhara, Nepal.
// 15 December 2018


#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
	char gc_gap[100];
	int i,j,l,x,p,countOne,msbValue,bin,fstart,sstart;
	int end=0,c=0,d=0,ctr=0,sum=0,gap[100],post_seq[100];
	printf("Enter the gamma coded gap:\n");
	scanf("%s",&gc_gap);
	l=strlen(gc_gap);
	

//--------------------------------------------------------------------------------//
//code for getting the length and counting the no of 1s and equivalent decimal value
	for(i=0;i<l;i=i+end)
	{
		//printf("i=%d\n",i);
		fstart=end;
		//printf("fstart=%d\n",fstart);
		c=0;
		for(j=fstart;j<l;j++)
		{
			//printf("%c\t",gc_gap[j]);
			c=c+1;
			if(gc_gap[j]=='0')
				break;
		}
		countOne=c-1;
		msbValue=pow(2,countOne);
		sstart=end+c;
		end=end+(2*c-1);
	
//--------------------------------------------------------------------//		
// code for getting the offset and then calculating the decimal value
		d=0;
		p=0;
		bin=0;
		for(j=end-1;j>=sstart;j--)
		{
			//printf("the offsetin reverse order is: %c\t",gc_gap[j]);
			x=gc_gap[j]-48;
			//printf("x=%d\t",x);
			bin=bin+x*pow(2,p);
			p++;
			d=d+1;
		}
		

		fstart=end;
		i=0;
		gap[ctr]=msbValue+bin;
		sum=sum+gap[ctr];
		post_seq[ctr]=sum;
		ctr++;
	}

//----------------------------------------------------//
//code for displaying
	
	printf("\nThe gap are:\n");
	for(i=0;i<ctr;i++)
	{
		printf("%d\t",gap[i]);	
	}

	printf("\nThe posting sequence is:\n");
	for(i=0;i<ctr;i++)
	{
		printf("%d\t",post_seq[i]);	
	}

}


//---------------------------------------------------------------------------//
	
/*
For testing
1110001
111000111010
111000111010101
11100011101010111111011011
1110001110101011111101101111011

*/
