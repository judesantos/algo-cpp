#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

double shared_x;
pthread_mutex_t lock_x;

typedef struct _thread_data_t {
    int tid;
    double stuff;
} thread_data_t;

void *thr_func(void* args) {
    thread_data_t *d = (thread_data_t *)args;
    
    pthread_mutex_trylock(&lock_x);
        shared_x += d->stuff;
        printf("hello from thread: %d\n", d->tid);
        printf("%dx = %f\n", d->tid, shared_x);
    pthread_mutex_unlock(&lock_x);

   
    pthread_exit(0);
}

int main() 
{
    pthread_t tr[NUM_THREADS];
    thread_data_t thr_data[NUM_THREADS];

    int rc;
    shared_x = 0;

    pthread_mutex_init(&lock_x, 0);

    for (int i = 0; i < NUM_THREADS; i++)
    {
        printf("Create thread: %d\n", i);
        thr_data[i].tid = i;
        thr_data[i].stuff = (i + 1) * NUM_THREADS;

        if ((rc = pthread_create(&tr[i], 0, thr_func, &thr_data[i])))
        {
            fprintf(stderr, "error, thread creation failed, rc: %d\n", rc);
            return EXIT_FAILURE;
        }

        printf("thread CREATED: %d\n", thr_data[i].tid);
    }

    for (int x = 0; x < NUM_THREADS; x++)
    {
        pthread_join(tr[x], 0);
    }

    pthread_mutex_destroy(&lock_x);
    return EXIT_SUCCESS;
}
