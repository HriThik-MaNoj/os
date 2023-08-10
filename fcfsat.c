#include<stdio.h>
void main()
{
	int n,i,j,bt[20],pid[20],at[20],ct[20],t,tat1[20];
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
	printf("\nenter the arrival time: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
	}
	printf("\nenter the burst time : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(at[i]>at[j])
			{
				t=at[i];
				at[i]=at[j];
				at[j]=t;
				t=pid[i];
				pid[i]=pid[j];
				pid[j]=t;
				t=pid[i];
				pid[i]=pid[j];
				pid[j]=t;
			}
		}
	}			
	int wt[n];
	wt[0]=0;
	printf("\nprocess id  arrival time  burst time  completion time  turnaround time  waiting time\n");
	for(i=0;i<n;i++)
	{
		ct[0]=bt[0];
		ct[i]=ct[i-1]+bt[i];
	}	
	for(i=0;i<n;i++)
	{
		tat1[i]=ct[i]-at[i];
		ttat=ttat+tat1[i];
	}
	for(i=0;i<n;i++)
	{
		wt[i]=tat1[i]-bt[i];
		twt=twt+wt[i];
	}		
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",pid[i]);
		printf("%d\t\t",at[i]);
		printf("%d\t\t",bt[i]);
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
	int tbt=0;
	printf("GANTT CHART\n");
	for(i=0;i<n;i++)
	printf("---------------");
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
	printf("---------------");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d       ",tbt);
		tbt=tbt+bt[i];
	}	
	printf("%d      ",tbt);
	}
			
	
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
