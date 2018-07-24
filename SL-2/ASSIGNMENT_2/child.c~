#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<string.h>

int main(int argc,char *argv[])
{

    int search,first,last,middle,array[100];
    int i=0;
    char args[100];

    strcpy(args,argv[1]);

    while(args[i]!='\0')
    {
        array[i] = args[i] - '0';
        i++;
    }

     printf("Enter value to find\n");
     scanf("%d",&search);

       first = 0;
       last = i - 1;
       middle = (first+last)/2;

       while (first <= last)
       {
          if (array[middle] < search)
             first = middle + 1;
          else if (array[middle] == search)
          {
             printf("%d found at location %d.\n", search, middle+1);
             break;
          }

          else
             last = middle - 1;

          middle = (first + last)/2;
       }

       if (first > last)
          printf("Not found! %d isn't present in the list.\n", search);

     return 0;
     
     
     //test

}
