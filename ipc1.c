#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
void main()
{
	int i,shmid;
	char buff[100];
	void *shared_memory;
	shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
	printf("key of shared memory is %d",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("\nprocess attached=%p\n",shared_memory);
	printf("data read from shared memory=%s\n",(char*)shared_memory);
}	

