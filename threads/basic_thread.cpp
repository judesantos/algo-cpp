#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

typedef struct _thread_data_t {
    int tid;
    double stuff;
} thread_data_t;

void *thr_func(void* args) {
    thread_data_t *d = (thread_data_t *)args;
    printf("hello from thread: %d\n", d->tid);

    printf("thread  EXIT: %d\n", d->tid);
    pthread_exit(0);
}

int main() 
{
    pthread_t tr[NUM_THREADS];
    thread_data_t thr_data[NUM_THREADS];
    int rc;

    for (int i = 0; i < NUM_THREADS; i++)
    {
        printf("Create thread: %d\n", i);
        thr_data[i].tid = i;
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

    return EXIT_SUCCESS;
}
