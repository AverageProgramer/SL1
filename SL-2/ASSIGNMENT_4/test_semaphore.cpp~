#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


pthread_t *producers;
pthread_t *consumers;

sem_t buf_mutex,empty_count,fill_count;


int *buf,buf_pos=-1,prod_count,con_count,buf_len;


int produce(pthread_t self)
{
    int i = 0;
    int p = 1 + rand()%40;
    while(!pthread_equal(*(producers+i),self) && i < prod_count)
    {
        i++;
    }
    printf("Producer %d produced %d \n",i+1,p);
    return p;
}


void consume(int p,pthread_t self)
{
    int i = 0,j;
    while(!pthread_equal(*(consumers+i),self) && i < con_count)
    {
        i++;
    }

    printf("Buffer:");
    for(j=0;j<=buf_pos;++j)
        printf("%d ",*(buf+j));
    printf("\nConsumer %d consumed %d \nCurrent buffer len: %d\n",i+1,p,buf_pos);

}


void* producer(void *args)
{

    while(1)
    {
        int p = produce(pthread_self());
        sem_wait(&empty_count);	// sem wait decrements semaphore value 
        						// Hence decrement empty count as producer has produced value in buffer
        sem_wait(&buf_mutex);	// buf_mutex used for locking(0) and unlocking(1) decrement to lock critical section
        ++buf_pos;          // critical section
        *(buf + buf_pos) = p;	
        sem_post(&buf_mutex);	// sem post increments semaphore value hence increment to unlock
        sem_post(&fill_count);
        sleep(1 + rand()%3);	// wait for random time 
        						// dont create process immediately
    }

    return NULL;
}


void* consumer(void *args)
{
    int c;
    while(1)
    {
        sem_wait(&fill_count); // Hence decrement fill count as consumer has consumed value in buffer
        sem_wait(&buf_mutex);  // buf_mutex used for locking(0) and unlocking(1) decrement to lock critical section
        c = *(buf+buf_pos);	   // c indicates which value is consumed by consumer	
        consume(c,pthread_self());
        --buf_pos;				// critical section
        sem_post(&buf_mutex);	// sem post increments semaphore value hence increment to unlock
        sem_post(&empty_count);
        sleep(1+rand()%5);		// wait for random time 
    }

    return NULL;
}

int main(void)
{

    int i,err;						// err = error generated while creating thread. 0 if none

    srand(time(NULL));

    sem_init(&buf_mutex,0,1);		// 1=unlocked
    sem_init(&fill_count,0,0);		// 0=locked

    printf("Enter the number of Producers:");
    scanf("%d",&prod_count);
    producers = (pthread_t*) malloc(prod_count*sizeof(pthread_t));

    printf("Enter the number of Consumers:");
    scanf("%d",&con_count);
    consumers = (pthread_t*) malloc(con_count*sizeof(pthread_t));

    printf("Enter buffer capacity:");
    scanf("%d",&buf_len);
    buf = (int*) malloc(buf_len*sizeof(int));

    sem_init(&empty_count,0,buf_len);		// initially whole buffer is empty

    for(i=0;i<prod_count;i++)
    {
        err = pthread_create(producers+i,NULL,&producer,NULL);
        if(err != 0)			// err = 0 success else error_number
        {
            printf("Error creating producer %d: %s\n",i+1,strerror(err));
        }
        
        else
        {
            printf("Successfully created producer %d\n",i+1);
        }
    }

    for(i=0;i<con_count;i++)
    {
        err = pthread_create(consumers+i,NULL,&consumer,NULL);        
        
        if(err != 0)
        {
            printf("Error creating consumer %d: %s\n",i+1,strerror(err));
        }
        
        else
        {
            printf("Successfully created consumer %d\n",i+1);
        }
    }

    for(i=0;i<prod_count;i++)
    {
        pthread_join(*(producers+i),NULL);
    }
    
    for(i=0;i<con_count;i++)
    {
        pthread_join(*(consumers+i),NULL);
    }


    return 0;
}
