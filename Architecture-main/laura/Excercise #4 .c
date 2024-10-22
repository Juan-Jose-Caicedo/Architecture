//Exercise 4: Modify file permissions= Implement a C program that changes the permissions of a file using the system call
// chmod() to make it readable only by the owner.

#include <stdio.h>
#include <sys/stat.h>

int main() {
    if (chmod("programas.txt", 0400) == -1) {
        perror("Error al cambiar los permisos");
        return 1;
    }
    return 0;
}
