#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<malloc.h>
pthread_mutex_t memory;
sem_t read_access;
int curr_reading=0;

void * Writer(void *arg)
{
	while(1)
	{
		sleep(1);
		int curr_writer=(int)arg;
	
		printf("\nWriter %d is trying to enter into database for modifying the data\n",curr_writer);
		 pthread_mutex_lock(&memory);	// while writing no one can access memory
		 
		printf("\nWriter %d is writting into the database\n",curr_writer);	
	
		printf("\nWriter %d is leaving the database\n",curr_writer);
		pthread_mutex_unlock(&memory);
	}
}

void *Reader(void *arg)
{
	while(1)
	{
		sleep(1);
		int temp=(int)arg;
	
		printf("\nReader %d is trying read memory !!\n",temp);
		sem_wait(&read_access);		// enter critical section (reader ENTERD)
		curr_reading++;				// increment current reading readeres
	
		if(curr_reading == 1)
			 pthread_mutex_lock(&memory);		// memory is USED by writer only
			 									// so if reader is reading, lock it
			sem_post(&read_access);
		printf("\nReader %d is reading the database\n",temp);
		// exit critical section
	
		sem_wait(&read_access);		// enter critical section (reader EXITING)
		printf("\nReader %d is leaving the database\n",temp);
		curr_reading--;
	
		if(curr_reading==0)	
			pthread_mutex_unlock(&memory);	
	
		sem_post(&read_access);		// exit critical section
	}
}

void init()
{	if (pthread_mutex_init(&memory, NULL) != 0)
	{
	    printf("\n mutex init failed\n");
	
	}
	sem_init(&read_access,0,1);	
}

int main()
{
	int i=0,readers=0,writers;
	init();

	pthread_t *Readers_thr,*Writer_thr;
	
	printf("\nEnter number of Readers thread : ");
	scanf("%d",&readers);
	printf("\n");
	
	printf("\nEnter number of Writers thread : ");
	scanf("%d",&writers);
	printf("\n");
	
	Readers_thr=(pthread_t*)malloc(sizeof(pthread_t)*readers);
	Writer_thr=(pthread_t*)malloc(sizeof(pthread_t)*writers);
	
	for(i=0;i<readers;i++)
	{
		pthread_create(&Readers_thr[i],NULL,Reader,(void *)i);
	}
	
	for(i=0;i<writers;i++)
	{
		pthread_create(&Writer_thr[i],NULL,Writer,(void *)i);
	}
	
	for(i=0;i<writers;i++)
	{
		pthread_join(Writer_thr[i],NULL);
	}

	for(i=0;i<readers;i++)
	{
		pthread_join(Readers_thr[i],NULL);
	}
	
	pthread_mutex_destroy(&memory);

	return 0;
}

