#include<stdio.h>
#include<pthread.h>

pthread_rwlock_t rwlock;

int counter = 0;

void *reader1(void *arg)
{
    pthread_rwlock_rdlock(&rwlock);
    printf("Thread one:%d\n",counter);
    pthread_rwlock_unlock(&rwlock);
    
    return NULL;
}

void *reader2(void *arg)
{
    pthread_rwlock_rdlock(&rwlock);
    printf("Thread one:%d\n",counter);
    pthread_rwlock_unlock(&rwlock);
    
    return NULL;
}

void *writer(void *arg)
{
    pthread_rwlock_wrlock(&rwlock);
    counter++;
    printf("Thread one:%d\n",counter);
    pthread_rwlock_unlock(&rwlock);
    
    return NULL;
}


int main()
{
    pthread_t t1,t2,t3;
    
    pthread_rwlock_init(&rwlock, NULL);
    
    pthread_create(&t1,NULL,reader1,NULL);
    pthread_create(&t2,NULL,reader2,NULL);
    pthread_create(&t3,NULL,writer,NULL);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    
    pthread_rwlock_destroy(&rwlock);
}