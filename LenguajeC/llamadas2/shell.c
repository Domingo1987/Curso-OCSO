#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/* Esta función muestra el prompt en pantalla para el usuario. */
void type_prompt() {
    printf("> ");
}

/* Esta función lee la entrada del usuario desde la línea de comandos. */
void read_command(char *command) {
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    /* Eliminamos el salto de línea que añade fgets. */
    strtok(command, "\n");
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    int status;

    pid_t pid;

    pid = fork();
    sleep(1);

    if (pid == 0) 
    { /* hijo */
        printf("Soy el hijo (%d, hijo de %d)\n", getpid(), getppid());
    }
    else
    { /* padre */
        printf("Soy el padre (%d, hijo de %d)\n", getpid(), getppid());
        //printf("Listado de procesos:\n");
        
        type_prompt();
        read_command(command);
        if (system(command) == -1) {
            printf("Error: no se pudo ejecutar el comando.\n");
        }
        exit(0);

        //sleep(10); // Espera 10 segundos
    }

    return 0;
}
