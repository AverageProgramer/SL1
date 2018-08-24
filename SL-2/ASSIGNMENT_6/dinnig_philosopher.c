#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<malloc.h>
#include<stdlib.h>

pthread_mutex_t mutex;
sem_t s[100];
char state[100];

void test(int curr)
{
    if((state[curr]=='H') && (state[(curr-1)%5]!='E')  &&  (state[(curr+1)%5]!='E') )
    {           // if curr is hungry and his surroundings are NOT eating
        state[curr]='E';   // make it eat(busy)
        sem_post(&s[curr]);
    }
}

void take_fork(int curr_philosopher)
{

    pthread_mutex_lock(&mutex);

    state[curr_philosopher] = 'H' ;      // H = hungry
    test(curr_philosopher);                // check if his surrounding philosophers have taken forks

    pthread_mutex_unlock(&mutex);
    sem_wait(&s[curr_philosopher]);

}

void put_fork(int curr_philosopher)
{
    pthread_mutex_lock(&mutex);

    state[curr_philosopher]='T';        // t = thinking (not busy)
    printf("\nphilosopher %d has finished eating and now he is thinking\n",curr_philosopher);

    test((curr_philosopher-1)%5);   // check for left of curr_philosopher (curr_philosopher has finished eating so just check for right of (curr_philosopher-1))
    test((curr_philosopher+1)%5); // similar here

    pthread_mutex_unlock(&mutex);
}

void * work( void * arg)
{
    while(true)
    {
        sleep(1);
        int curr_philosopher = (long)arg;

        printf("Philosopher is thinking !!\n");     // thinking
        take_fork(curr_philosopher);                 // pick fork

        printf("Philosopher is eating\n");      // eating
        put_fork(curr_philosopher);

    }
}


void init()
{
    int n;
    printf("Enter number of philosophers : ");
    scanf("%d",&n);
    printf("\n");

    pthread_t *philosophers;

    if(pthread_mutex_init(&mutex,NULL) != 0)
    {
        printf("Initialization failed !!!\n");
        return;
    }

    for(int i=0;i<n;i++)
        sem_init(&s[i],0,0);        // name, 0 always, value to be initialized

    philosophers = (pthread_t*)malloc(sizeof(pthread_t)*n); // initialize thread

    for(int i=0;i<n;i++)
        //pthread_create(&philosophers[i], NULL, work, (void *)i); // created all philosophers
        pthread_create(&philosophers[i],NULL,work,(void *)i);

    for(int i=0;i<n;i++)
        pthread_join(philosophers[i], NULL);    // join

}

int main()
{

    init();
    pthread_mutex_destroy(&mutex);

}
