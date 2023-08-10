#include<stdio.h>
void main()
{
	int n,i,j,pid[20],bt[20],tat1[20];
	printf("enter the no. of process : ");
	scanf("%d",&n);
	printf("\nenter the process id : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pid[i]);
	}
	printf("\nenter the burst time : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(bt[i]>bt[j])
			{
				int t=bt[i];
				bt[i]=bt[j];
				bt[j]=t;
				t=pid[i];
				pid[i]=pid[j];
				pid[j]=t;
			}
		}
	}			
	
	int wt[n];
	wt[0]=0;
	printf("\nprocess id  burst time  turnaround time  waiting time\n");
	tat1[0]=bt[0];
	for(i=1;i<n;i++)
	{
		tat1[i]=tat1[i-1]+bt[i];
	}
	float ttat=0.0;
	for(i=0;i<n;i++)
	ttat=ttat+tat1[i];
	for(i=1;i<n;i++)
	wt[i]=tat1[i]-bt[i];
	float twt=0.0;
	for(i=0;i<n;i++)
	twt=twt+wt[i];
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",pid[i]);
		printf("%d\t\t",bt[i]);
		printf("%d\t\t",tat1[i]);
		printf("%d\t\t",wt[i]);
		printf("\n");
	}
	float atat=0.0;
	float awt=0.0;
	atat=ttat/n;
	awt=twt/n;
	printf("average turnaround time=%f\n",atat);
	printf("average waiting time=%f",awt);
	printf("\n");
	printf("GANTT CHART\n");
	for(i=0;i<n;i++)
	printf("----------");
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
	printf("----------");
	printf("\n");
	for(i=0;i<n;i++)
	printf("%d      ",wt[i]);
	printf("%d       ",tat1[i-1]);
}	
			
	
	
			
			
