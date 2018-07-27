#include<stdio.h>
#include<math.h>
#include<pthread.h>
#include<unistd.h>
#include<malloc.h>
#include<stdlib.h>

int r,c;
int **a,**b,**ans;

typedef struct position
{
    int a,b;
}position;

void * thread_matrix_mult(void *arg)
{
    position *m = (position*)arg;

    int sum=0;
    for(int i=0;i<r;i++)
    {
        sum += (*(*(a+m->a)+i))  * (*(*(b+i)+m->b)) ;
    }

    *(*(ans+m->a)+(m->b)) = sum;

}

void Read()
{
    printf("Enter number of row : ");
    scanf("%d",&r);
    printf("\n");

    printf("Enter number of column : ");
    scanf("%d",&c);
    printf("\n");

    a = (int**)malloc(sizeof(int)*r);
    b = (int**)malloc(sizeof(int)*r);
    ans = (int**)malloc(sizeof(int)*r);

    for(int i=0;i<r;i++)
    {
        a[i] =  (int*)malloc(sizeof(int)*c);
        b[i] =  (int*)malloc(sizeof(int)*c);
        ans[i] =  (int*)malloc(sizeof(int)*c);
    }

    printf("Enter matrix 1 :");

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            scanf("%d",(*(a+i)+j));
    }

    printf("Enter matrix 2 :");

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
             scanf("%d",(*(b+i)+j));
    }

    printf("\n\n");
}

int  main()
{
    Read();

    int count=0;
    pthread_t *arr;

    arr = (pthread_t*)malloc(sizeof(pthread_t)*400);

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            position *pos = (position*)malloc(sizeof(position));
            pos -> a=i;
            pos -> b=j;

            pthread_create((arr+count++),NULL,thread_matrix_mult,(void *)pos);
        }
    }

    for(int i=0;i<count;i++)
        pthread_join(*(arr+i),NULL);

    for(int i=0;i<r;i++)            //printing ans
    {
        for(int j=0;j<c;j++)
        {
             printf("%d ",*(*(ans+i)+j));
        }
        printf("\n");
    }

    return 0;
}



