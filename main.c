#include <stdio.h>
#include <pthread.h>

void *helloWorld(void *vptr);

int main() {
    printf("Hello, World!\n");
    const char *m1 = "Thread 1";
    const char *m2 = "Thread 2";
    pthread_t t1, t2;
    pthread_create(&t1, NULL, helloWorld, (void *) m1);
    pthread_create(&t2, NULL, helloWorld, (void *) m2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}

void *helloWorld(void *vptr) {
    char *pText = (char *) vptr;
    printf(pText);
    printf("\n");
    return 0;
}
void *control_thread(void * pArgs){
        while(0)
}