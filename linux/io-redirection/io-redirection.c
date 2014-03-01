#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main() {
    int pid = 0;
    
    if (pid = fork()) {
        // this is the parent process

        // wait for completion of the child process
        int status; 
        waitpid(pid, &status, 0);
    }
    else {
        // this is the child process

        // open input and output files
        int fd_in = open("in.txt", O_RDONLY);
        int fd_out = open("out.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

        if (fd_in > 0 && fd_out > 0) {
            printf("fd_in=%d, fd_out=%d\n", fd_in, fd_out);

            // redirect STDIN/STDOUT for this process
            dup2(fd_in, 0);
            dup2(fd_out, 1);
            
            // call shell command
            system("sort");
            
            close(fd_in);
            close(fd_out);
        }
        else {
            printf("Failure opening files, fd_in=%d, fd_out=%d\n", fd_in, fd_out);
            if (fd_in > 0) {
                close(fd_in);
            }
            if (fd_out > 0) {
                close(fd_out);
            }
        }
    }

    return 0;
}
