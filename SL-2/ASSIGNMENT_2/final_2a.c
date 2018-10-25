#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int arr[5] = {3,1,5,2,4};

    int curr_process = fork();

    if(curr_process < 0)
    {
        printf("Error in fork \n");
        exit(0);
    }

    if(curr_process == 0)
    {
       // system("wait");


        printf("In Child\n");
        printf("Child pid=%d Parent pid=%d\n",getpid(),getppid() );

        //sort(arr,n);
        for(int i=0;i<5;i++)
            printf("%d ",arr[i] );
        printf("\n");

        //system("ps -elf | grep a.out");

    }

    if(curr_process > 0)
    {
        system("wait");


        printf("In Parent\n");
        printf("pid=%d" ,getpid());

        //sort(arr,n);
      /*  for(int i=0;i<5;i++)
            printf("%d ",arr[i] );
        printf("\n");*/

        system("ps -elf | grep a.out");

    }

    return 0;
}
