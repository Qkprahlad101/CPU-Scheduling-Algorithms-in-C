#include<stdio.h>

void main()
{
	int n;
	printf("Enter the no of processes: ");
	scanf("%d",&n);
	
	int i,j,p[n],at[n],bt[n],ct[n],tat[n],st,ind,arr[n],l=0,wt[n],sum=0;
	float atat=0,awt=0;
	
	printf("Enter the arrival times: ");
	for(i=0;i<n;i++)
	   scanf("%d",&at[i]);
	   
	printf("Enter the burst times: ");
	for(i=0;i<n;i++)
	    scanf("%d",&bt[i]);
	    
	for(i=0;i<n;i++)
	   p[i]=at[i];
	   
	for(i=0;i<n;i++)
	   printf("%d",p[i]);
	   
	for(i=0;i<n;i++)
	{
		while((p[l]==-1) && (l<n))
		  l++;
		  
		st=p[l];
		
		for(j=0;j<n;j++)
	    {
	    	if((st>=p[j]) &&  (p[j]>-1))
		          ind = j;
		}
		p[ind]=-1;
		arr[i]=ind;
	}
	
	printf("\nArrival time ordered Processes\n");
	for(i=0;i<n;i++)
	   printf("%d\t",arr[i]);   //arr[] is the array which contains indices of the processes in ASC order of AT
	   
	for(i=0;i<n;i++)
	{
		sum=bt[arr[i]]+sum;
		ct[arr[i]]=sum;
		tat[arr[i]]=ct[arr[i]]-at[arr[i]];
		wt[arr[i]]=tat[arr[i]]-bt[arr[i]];
	}
	
	printf("\nPID\tAT\tBT\tCT\tTAT\tWT");
    for(i=0;i<n;i++)
    {
    	printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i,at[arr[i]],bt[arr[i]],ct[arr[i]],tat[arr[i]],wt[arr[i]]);
	}
	
	for(i=0;i<n;i++)
	{
		atat+=tat[i];
		awt+=wt[i];
	}
	printf("\nAverage TAT and WT are: %f and %f",(atat/n),(awt/n));
}












