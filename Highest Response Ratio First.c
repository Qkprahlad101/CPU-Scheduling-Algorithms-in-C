#include<stdio.h>
struct process
{
 int at,bt,ct,wt,tat;
 int completed;
}p[10];

int n;

void sortByArrival()
{
	struct process temp;
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	{
 		if(p[i].at>p[j].at)
 		{
  			temp=p[i];
  			p[i]=p[j];
  			p[j]=temp;
 		}
	}
}
void main()
{
 	int i,j,time,sum_bt=0;
    float avgwt=0,avgtat=0,temp;
 	printf("Enter no of processes:");
 	scanf("%d",&n);

	printf("Enter the arrival times: ");
	for(i=0;i<n;i++)
	  scanf("%d",&p[i].at);
	printf("Enter the burst times: ");
	for(i=0;i<n;i++)
	  scanf("%d",&p[i].bt);
	  
	for(i=0;i<n;i++)
	{
	p[i].completed=0;
 	sum_bt+=p[i].bt;
	}
	    
	sortByArrival();

	printf("\nAT\tBT\tWT\tTAT");
  	for(time=p[0].at;time<sum_bt;)
  	{
  
   		float hrr=-999;
   		int ind;   //to store index of the hrr process
  		for(i=0;i<n;i++)
  		{
  
   		if(p[i].at<=time && p[i].completed!=1)
            {
              temp=(p[i].bt + (time-p[i].at))/p[i].bt;  // temp is the variable storing response ratio
              if(hrr < temp)
               {
                hrr=temp;
                ind=i;
               }
          
  			 }
   		}
  
  
   time+=p[ind].bt; 
   p[ind].wt=time-p[ind].at-p[ind].bt;
   p[ind].tat=time-p[ind].at;
   p[ind].completed=1;
   avgwt+=p[ind].wt;
   avgtat+=p[ind].tat;
	printf("\n%d\t%d\t%d\t%d",p[ind].at,p[ind].bt,p[ind].wt,p[ind].tat);
  }

	printf("\nAverage wt and tat:%f and %f\n",avgwt/n,avgtat/n);
}
