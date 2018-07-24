#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    char *args[]={"./child",NULL};
    int a[10],num,i;

     printf("enter the no. of elements u want to insert ");
    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
        printf("Enter element ");
        scanf("%d",&a[i]);
    }

    int c,swap,d;
     for (c = 0 ; c <num-1; c++)
    {
        for (d = 0 ; d < num- c - 1; d++)
            {

              if (a[d] > a[d+1])
              {
                swap       = a[d];
                a[d]   = a[d+1];
                a[d+1] = swap;
              }
        }
  }

char output[100];

for (i = 0 ; i < num; ++i)              // convertuing int arr to char arr
{
    output[i] = a[i] + '0';
}
output[i]='\0';

char *argp[]={"./child.out",output,NULL};

   int b = fork();

    if (b == 0)
      execv("./child.out",argp);

    else
        wait(NULL);

    return 0;

}
