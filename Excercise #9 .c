// Exercise 9 : Process control (wait)= Write a program that uses fork() to create a child process. 
//The parent process should wait for the child to finish using the system call wait() before continuing.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Error al crear el proceso -Hijo-");
        return 1;
    } else if (pid == 0) {
        // Proceso Hijo
        printf("Desde el proceso -Hijo-,  PID es: %d\n", getpid());
        // Aquí el Hijo puede realizar alguna tarea
        sleep(2); // Simular una tarea que tarda 2 segundos
        printf("Hijo terminando...\n");
        exit(0);
    } else {
        // Proceso padre
        printf("Desde el proceso -Padre-, PID es: %d\n", getpid());
        printf("El PID de hijo es: %d\n", pid);

        // Esperar a que el hijo termine
        int status;
        waitpid(pid, &status, 0);

        printf("El -Hijo- ha terminado\n");
    }

    return 0;
}

