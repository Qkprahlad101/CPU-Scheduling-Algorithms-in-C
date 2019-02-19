#include<stdio.h>

void main()
{
	int n,i,j=0;
	printf("Enter no. of processes:");
	scanf("%d",&n);

	int Arr[n],BT[n],Bt[n],Ct[n],count=0;

	printf("Enter the Arrival time: ");
	for(i=0;i<n;i++)
	  scanf("%d",&Arr[i]);

	printf("Enter the Burst times: ");
	for(i=0;i<n;i++)
	{
	    scanf("%d",&BT[i]);
	    Bt[i]=BT[i];   //Bt is the array on which operations are performed
    }

	while(j<n)
	{
		int min=1000,ind=-1;
		for(i=0;i<n;i++)
		{
			if(Bt[i]==min)  //if 2 or more processes have same burst time,select 1st arrival
			{
				if(Arr[i]<Arr[ind])
				ind=i;
			}

			else if(Bt[i]<min)  
			{
				if(Arr[i]<=count)   //to check if the processes has arrived or not
				{
					min=Bt[i];
					ind=i;
				}
			}

		}
		if(ind!=-1)   
		{
			count+=BT[ind];
			Ct[ind]=count;
			j++;
			Bt[ind]=1001;  //this bt is temp array for comparison
		}
		else
		count++;
	}

	int TAT[n],WT[n];

	for(i=0;i<n;i++)
	{TAT[i]=Ct[i]-Arr[i];
	 WT[i]=TAT[i]-BT[i]; }



	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	printf("P%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),Arr[i],BT[i],Ct[i],TAT[i],WT[i]);

	float sum=0;
	for(i=0;i<n;i++)
	sum+=(float)TAT[i];
	printf("\nAverage TAT: %f",sum/n);
	sum=0;
	for(i=0;i<n;i++)
	sum+=(float)WT[i];
	printf("\nAverage WT: %f",sum/n);
}

