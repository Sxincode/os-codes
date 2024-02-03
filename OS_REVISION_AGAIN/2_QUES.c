// Q.Programs using the following system calls of UNIX operating 
// system fork, exec, getpid, exit, wait, close, stat, opendir, 
// readdir

/*
Remaining methods;
1. exec
2. wait
3. close
4. stat
5. opendir
6. readdir
*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    int pid;
    pid=fork();

    if(pid<0)
    {
        printf("Error process creation!\n");
        exit(1);
    }
    else if(pid==0)
    {
        printf("Child Process Created!\n");
        printf("Child Process id : %d",getpid());
        printf("Parent Process id : %d",getppid());
    }
    else
    {
        printf("Parent Process!\n");
        printf("Process Id:%d\n",getpid());
    }
    return 0;
}