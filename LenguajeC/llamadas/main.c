#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main() {
    char *buffer;

    printf("HOLA HOLA\n");

    //buffer = malloc(256);
    buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    //ssize_t bytes_read = read(0,buffer,sizeof(buffer)); 
    ssize_t bytes_read = read(0,buffer,BUFFER_SIZE); 


    if (bytes_read < 0) {
        perror("Error en read");
        free(buffer);
        return 1;
    }

    printf("Los primeros 4 caracteres leídos son: %s\n", buffer);

    free(buffer);
    return 0;
}
