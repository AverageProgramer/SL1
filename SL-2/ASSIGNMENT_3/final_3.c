#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<malloc.h>

int **a,**b,**ans;
//int a[20][20], b[20][20] , ans[20][20];
int r1,c1,r2,c2;

typedef struct position
{
    int row,col;
}position;


void Read()
{
   ans = a = (int**)malloc(r1*sizeof(int));
    b = (int**)malloc(r2*sizeof(int));
    ans = (int**)malloc(r1*sizeof(int));

    for(int i=0;i<r1;i++)
    {
        a[i] = (int *)malloc(c1*sizeof(int));
        ans[i] = (int *)malloc(c2*sizeof(int));
    }

    for(int i=0;i<r2;i++)
        b[i] = (int *)malloc(c2*sizeof(int));


    printf("MAT a :\n");
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
            scanf("%d",&a[i][j]);
    }

    printf("MAT b :\n");
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
            scanf("%d",&b[i][j]);
    }

}

void * matrix_mult(void * arg)
{
    position * pos = (position *)arg;
    int r = pos->row;
    int c = pos->col;

    ans[r][c]=0;

    for(int i=0;i<r2;i++)
        ans[r][c] += a[r][i] * b[i][c];

}

int main()
{
    printf("r1 c1 r2 c2\n");
    scanf("%d %d %d %d",&r1,&c1,&r2,&c2);

    while(r2 != c1)
    {
        printf("r1 c1 r2 c2\n");
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    }

    Read();

    pthread_t thread_arr[100];
    int count=0;

    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            position *pos = (position *)malloc(sizeof(position));

            pos->row = i;
            pos->col = j;

            pthread_create(&thread_arr[count++], NULL, matrix_mult, (void *)pos);
        }
    }

    for(int i=0;i<count;i++)
        pthread_join(thread_arr[i],NULL);

    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
            printf("%d\t",ans[i][j] );

        printf("\n");
    }

}
