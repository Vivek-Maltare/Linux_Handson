#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
//using write function call to write directly to our standard output (screen). on sucess the function will return the number of bytes written on to screen else return -1.
int write_count=0;
write_count=write(1,"HI I AM VIVEK MALTARE\n",22);
if(write_count==-1)
{
  printf("FAILURE");
}
else
{
  printf("TOTAL NUMBER OF BYTES WRITTEN : %d\n",write_count);
}
//reading data from the standard input whose file descriptor is 0 and writing it to standard output (fd 1). read on success will return the number of bytes read else -1.
int read_count=0;
char buff[100];
read_count=read(0,buff,21);
if(read_count == -1)
{
  printf("FAILURE");
}
else
{
  write(1,buff,21);
  printf("TOTAL NUMBER OF BYTES READ ON SCREEN  : %d\n",read_count);
}

}
