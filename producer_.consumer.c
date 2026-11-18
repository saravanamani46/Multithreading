#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

sem_t empty;
sem_t full;

int in;
int out;

int a[5];

void *producer(void *arg)
{
    for(int i=0;i<10;i++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
    
        scanf("%d",&a[in]);
        
        in = (in + 1)%5;
    
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        
    }
    
    
    return NULL;
}

void *consumer(void *arg)
{
    for(int i=0;i<10;i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
    
    
        printf("%d\n",a[out]);
        
        out = (out + 1)%5;
        
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    
    
    
    return NULL;
}

int main()
{
    pthread_t t1,t2;
    
    sem_init(&empty,0,5);
    sem_init(&full,0,0);
    
    pthread_create(&t1,NULL,producer,NULL);
    pthread_create(&t2,NULL,consumer,NULL);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    sem_destroy(&empty);
    sem_destroy(&full);
}