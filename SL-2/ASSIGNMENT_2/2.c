#include <stdlib.h>
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
	
	printf("Enter choice 1.Zombie \n 2.Orphan\n");
	int ch;
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
				pid_t pid=fork();
				if(pid==0)
				{
					qsort(a, n, sizeof(int), cmpfunc);
					printf("\nChild process \n");
    					
    					for(int i=0;i<n;i++)
						printf("%d ",a[i] );
					printf("\n");	
    					printf("\nPID of child process: %d",getpid());
    					printf("\nPID of parent process: %d\n",getppid());
    					
 					sleep(1);  				
    					system("ps -elf | grep a.out");
						
					

				}
				else 
				{
					sleep(10);
					system("wait");
					qsort(a, n, sizeof(int), cmpfunc);
					printf("\nParent process \n");
    					
    					for(int i=0;i<n;i++)
						printf("%d ",a[i] );
					printf("\n");	
    					
					
					system("ps -elf |grep a.out");

				}
		}
		break;
		case 2:
		{
			pid_t pid=fork();
			if(pid==0)
			{
			
				qsort(a, n, sizeof(int), cmpfunc);
				printf("\nChild process \n");
    					
    				for(int i=0;i<n;i++)
					printf("%d ",a[i] );
				printf("\n");	
    				printf("\nPID of child process: %d",getpid());
    				printf("\nPID of parent process: %d\n",getppid());
				
				sleep(10);
				system("ps -elf |grep a.out");
						
				
			}
			else 
			{
				//system("wait");
				qsort(a, n, sizeof(int), cmpfunc);
				printf("\nParent process \n");
    					
    				for(int i=0;i<n;i++)
					printf("%d ",a[i] );
				printf("\n");	
    			
				system("ps -elf |grep a.out");
				exit(0);
			}
		}
		break;
	}

	//Zombie
	/*
	if(pid==0)
	{
	
		printf("Child Process\tId: %d %d\n",getpid(),getppid());
		qsort(a, n, sizeof(int), cmpfunc);
		for(int i=0;i<n;i++)
			printf("%d ",a[i] );
		
		//system("ps -elf |grep a.out");
		exit(0);

	}
	else 
	{
		system("wait");
		printf("Parent process\tId: %d %d\n",getpid(),getppid());
		sleep(10);
		system("ps -elf |grep a.out");

	}
	*/
	//ORPHAN
	/*
	if(pid==0)
	{
	
		printf("Child Process\tId: %d %d\n",getpid(),getppid());
		qsort(a, n, sizeof(int), cmpfunc);
		for(int i=0;i<n;i++)
			printf("%d ",a[i] );
		sleep(10);
		system("ps -elf |grep a.out");
				
		
	}
	else 
	{
		//system("wait");
		printf("Parent process\tId: %d %d\n",getpid(),getppid());

		exit(0);
		//system("ps -elf |grep a.out");
	}
	*/
	return 0;
}
