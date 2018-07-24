#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>

int main()
{
	char str[100];
	int i;		
	
	fork();
	pid_t pid=getpid();
	pid_t ppid = getppid();
	pid_t this_id;
	
	this_id = wait(2);

	for(i=0;i<=10;i++)
	{			
	
		
			
		printf("PID = %d value = %d\t",pid,i);
		printf("child of PID = %d\t",ppid);
		printf("Wait returns %d\n",this_id);
	}
	
	return 0;	
}
