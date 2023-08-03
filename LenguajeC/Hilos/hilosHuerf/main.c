#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *child_thread(void *arg) {
    int i=0;
    while(1) {
        printf("%d-Child thread todavia estoy...\n", i);
        printf("Soy el hijo (%d, hijo de %d)\n", getpid(), getppid());
    i++;
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    if(pthread_create(&thread_id, NULL, child_thread, NULL) != 0) {
        fprintf(stderr, "Fallo al crear thread\n");
        exit(1);
    }

    printf("Main thread saliendo, sin esperar que termine child thread\n");    
    //sleep(20);
    pthread_join(thread_id, NULL);


    pthread_exit(NULL);
    //return 0;   // No se debería usar en este caso, ya que terminaría todos los hilos hijos.
}
