//Exercise 10: Directory management= Create a program that uses the system calls mkdir() and rmdir() to create and remove directories. 
//The program should also display the current directory using getcwd().

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    if (mkdir("mi_directorio", 0755) == -1) {
        perror("Error, no se pudo crear el directorio");
        return 1;
    }

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Directorio actual: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }

    if (rmdir("mi_directorio") == -1) {
        perror("Error, no se pudo eliminar el directorio");
        return 1;
    }

    return 0;
}