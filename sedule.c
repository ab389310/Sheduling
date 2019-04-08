#include<stdio.h>

int main()
{    
    printf("\n\n=========================================>>>  Non Pre-emptive Scheduling  <<<=========================================");
	printf("\n\n========================================>>>  Priority Based on Burst Time  <<<========================================"); 
	printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n");    
    int i,j,n,k,l,pos,random,random2,random3,min,maxp,maxloc;
    printf("\n=>Enter the number of Process -> ");
    scanf("%d",&n);
    int BurstTime[n],Process[n],WaitingTime[n],Arrival[n];
    float priority[n],wrandom,AvgTat=0,AvgWt=0;
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n");
    for(i=0;i<n;i++)
    {
        printf("=>Enter arrival time for Process %d -> ",i+1);
        scanf("%d",&Arrival[i]);           
	}
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n");
    for(i=0;i<n;i++)
    {
        printf("=>Enter burst time for Process %d ->",i+1);
        scanf("%d",&BurstTime[i]);
        Process[i]=i+1;          
	} 
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n");
	WaitingTime[0]=0;
	if(n>1)
	{
	min=Arrival[0];
	pos=0;
	for(i=1;i<n;i++)
	{
	   if(Arrival[i]<min)
		  {
		  min=Arrival[i];
		  pos=i;
	      }	   
	}
	random=Process[pos];
	random2=BurstTime[pos];
	random3=Arrival[pos];
    for(i=pos-1;i>=0;i--)
	{
		Process[i+1]=Process[i];
		BurstTime[i+1]=BurstTime[i];
		Arrival[i+1]=Arrival[i];
	}
	Process[0]=random;
	BurstTime[0]=random2;
	Arrival[0]=random3;	
	for(i=1;i<n;i++)
	{   
	   wrandom=(BurstTime[i-1]+Arrival[i-1]);
		for(j=i;j<n;j++)
		{   

			if(Arrival[j]<=wrandom)
		     {
			  priority[j]=1+((wrandom-Arrival[j])/BurstTime[j]);
		     }
		   else
		     {
			  priority[j]=0;
		     }

	   }	   
	   maxloc=i;
	   maxp=priority[i];
	   for(k=i+1;k<n;k++)
		{
			if(maxp<priority[k])
			{
				maxp=priority[k];
				maxloc=k;
			}
		}

		random=Process[maxloc];
	   random2=BurstTime[maxloc];
	   random3=Arrival[maxloc];
	   for(l=maxloc-1;l>=i;l--)
         	{
		Process[l+1]=Process[l];
		BurstTime[l+1]=BurstTime[l];
		Arrival[l+1]=Arrival[l];
	       }
	   Process[i]=random;
	   BurstTime[i]=random2;
	   Arrival[i]=random3;
	}
	wrandom=Arrival[0];
	for(i=1;i<n;i++)
	{   
	   wrandom +=BurstTime[i-1];
		WaitingTime[i]=wrandom-Arrival[i];
		if(WaitingTime[i]<0)
		WaitingTime[i]=0;
	}	
    }
    printf("\n Process\t          Burst Time    \tWaiting Time\t      Arrival Time\t   Turn Around Time\n");
    for(i=0;i<n;i++)
    {        
        printf("\n Process%d\t\t\t %d\t\t        %d\t    \t\t%d\t\t \t%d\n",Process[i],BurstTime[i],WaitingTime[i],Arrival[i],WaitingTime[i]+BurstTime[i]);
        AvgTat=AvgTat+WaitingTime[i]+BurstTime[i];
        AvgWt=AvgWt+WaitingTime[i];
    }
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n");
    printf("=>Average Turn Around Time -> %f",AvgTat/n);
    printf("\n=>Average Waiting Time -> %f",AvgWt/n);
    printf("completion");
    return 0;
}

