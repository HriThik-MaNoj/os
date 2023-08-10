#include<stdio.h>
void main()
{
	int n,i,j,temp,pid[20],at[20],pri[20],bt[20],tat1[20],ct[20],sum=0;
	float ttat=0.0;
	float twt=0.0;
	float atat,awt;
	printf("enter the no. of process : ");
	scanf("%d",&n);
	printf("\nenter the process id : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pid[i]);
	}
	printf("\nenter the arrival time : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
	}
	printf("\nenter the burst time : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	printf("\nenter the priority : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pri[i]);
	}
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(pri[i]>pri[j])
			{
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
		
				temp=pid[i];
				pid[i]=pid[j];
				pid[j]=temp;
				
				temp=pri[i];
				pri[i]=pri[j];
				pri[j]=temp;
				
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
			}
		}
	}
	printf("\nprocess id  arrival time  burst time  priority  completion time  tat time  waiting time\n");
	
	for(j=0;j<n;j++)
	{
		ct[j]=0;
		sum=sum+bt[j];
		ct[j]=ct[j]+sum;			
	}
	ct[0]=bt[0];
	tat1[0]=bt[0];
	for(i=0;i<n;i++)
	{
		tat1[i]=ct[i]-at[i];
		ttat=ttat+tat1[i];
	}
	int wt[n];
	wt[0]=0;
	for(i=0;i<n;i++)
	{
		wt[i]=tat1[i]-bt[i];
		twt=twt+wt[i];
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",pid[i]);
		printf("%d\t\t",at[i]);
		printf("%d\t",bt[i]);
		printf("%d\t\t",pri[i]);
		printf("%d\t\t",ct[i]);
		printf("%d\t\t",tat1[i]);
		printf("%d\t\t",wt[i]);
		printf("\n");
	}	
	atat=ttat/n;
	awt=twt/n;
	printf("avg tat=%f\n",atat);
	printf("avg wt=%f\n",awt);
	printf("\n");
	printf("GANTT CHART\n");
	for(i=0;i<n;i++)
	printf("--------");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("|");
		for(i=0;i<n;i++)
		{
			printf("\tP[%d]|",pid[i]);
		}
		}
	printf("\n");
	for(i=0;i<n;i++)
	printf("--------");
	printf("\n");
	printf("%d\t",wt[0]);
	for(i=1;i<n;i++)
	printf("%d\t",ct[i-1]);
	printf("%d\t",ct[i-1]);
}	
	
			
		
		
