//Exercise 3: Handle file permissions= Write a program that creates a file with specific permissions (read, write) 
//using the system call open() and the O_CREAT flag. Ensure that the file has read and write permissions only for the owner.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("programas.txt", O_CREAT | O_WRONLY, 0600);
    // 0600: Lectura y escritura solo para el propietario

    if (fd == -1) {
        perror("Error, no se pudo crear el archivo");
        return 1;
    }

    close(fd);
    return 0;
}

