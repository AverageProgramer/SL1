#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

#define left (current-1)%5
#define right (current+1)%5
#define eat 3
#define think 2
#define hungry 1

sem_t s[5];
int phil[5]={1,2,3,4,5};
int state[5];

pthread_mutex_t mutex;

void test(int current)
{
    if(state[current]==hungry  &&  state[left]!=eat  &&  state[right]!=eat)
    {
        state[current]=eat;
        printf("philosopher %d is eating\n",current );

        sleep(2);
        sem_post(&s[current]);
    }
}

void takefork(int current)
{
    pthread_mutex_lock(&mutex);

            state[current]=hungry;
            printf("philosopher %d is hungry\n",current );

            test(current);

    pthread_mutex_unlock(&mutex);

    sem_wait(&s[current]);
}

void putfork(int current)
{
    pthread_mutex_lock(&mutex);

            state[current] = think;
            printf("philosopher %d is thinking\n",current );

            test(left);
            test(right);

    pthread_mutex_unlock(&mutex);
}

void * philosopher(void * arg)
{
    int current = *(int *)arg;

    while(1)
    {
        takefork(current);
        sleep(2);
        putfork(current);
    }
}

int main()
{
    pthread_mutex_init(&mutex,0);

    for(int i=0;i<5;i++)
        sem_init(&s[i],0,0);

    pthread_t ID[5];

    for(int i=0;i<5;i++)
        pthread_create(&ID[i], NULL, philosopher, &phil[i]);

    for(int i=0;i<5;i++)
        pthread_join(ID[i],NULL);
}
