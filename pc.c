#include<stdio.h>
#include <stdlib.h>

int x=0,mutex=1,full=0,empty=3,n;
void main()
{
	void producer();
	void consumer();
	int wait(int);
	int signal(int);
	printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
	while(1)
	{
	printf("\nenter your choice : ");
	scanf("%d",&n);
	switch(n)
	{
	case 1 : if((mutex==1)&&(empty!=0))
		producer();
		else
		printf("BUFFER IS FULL");
		break;
	case 2 :  if((mutex==1)&&(full!=0))
		consumer();
		else
		printf("BUFFER IS EMPTY");
		break; 	
	case 3 : exit(0);
		break;
	}
	}
	}	
	int wait(int s)
	{
		return(--s);
	}
	int signal(int s)
	{
		return(++s);
	}
	void producer()
	{
		mutex=wait(mutex);
		full=signal(full);
		empty=wait(empty);
		x++;
		printf("\nproducer produces an item=%d",x);
		mutex=signal(mutex);
	}
	void consumer()
	{
		mutex=wait(mutex);
		empty=signal(empty);
		full=wait(full);
		printf("\nconsumer consumes an item=%d",x);
		x--;
		mutex=signal(mutex);
	}
					
