#include <stdio.h> 
#include <time.h>
#include <pthread.h>

int main() 
{
    struct timespec ts;
    pthread_mutex_t TempMutex;
    pthread_mutex_init(&TempMutex, NULL);

    clock_gettime(CLOCK_REALTIME, &ts); 
    printf("CLOCK_BOOTTIME: %ds, %dms\n", ts.tv_sec, ts.tv_nsec/(1000*1000));

    int i = 0, j = 0;
    for(; i < 1000*1000; i++)
    {
        pthread_mutex_lock(&TempMutex);
        //j++;
        pthread_mutex_unlock(&TempMutex);
    }

    clock_gettime(CLOCK_REALTIME, &ts); 
    printf("CLOCK_BOOTTIME: %ds, %dms\n", ts.tv_sec, ts.tv_nsec/(1000*1000));

    pthread_mutex_destroy(&TempMutex);

    return 0;
}
