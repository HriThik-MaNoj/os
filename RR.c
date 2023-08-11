#include<stdio.h>
void main()
{
	int i,j,flag=0,at[10],bt[10],n,rt[10],remain,wt[10],tq,tat[10];
	float ttat=0.0;
	float twt=0.0;
	float atat,awt;
	printf("enter the no. of process :");
	scanf("%d",&n);
	remain=n;
	for(i=0;i<n;i++)
	{
		printf("\nenter the arrival time and burst time of %d ",i+1);
		scanf("%d",&at[i]);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	printf("\nenter the time quantum " );
	scanf("%d",&tq);
	
	printf("\n\tprocess\t\tturnaround time\t\twaiting time\n");
	int ct;
	for(ct=0,i=0;remain!=0;)
	{
		if(rt[i]<=tq&&rt[i]>0)
		{
			ct=ct+rt[i];
			rt[i]=0;
			flag=1;
		}
		else if(rt[i]>0)
		{
			rt[i]=rt[i]-tq;
			ct=ct+tq;
		}
		if(rt[i]==0&&flag==1)
		{
			remain--;
			printf("\tP[%d]\t\t%d\t\t\t%d\t\t",i+1,ct-at[i],ct-at[i]-bt[i]);
			printf("\n");
			twt=twt+ct-at[i]-bt[i];
			ttat=ttat+ct-at[i];
			flag=0;
		}
		if(i==n-1)
		i=0;
		else if(at[i+1]<=ct)
		i++;
		else
		i=0;
		}
		atat=ttat/n;
		awt=twt/n;
		printf("avg.wt=%f\n",awt);		
		printf("avg.tat=%f",atat);	
		}	
	
