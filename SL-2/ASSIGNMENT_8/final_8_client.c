#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int mem_id = atoi(argv[0]);
    char * message,*temp;
    void * memory;

    memory = shmat(mem_id,NULL,0);

    message = (char *)memory;

    printf("%s\n",message );

    shmdt(message);
    return 0;
}
