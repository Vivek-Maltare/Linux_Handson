# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
int main()
{
  fprintf(stdout,"this is the statement executed before executing any function call of execl family\n");
  fprintf(stdout,"enter your choice: ");
  fflush(stdout);
  int exec1;
  char s1[100];
  // DUPLICATING OUR STANDARD OUTPUT FD
  int s = dup(STDOUT_FILENO);
  int file_descriptor = open("exec.txt",O_RDWR|O_CREAT,0644);
  if(file_descriptor == -1)
  {
    perror("ERROR :");
  }
   // DUPLICATING OUR STD FD TO FILE_DESCRIPTOR SO THAT OUTPUT WILL BE REDIRECTED TO FILE  
  if(dup2(file_descriptor,STDOUT_FILENO) == -1)
  {
    perror("ERROR :");
  }
   close(file_descriptor);
   scanf("%s",s1);
  if(strcmp(s1,"execl")==0)
  {
   exec1 = execl("/bin/ls","ls","-RL",NULL);
   if(exec1 == -1)
   {
    perror("ERROR:");
   }
  }
  if(strcmp(s1,"execlp")==0)
  {
   exec1 = execlp("ls","ls","-RL",NULL);
   if(exec1 == -1)
   {
    perror("ERROR:");
   }
  }
  if(strcmp(s1,"execle")==0)
  {
    char* e[] = {"PATH = /bin/ls","USER = vivek-maltare",NULL};
    exec1 = execle("/bin/ls","ls","-RL",NULL,e);
    if(exec1 == -1)
    {
    perror("ERROR:");
    }
  }
  if(strcmp(s1,"execv")==0)
  {
    char* args[] = {"ls","-RL",NULL};
    exec1 = execv("/bin/ls",args);
    if(exec1 == -1)
    {
     perror("ERROR:");
    }
  }
  if(strcmp(s1,"execvp")==0)
  {
    char* args[] = {"ls","-RL",NULL};
    exec1 = execvp("ls",args);
    if(exec1 == -1)
    {
     perror("ERROR:");
    }
  }
 printf("this is the line that won't be executed");
}

