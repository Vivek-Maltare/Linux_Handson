# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
int main()
{
  int pid = fork();
  if(pid>0)
  {
   printf("I AM PARENT PROCESS :%d\n",getpid());
   printf("NOW I HAVE COMPLETED MY EXECUTION\n");
  }
  if(pid == 0)
  {
   sleep(10);
   printf("I AM AN ORPHAN CHILD PROCESS %d\n",getpid());
  }
}

