#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd;
    char *buff[2];

    if ((fd = open("process.txt", O_RDWR | O_CREAT, 0644)) == -1)
    {
        perror("ERROR:");
        return 1; 
    }

    int pid = fork();

    if (pid > 0)
    {
        buff[0] = "writing from parent process\t";
        write(fd, buff[0], strlen(buff[0]));
    }

    if (pid == 0)
    {
        buff[1] = "writing from child process";
        write(fd, buff[1], strlen(buff[1]));
    }

    close(fd); // Close the file
    return 0;
}
