//Exercise 6: Inter-process communication (pipe)= Write a C program that creates a pipe between a parent and a child process. 
//The parent process should send a message to the child using the system call write() and the child should read it using read().

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        perror("Error al crear la tubería");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Error al crear el proceso -Hijo-");
        return 1;
    } else if (pid == 0) {
        // Proceso Hijo
        close(fd[1]); // Cerrar extremo de escritura
        char buffer[100];
        read(fd[0], buffer, 100);
        printf("Hijo: %s\n", buffer);
        close(fd[0]);
    } else {
        // Proceso Padre
        close(fd[0]); // Cerrar extremo de lectura
        write(fd[1], "Hola desde el -Padre-", 17);
        close(fd[1]);
        wait(NULL);
    }

    return 0;
}
