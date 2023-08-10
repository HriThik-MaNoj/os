#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	pid_t pid,pid1,pid2;
	pid=fork();
	if(pid==-1)
	{
		printf("child process is not created successfully\n");
		exit(1);
	}
	if(pid==0)
	{
		pid1=getpid();
		printf("\nchild process is created with id=%d\n",pid1);	
	}
	else
	{
		pid2=getpid();
		printf("\nparent process is created with id=%d\n",pid2);
	}
}			
