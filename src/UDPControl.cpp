#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include<unistd.h>

int counter = 0;
pthread_mutex_t mutex;

void *routine( void *ptr ) {

	printf("routine01 \n");
	sleep(1);
    //pthread_mutex_lock(&mutex);
    for (int i = 0; i < 100000000; i++){
    	counter++;
    }
    printf("Counter: %d \n", counter );
    //pthread_mutex_unlock(&mutex);

    return NULL;
}


int main(int argc, char* argv[]) {

    pthread_t p1;

    pthread_mutex_init(&mutex, NULL);

    pthread_mutex_lock(&mutex);

    if(pthread_create(&p1, NULL, routine, NULL) != 0) {
    	printf("error01 %s \n", strerror(errno));
        return 1;
    }

    pthread_mutex_unlock(&mutex);

    printf("ok \n");
//comment here
    int a = pthread_join(p1, NULL);
    if (a !=0 ){
    	printf("error02:  %s \n", strerror(errno));
        return 2;
    }
//until here

    printf("ok \n");

    sleep(1);

   // pthread_mutex_destroy(&mutex);

   return 0;

}
