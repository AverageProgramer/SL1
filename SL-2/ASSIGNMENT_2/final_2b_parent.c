#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[5]={5,4,3,2,1};

    sort(arr,5);
    char *argv[5],*envp[1],length_string[20];

    envp[0]=NULL;

    int curr_proccess = fork();

    if(curr_proccess < 0)
    {
        printf("Error in fork \n");
        exit(0);
    }

    if(curr_proccess == 0)
        system("wait");

    else
    {
        for(int i=0;i<5;i++)
        {
            argv[i] = (char *)malloc(10*sizeof(char));
            sprintf(argv[i],"%d",arr[i]);
        }

        argv[5]=NULL;

        execve("./final_child",argv,envp);
    }

    return 0;
}
