#include <pthread.h>
#include <stdio.h>

static int cantidad = 10;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *hilo1_routine(void *unused) {
  for (int i = 1; i < 100; i++) {
    pthread_mutex_lock(&mutex);
    cantidad++;
    pthread_mutex_unlock(&mutex);
  }
}

void *hilo2_routine(void *unused) {
  for (int i = 1; i < 100; i++) {
    pthread_mutex_lock(&mutex);
    cantidad--;
    pthread_mutex_unlock(&mutex);
  }
}

void errorExit(char *strerr) {
  perror(strerr);
  error(1);
}

int main() {

  pthread_t hilo1, hilo2;
	
  if (pthread_create(&hilo1, NULL, hilo1_routine, NULL) != 0)
    errorExit("hilo1 no se pudo crear");

  if (pthread_create(&hilo2, NULL, hilo2_routine, NULL) != 0)
    errorExit("hilo2 no se pudo crear");
	
  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);

  printf("Contar cantidad %d \n", cantidad);

  return 0;
}
