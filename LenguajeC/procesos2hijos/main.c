#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i = 0;
    pid_t pid1, pid2;
    int status1=0, status2=0;
    
    // Creamos el primer proceso hijo
    pid1 = fork();
    if (pid1 == 0) {
        // Código del primer proceso hijo
        printf("Soy el primer proceso hijo (%d) mi status es %d\n", getpid(), status1);
        exit(0);
    } else if (pid1 < 0) {
        perror("Error al crear el primer proceso hijo");
        sleep(3);
        exit(1);
    }
    
    // Creamos el segundo proceso hijo
    pid2 = fork();
    if (pid2 == 0) {
        // Código del segundo proceso hijo
        printf("Soy el segundo proceso hijo (%d) mi status es %d\n", getpid(), status2);
        for(;i<100;i++) {
            system("date");
        }
        exit(0);
    } else if (pid2 < 0) {
        perror("Error al crear el segundo proceso hijo");
        exit(1);
    }
    
    // Esperamos a que ambos procesos hijos terminen
    waitpid(pid1, &status1, 0);
    printf("SOY el 1 y termine con %d\n", status1);

    waitpid(pid2, &status2, 0);
    printf("SOY el 2 y termine con %d\n", status2);

    
    // Imprimimos el mensaje de que ambos procesos han terminado
    printf("Ambos procesos hijos han terminado.\n");
    
    return 0;
}
