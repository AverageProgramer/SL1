#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<unistd.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>

int main()
{
    int mem_id,mem_size=15;
    char *argv[3], mem_size_string[20], mem_id_string[20], *temp, message[20] = "hello client";
    void * memory;

    //printf("Size : \n");
    //scanf("%d",&mem_size);

    mem_id = shmget((key_t)rand(), mem_size, IPC_CREAT|0666);

    if(mem_id < 0)
    {
        printf("ERROR in creation\n");
        exit(0);
    }

    sprintf(mem_id_string,"%d",mem_id);
    sprintf(mem_size_string,"%d",mem_size);

    memory = shmat(mem_id, NULL, 0);

    if(memory == NULL)
    {
        printf("ERROR in attachment\n");
        exit(0);
    }

    temp = (char *)memory;

    memcpy(temp,message,strlen(message)+1);
    //printf("%s\n",temp );

    int dettach = shmdt(temp);

    if(dettach <  0)
    {
        printf("ERROR in dettachment\n");
        exit(0);
    }

    argv[0] = mem_id_string;
    argv[1] = mem_size_string;
    argv[2]=NULL;

    execv("./final_client", argv);
}
