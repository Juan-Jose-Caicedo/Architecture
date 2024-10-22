//Exercise 8 : Execute an external program = Write a program that uses exec() to replace the current process with 
//another program (for example, execute the ls command inside your program).

#include <stdio.h>
#include <unistd.h>

int main() {
    execlp("ls", "ls", "-l", NULL);
    perror("Error al ejecutar ls");
    return 1;
}

