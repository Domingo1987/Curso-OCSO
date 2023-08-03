#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

int main() {
    srand(time(NULL));  // inicializar la semilla del generador de números aleatorios
    pid_t pid;
    int i;
    
    for (i = 0; i < 7; i++) {
        pid = fork();
        if (pid < 0) {
            printf("Error en fork()\n");
            exit(1);
        } else if (pid == 0) {
            int sleep_time = rand() % 10 + 1;  // generar un número aleatorio entre 1 y 10
            sleep(sleep_time);
            exit(0);  
        } 
    }

    // Hacer que el proceso principal duerma un tiempo suficiente para que los hijos terminen
    sleep(20);
    
    return 0;
}
