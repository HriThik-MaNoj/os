#include <stdio.h>
#include <math.h>



void main(){

	int queue[100],i,n,j,k,diff,head,seek = 0;
	float avg;
	
	printf("Enter the number of elements in the queue : ");
	scanf("%d",&n);
	printf("Enter the queue : ");
	for(i = 1; i < n; i++){
	
		scanf("%d",&queue[i]);
	}
	printf("Enter the initial head position : ");
	scanf("%d",&head);
	queue[0] = head;
	
	for(i = 0; i < n; i++){
	
		diff = abs(queue[i+1] - queue[i]);
		seek += diff;
		printf("Move from %d to %d with seek  %d\n",queue[i],queue[i+1],diff);
	}
		avg = (float)seek/(float)n;
		printf("Average seek time = %f ",avg);
	
}

