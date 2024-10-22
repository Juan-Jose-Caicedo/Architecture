//Exercise 5: Create and terminate processes = Write a program that uses the system call fork() to create a child process
//and then uses getpid() and getppid() to display the process IDs of the child and parent processes.
//The child process should terminate using exit()


#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Error al crear el proceso -Hijo-");
        return 1;
    } else if (pid == 0) {
        // Proceso hijo
        printf("Proceso -Hijo-, PID es: %d\n", getpid());
        printf("y -Padre- tiene el PID: %d\n", getppid());
        exit(0);
    } else {
        // Proceso padre
        printf("El proceso -Padre-, mi PID es: %d\n", getpid());
        printf("El PID de -Hijo- es: %d\n", pid);
        wait(NULL); // Esperar a que el hijo termine
    }

    return 0;
}
