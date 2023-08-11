#include <stdio.h>
#include <math.h>

void main(){

	int i,j,n,rq[100],initial,TotalHeadMovement = 0,size,move,temp;
	
	printf("Enter the number of requests : ");
	scanf("%d",&n);
	printf("Enter the requests sequence : ");
	for(i = 0; i < n; i++){
	
		scanf("%d",&rq[i]);
	}
	printf("Enter the initial head position : ");
	scanf("%d",&initial);
	printf("Enter the disk size : ");
	scanf("%d",&size);
	
	printf("Enter the direction of head movement 1 for High and 0 for low : ");
	scanf("%d",&move);
	
	for(i = 0; i < n; i++){
	
		for(j = 0; j < n-i-1; j++){
		
			if(rq[j] > rq[j + 1]){
			
				temp = rq[j];
				rq[j] = rq[j+1];
				rq[j+1] = temp;
			}
		}
	}
	
	int index;
	for(i = 0 ; i < n; i++){
	
		if(initial < rq[i]){
		
			index = i;
			break;
		}
	}
	if(move == 1){
	
		for(i = index; i < n; i++){
	
			TotalHeadMovement += abs(rq[i] - initial);
			initial = rq[i];
		}
		TotalHeadMovement += abs(size-rq[i-1]-1);
		initial = 0;
		for(i = 0; i < index; i++){
		
			TotalHeadMovement += abs(rq[i] -initial);
			initial = rq[i];
		}
		
	}
	else{
	
		for(i = index - 1; i >= 0; i--){
		
			TotalHeadMovement += abs(rq[i] - initial);
			initial = rq[i];
		}
		TotalHeadMovement += abs(rq[i+1] - 0);
		initial = size-1;
		for( i = n; i >= index; i--){
		
			TotalHeadMovement += abs(rq[i] - initial);
			initial = rq[i];
		}
		
		
	}
	printf("Total Head Movement  = %d",TotalHeadMovement);
}
		
	
	
	
				
