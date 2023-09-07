# include <stdio.h>
# include <unistd.h>
int main()
{
  int pid = fork();
  if(pid>0)
  {
    printf("parent process...\n");
    printf("PID %d\n",getpid());
  } 
  if(pid == 0)
  {
    printf("child process...\n");
    printf("PID %d\n",getpid());
  }

}


