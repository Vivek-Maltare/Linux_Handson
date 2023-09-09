# include <stdio.h>
# include <sys/resource.h>
# include <errno.h>
# include <unistd.h>
int  main()
{
  int priority,new_value;
  int get = getpid();
  printf("%d",get);
  // CLEARING ERROR NUMBER IN ORDER TO DIFFERENTIATE BETWEEN AN ERROR VALUE OF -1 AND A PROCESS PRIORITY OF -1.
  errno = 0;
  priority = getpriority(PRIO_PROCESS,0);
  if(errno == -1)
  {
    printf("ERROR : "); 
  }
  
  printf("the existing priority of the process is %d\n",priority);
  printf("enter the priority value you want to set :");
  scanf("%d",&new_value);
  if(new_value< -20 && new_value>19)
  {
    printf("trying to set an invalid priority.\n");
    printf("ERROR :");
  }
  else
  {
  // setting priority of current running process
  nice(new_value);
  errno = 0;
  priority = getpriority(PRIO_PROCESS,0);
  if(errno == -1)
  {
    printf("ERROR :");
  }

  printf("the new priority of the process is %d\n",priority);
  
  }     
}
