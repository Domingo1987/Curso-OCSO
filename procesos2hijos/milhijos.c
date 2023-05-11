#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int i, status, pid;
    srand(time(NULL)); // inicializar la semilla para generar números aleatorios
    
    for (i = 0; i < 1000; i++) {
        pid = fork(); // crear un nuevo proceso hijo
        if (pid == 0) { // si es el proceso hijo
            int t = rand() % 5 + 1; // generar un tiempo aleatorio entre 1 y 5 segundos
            printf("Soy el proceso hijo con PID %d. Voy a esperar %d segundos.\n", getpid(), t);
            sleep(t); // esperar el tiempo aleatorio
            printf("Soy el proceso hijo con PID %d. Terminé.\n", getpid());
            exit(0); // terminar el proceso hijo
        }
    }
    
    // Esperar a que todos los procesos hijos terminen
    for (i = 0; i < 1000; i++) {
        wait(&status);
    }
    
    printf("Todos los procesos hijos terminaron.\n");
    return 0;
}
