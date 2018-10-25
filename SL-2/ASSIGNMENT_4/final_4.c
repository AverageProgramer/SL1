#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <malloc.h>
#include <semaphore.h>

sem_t guard,full,empty;

int buffer[10]={-1};
int count=0;

void * production(void * i)
{
    int current_producer = *(int *)i;

    while(1)
    {
        sem_wait(&empty);

        sem_wait(&guard);

                int value = rand()%100;
                buffer[count++] = value;

                printf("Producer %d produced value %d\n",current_producer, value);

                sleep(1);
        sem_post(&guard);

        sem_post(&full);
    }
}

void * consumption(void * i)
{
    int current_consumer = *(int *)i;

    while(1)
    {
        sem_wait(&full);

        sem_post(&guard);

                    int item = buffer[count--];

                    printf("Consumer %d consumed value %d\n",current_consumer,item );

                    sleep(1);
        sem_post(&guard);

        sem_post(&empty);
    }
}

int main()
{
    int no_of_prod;
    int no_of_con;

    sem_init(&guard,1,1);
    sem_init(&empty,1,10);
    sem_init(&full,1,0);

    printf("Prod and cons\n");
    scanf("%d %d",&no_of_prod, &no_of_con);

    pthread_t producers[no_of_prod], consumers[no_of_con];

    for(int i=0;i<no_of_prod;i++)
        pthread_create(&producers[i], NULL, production , &i);

    for(int i=0;i<no_of_con;i++)
        pthread_create(&consumers[i], NULL, consumption, &i);

    for(int i=0;i<no_of_prod;i++)
        pthread_join(producers[i], NULL);

    for(int i=0;i<no_of_con;i++)
        pthread_join(consumers[i], NULL);

}
