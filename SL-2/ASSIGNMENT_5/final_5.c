#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

int buffer[10]={-1};
int readers_reading=0;

pthread_mutex_t reader_guard, writer_guard;

int reader_count, writer_count;

void * writing (void * arg)
{
    int current_writer = *(int *)arg;

    while(1)
    {
        sleep(rand()%5);

        pthread_mutex_lock(&writer_guard);

        int val = rand()%100;
        int index = rand()%10;

        buffer[index] = val;

        printf("Writer %d wrote value %d at position %d\n",current_writer,val,index );

        pthread_mutex_unlock(&writer_guard);
    }
}

void * reading (void * arg)
{
    int current_reader = *(int *)arg;

    while(1)
    {
        sleep(rand()%5);

        pthread_mutex_lock(&reader_guard);

                readers_reading++;

                if(readers_reading == 1)
                    pthread_mutex_lock(&writer_guard);

        pthread_mutex_unlock(&reader_guard);

        int index = rand()%10;
        printf("Reader %d read value %d from position %d\n", current_reader, buffer[index],index);

        pthread_mutex_lock(&reader_guard);

                readers_reading--;

                if(readers_reading == 0)
                    pthread_mutex_unlock(&writer_guard);

        pthread_mutex_unlock(&reader_guard);
    }
}

int main()
{
    printf("no of readers , no of writers\n");
    scanf("%d %d", &reader_count, &writer_count);

    pthread_t arr[reader_count + writer_count];
    int count=0;

    pthread_mutex_init(&reader_guard,0);
    pthread_mutex_init(&writer_guard,0);

    for(int i=0;i<writer_count;i++)
        pthread_create(&arr[i], NULL, writing, &i);

    for(int i=writer_count;i<reader_count+writer_count;i++)
        pthread_create(&arr[i], NULL, reading, &i);

    for(int i=0;i<reader_count+writer_count;i++)
        pthread_join(arr[i],NULL);

}
