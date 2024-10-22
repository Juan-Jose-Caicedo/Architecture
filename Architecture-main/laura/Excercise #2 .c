// Exercise 2: Read from a file= Implement a C program that opens an existing text file using open(), 
//reads its content using read(), and displays it on the console.



#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // Abrir el archivo en modo lectura
    fd = open("programas.txt", O_RDONLY);
    if (fd == -1) {
        perror("Open");
        return 1;
    }

    // Leer el contenido del archivo
    if (read(fd, buffer, sizeof(buffer)) == -1) {
        perror("Read");
    }

    // Imprimir el contenido en la consola
    printf("%s\n", buffer);

    // Cerrar el archivo
    close(fd);

    return 0;
}
