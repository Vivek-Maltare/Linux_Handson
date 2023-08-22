#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
   int fd,val,f_flag;
   fd = open("test", O_CREAT|O_RDWR|O_APPEND, S_IRUSR | S_IWUSR);
   if(fd<0)
   {
     perror("ERROR :");
   }
  if((val=fcntl(fd,F_GETFL))<0)
   {
     perror("ERROR :");
   }
   f_flag = val & O_ACCMODE;
   if(f_flag==O_RDONLY)
     printf("the file is read only :\n");
   if(f_flag==O_WRONLY)
     printf("the file is write only :\n");
   if(f_flag==O_RDWR)
     printf("the file is read/write :\n");
   else 
   {
     printf("no idea :\n");
   }
}
