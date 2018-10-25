#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int binary_search(int arr[], int start, int end, int val)
{
    if(start > end)
        return 0;

    int mid = (start + end)/2;

    if(arr[mid]==val)
        return 1;

    if(arr[mid] < val)
        return binary_search(arr,mid+1,end,val);

    else
        return binary_search(arr,start,mid-1,val);

}

int main(int argc, char const *argv[])
{
    int n = argc,val;
    int arr[n];

    for(int i=0;i<n;i++)
        arr[i] = atoi(argv[i]);

    printf("Enter element : \n");
    scanf("%d",&val);

    /*for(int i=0;i<n;i++)
    {
        if(arr[i] == val)
        {
            printf("Found at %d\n",i );
            exit(0);
        }
    }

    printf("Not Found\n");*/

    if(binary_search(arr,0,n-1,val))
        printf("Found\n");

    else
        printf("Not found\n");

    return 0;
}
