#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
  if(argc!=2)
  {
     perror("ERROR : ");
     return 1;
  }
 
  int fd = open(argv[1],O_RDONLY);
  if(fd<0)
  {
    perror("ERROR : ");
    return 1;
  } 
 
  char buffer[1024];
  int bytes_read;
  while((bytes_read = read(fd, buffer, sizeof(buffer)))>0)
  {
    write(STDOUT_FILENO, buffer, bytes_read);
  }

  if(bytes_read == -1)
  {
    perror("error reading from file");
    close(fd);
    return 1;
  }

  close(fd);
 
  return 0;
}
