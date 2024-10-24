//Exercise 1: Create and open files= Write a C program that uses the system call open() to create a 
//new file, write text into it, and then close it using close() 

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char *texto = "Hola mundo";

    // Creacion un archivo nuevo
    fd = open("programas.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("Open");
        return 1;
    }

    // Escribir en el archivo
    if (write(fd, texto, sizeof(texto)) == -1) {
        perror("Write");
    }

    // Cerrar el archivo
    close(fd);

    return 0;
}