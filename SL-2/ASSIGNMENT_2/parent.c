#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
	int n;
	printf("Enter n : \n");
	scanf("%d",&n);
	int a[n];
	printf("Enter array : \n");

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	
	qsort(a, n, sizeof(int), cmpfunc);
	
	int pid;

	pid=vfork();

	if(pid==0)
	{
		char *arg[100];
		
		for(int i=0;i<n;i++)
		{
			arg[i]=(char*)malloc(100*sizeof(char));
			sprintf(arg[i],"%d",a[i]);

		}
		arg[n]=NULL;
		printf("\nExexv : TO child\n");
		execv("./childout",arg); 

		
	}
	else
	{
		wait(NULL);
		printf("\n\nIn parent");
	}
	return 0;
}
