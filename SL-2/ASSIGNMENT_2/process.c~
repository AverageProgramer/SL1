#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);  

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{

    int n;
    printf("Enter length of array : ");
    scanf("%d",&n);
    printf("\n");

    int arr[n];

    printf("Enter Elements of array : ");
    for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
    printf("\n");

    pid_t  process= fork();

    if(process < 0)
    {
        printf("\n------------------------------------------------------------------\n");
        printf("Forking is unsuccesful !!!!\n");
        printf("------------------------------------------------------------------\n");
        exit(0);
    }


    if(process == 0)        //child
    {
        printf("\n------------------------------------------------------------------\n");
        printf("    CHILD PROCESS   \n");
        printf("    PID = %d\n",getpid());
        printf("    PPID = %d\n",getppid());


        //system("wait");
        //sleep(5);


        quickSort(arr,0,n-1);

        printf("    Array sorted !!!\n\t");
        for(int i=0;i<n;i++)
                printf("%d ",arr[i]);
        printf("\n");

        printf("------------------------------------------------------------------\n");
        exit(-1);


    }

    else if(process > 0)
    {
        printf("------------------------------------------------------------------\n");
        printf("    PARENT PROCESS   \n");
        printf("    PID = %d\n",getpid());
        printf("    PPID = %d\n",getppid());

        system("wait");
        sleep(5);

/*
        quickSort(arr,0,n-1);

        printf("    Array sorted !!!\n\t");
        for(int i=0;i<n;i++)
                printf("%d ",arr[i]);
        printf("\n");

        printf("------------------------------------------------------------------\n");
        */

        system("ps -elf | grep a.out");

        //exit(-1);

    }
    return 0;
}
