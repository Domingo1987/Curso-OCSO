#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
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
        system("ps");
        //sleep(10); // Espera 10 segundos
    }
 
    return 0;
}