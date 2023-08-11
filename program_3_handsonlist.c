#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
//creating a new file  using  creat  system call
int fd=creat("file_using_terminal.txt",O_RDWR);
//if file is not created succcessfully fd will hold value -1 
if(fd==-1)
  printf("error no %d\n",errno);
else
  printf("file descriptor value %d\n",fd);
}
