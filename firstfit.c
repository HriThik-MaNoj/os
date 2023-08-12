#include <stdio.h>
void main(){

	int i,j,bsize[20],psize[20],bno,pno,flags[20],allocation[20];
	
	for(i = 0; i < 20; i++){
	
		flags[i] = 0;
		allocation[i] = -1;
	}
	
	printf("Enter the no of blocks : ");
	scanf("%d",&bno);
	printf("Enter the size of each block : ");
	for(i = 0; i < bno; i++){
	
		scanf("%d",&bsize[i]);
	}
	printf("Enter the no of processes : ");
	scanf("%d",&pno);
	printf("Enter the size of each process : ");
	for(i = 0; i < pno; i++){
	
		scanf("%d",&psize[i]);
	}
	
	for(i = 0; i < pno; i++){
	
		for(j = 0; j < bno; j++){
		
			if(flags[j] == 0 && bsize[j] >= psize[i]){
			
				allocation[j] = i;
				flags[j] = 1;
				break;
			}
		}
	}
	printf("\nBlock no\t\tsize\t\tProcess no\t\tsize\n");
	for(i = 0; i < bno; i++){
	
		printf("\n%d\t\t%d\t\t\t",i+1,bsize[i]);
		if(flags[i] == 1){
		
			printf("%d\t\t\t%d",allocation[i] + 1,psize[allocation[i]]);
		}
		else{
		
			printf("Not allocated ");
		}
	}
}
			
	
	
