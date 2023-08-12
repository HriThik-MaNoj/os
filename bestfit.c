#include <stdio.h>

void main(){

	int i,j,bsize[20],psize[20],bno,pno,flags[20],allocation[20],t;
	
	for(i = 0; i < 10; i++){
	
		flags[i] = 0;
		allocation[i] = -1;
	}
	
	printf("Enter the number of blocks  : ");
	scanf("%d",&bno);
	printf("Enter the size of each block : ");
	for(i = 0; i < bno; i++){
	
		scanf("%d",&bsize[i]);
	}
	
	for(i = 0; i < bno; i++){
	
		for(j = i+1; j < bno; j++){
		
			if(bsize[i] > bsize[j]){
			
				t = bsize[i];
				bsize[i] = bsize[j];
				bsize[j] = t;
			}
		}
	}
	printf("Enter the number of processes : ");
	scanf("%d",&pno);
	printf("Enter the size of each process : ");
	for(i = 0; i < pno; i++){
	
		scanf("%d",&psize[i]);
	}
	
	for(i = 0; i <  pno; i++){
	
		for(j = 0; j < bno; j++){
		
			if(flags[j] == 0 && bsize[j] >= psize [i]){
			
				allocation[j] = i;
				flags[j] = 1;
				break;
			}
		}
	}
	printf("\nBlock no.\t\tsize\t\tprocess no.\t\tsize");
	for(i = 0; i < bno; i++){
	
		printf("\n%d\t\t%d\t\t",i+1,bsize[i]);
		if(flags[i] == 1){
		
			printf("%d\t\t\t%d",allocation[i]+1,psize[allocation[i]]);
		}
		else{
			printf("Not allocated ");
		}
	}
}

	
	
		
