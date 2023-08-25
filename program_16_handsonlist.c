# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
int main()
{
  struct flock fp;
  int fd;
  char c;
  printf("ENTER YOUR LOCKING CHOICE :R/W\n");
  scanf("%c",&c);
  if(c=='W')
  {
    //SETTING FLOCK FP VARIABLES
    fp.l_start = 0;
    fp.l_len = 0;
    fp.l_whence = SEEK_SET;
    fp.l_pid = getpid();
    fp.l_type = F_WRLCK;
    if((fd = open("test.txt",O_RDWR)) == -1)
    {
      perror("ERROR : ");
    }
    printf("TRYING TO ACQUIRE WRITE LOCK :\n");
    sleep(3);
    if((fcntl(fd,F_SETLKW,&fp)) == -1)
    {
      printf("ERROR ACQUIRING WRITE LOCK :\n");
    }
    else
    {
      printf("LOCK ACQUIRED\n");
    }
    printf("WORKING.....\n");
    sleep(3);
    printf("PRESS W TO RELEASE LOCK :\n");
    getchar();
    getchar();
    if((fcntl(fd,F_UNLCK,&fp)) == -1)
    {
      printf("LOCK COULD NOT BE RELEASED\n");
    }
    else
    {
      printf("SUCCESSFULLY RELEASED LOCK\n");
    }
  }
  else
  {
    if((fd = open("test.txt",O_RDWR)) == -1)
    {
      perror("ERROR : ");
    }
    printf("TRYING TO ACQUIRE READ LOCK :\n");
    sleep(3);
    if((fcntl(fd,F_SETLKW,&fp)) == -1)
    {
      printf("ERROR ACQUIRING READ LOCK :\n");
    }
    else
    {
      printf("LOCK ACQUIRED\n");
    }
    printf("WORKING.....\n");
    sleep(3);
    printf("PRESS R TO RELEASE LOCK :\n");
    getchar();
    getchar();
    if((fcntl(fd,F_UNLCK,&fp)) == -1)
    {
      printf("LOCK COULD NOT BE RELEASED\n");
    }
    else
    {
      printf("SUCCESSFULLY RELEASED LOCK\n");
    }
  }
}
