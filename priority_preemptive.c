// Lower value meaning higher priority


#include<stdio.h>

void main()
{
	int n,i,j=0;
	printf("Enter no. of processes: ");
	scanf("%d",&n);

	int at[n],p[n],bt[n],ct[n],pr[n],pt[n],count=0;

	printf("Enter the Arrival times: ");
	for(i=0;i<n;i++) 
	   scanf("%d",&at[i]);

	printf("Enter the Burst times: ");
	for(i=0;i<n;i++) 
	{
	      scanf("%d",&bt[i]);
	      p[i]=bt[i];
   }

	printf("Enter the Priorities: ");
	for(i=0;i<n;i++) 
	{
	      scanf("%d",&pr[i]);
	      pt[i]=pr[i];
   }
   
   	   
	while(j<n)
	{
		int min=1000,ind=-1,priority=100;
		for(i=0;i<n;i++)
		{
	/*		if(p[i]==min)
			{
				if(at[i]<at[ind])
				ind=i;
			}   */

			if(pt[i]<priority && p[i]>0)
			{
				if(at[i]<=count)
				{
					min=pt[i];
					priority=pt[i];
					ind=i;
				}
			}

		}
		if(ind!=-1)
		{
			count++;
			p[ind]--;
			if(p[ind]==0)
			{
				ct[ind]=count;
				printf("\nCompletion time of process %d is %d",ind+1,ct[ind]);
				p[ind]=1001;
				j++;
				pt[ind]=10001;

			}
		}
		else     //when cpu is idle
		count++;
	}

	int TAT[n],WT[n];

	for(i=0;i<n;i++)
	{
     	TAT[i]=ct[i]-at[i];
    	WT[i]=TAT[i]-bt[i]; 
	 }



	printf("\nProcess Table:\nPid\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	printf("P%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),at[i],bt[i],ct[i],TAT[i],WT[i]);

	float sum=0;
	for(i=0;i<n;i++)
	sum+=(float)TAT[i];
	printf("\nAverage TAT: %f",sum/n);
	sum=0;
	for(i=0;i<n;i++)
	sum+=(float)WT[i];
	printf("\nAverage WT: %f",sum/n);
}
