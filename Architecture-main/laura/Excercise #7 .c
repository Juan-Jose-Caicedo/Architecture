// Exercise 7: Signal handling= Implement a program that registers a signal using signal() and handles SIGINT (Ctrl+C).
// When the user presses Ctrl+C, the program should print a message and continue running.

#include <stdio.h>
#include <signal.h>

void manejadorSIGINT(int sig) {
    printf("Se recibió la señal SIGINT (Ctrl+C)\n");
}

int main() {
    signal(SIGINT, manejadorSIGINT);

    while (1) {
        printf("Ejecutando...\n");
        sleep(1);
    }

    return 0;
}
