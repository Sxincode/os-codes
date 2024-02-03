// ********** IPC using Shared Memory *********

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define SEGMENT_SIZE 100
int main(int argc, char *argv[])
{
    int shmid, cnt;
    key_t key;
    char * segptr;
    char buffer[] = "Yeahboi@@";
    key = ftok(".",'r');
    if((shmid=shmget(key, SEGMENT_SIZE, IPC_CREAT | 0666))<0)
    {
        printf("Error!!");
        exit(1);
    }
    else
    {
        printf("Creating Shared memory\n");
        printf("shmid %d\n",shmid);
    }
    segptr = shmat(shmid, NULL, 0);
    if(segptr==(char*)-1)
    {
        printf("Error T_T");
        exit(1);
    }
    printf("Writing data to shared memory\n");
    strcpy(segptr, buffer);
    printf("DONE\n");
    printf("Reading data from shared memory\n");
    printf("%s \n",segptr);
    printf("DONE\n");
    printf("Removing Shared Memory Segment");
    if(shmctl(shmid, IPC_RMID, 0)==-1)
    {
        printf("Can't remove ");
    }
    else
    {
        printf("Removed");
    }
    return 0;
}