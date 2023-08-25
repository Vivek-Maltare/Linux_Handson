# include <stdio.h>
# include <stdlib.h>
# include <sys/select.h>
# include <unistd.h>
# include <fcntl.h>
int main()
{
  fd_set rfds;
  struct timeval t;
  int val;
  //SET OUR FD SET TO O
  FD_ZERO(&rfds); 
  //ADDING THE STANDARD INPUT FILE DESCRIPTOR TO FD SET
  FD_SET(0,&rfds);
  //SETITNG WAITING TIME BEFORE READING AN INPUT
  t.tv_sec = 10;
  //PASSING OUR FD SET TO THE READ FD'S PARAM IN ORDER TO WAIT FOR READING 
  val = select(1,&rfds,NULL,NULL,&t);
  if(val == -1)
  {
    perror("ERROR :");
  }
  //IF DATA AVAIALBLE WITHIN 10 SEC VAL WILL HAVE A NON ZERO VALUE
  else if(val)
  {
    printf("DATA IS AVAILABLE NOW :");
  }
  else
  {
    printf("DATA NOT AVAILABLE WITHIN 10 SECONDS :");
  }
  exit(EXIT_SUCCESS);
}
