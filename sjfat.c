#include<stdio.h>
struct process{
	int pid;
	int at;
	int bt;
	int tat;
	int wt;
	int ct;
};
void main()
{
	int n,i,j,sum=0;
	printf("\nenter the no. of process : ");
	scanf("%d",&n);
	struct process p[n],temp;
	printf("\nenter the process id : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i].pid);
	}
	printf("\nenter the arrival time : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i].at);
	}
	printf("\nenter the burst time : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i].bt);
	}
	for(i=0;i<n;i++)
	{
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
	int current_time=p[0].at;
	int sji;
	for(i=0;i<n;i++)
	{
		sji=i;
		for(j=i+1;j<n;j++)
		{
			if(p[j].at<=current_time&&p[j].bt<p[sji].bt)
			{
				sji=j;
			}
		}
	temp=p[i];
	p[i]=p[sji];
	p[sji]=temp;
	p[i].wt=current_time-p[i].at;
	p[i].tat=p[i].wt+p[i].bt;
	current_time=current_time+p[i].bt;
	}
	for(j=0;j<n;j++)
	{
	p[j].ct=0;
	sum=sum+p[j].bt;
	p[j].ct=p[j].ct+sum;
	}
	printf("\npid     at     bt     ct      tat     wt\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",p[i].pid);
		printf("%d\t",p[i].at);
		printf("%d\t",p[i].bt);
		printf("%d\t",p[i].ct);
		printf("%d\t",p[i].tat);
		printf("%d\t",p[i].wt);
		printf("\n");
	}
	float ttat=0.0;
	float twt=0.0;
	float atat,awt;
	for(i=0;i<n;i++)
	{
	ttat=ttat+p[i].tat;
	twt=twt+p[i].wt;
	}
	printf("avg tat=%f\n",ttat/n);
	printf("avg wt=%f\n",twt/n);
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
			printf("\tP[%d]|",p[i].pid);
		}
	}	
	printf("\n");
	for(i=0;i<n;i++)
	printf("--------");
	printf("\n");
	printf("%d        ",p[0].wt);
	for(i=0;i<n;i++)
	printf("%d       ",p[i].ct);
}	
		  						
