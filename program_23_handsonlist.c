# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
int main()
{
  int pid = fork();
  if(pid>0)
  {
   printf("inside parent process :\n");
   sleep(10);
   printf("parent exits now\n");
  }
  if(pid==0)
  {
   printf("inside child process\n");
   printf("i am zombie now\n");
   exit(0);
  }
return 0;
}
