#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
int main()
{
int fd;
char buff[10]="VIVEKIIITB";
int offset=10;
fd=open("test.txt",O_RDWR);
if(fd==-1)
{
 perror("ERROR :");
}
else
{
 write(fd,buff,strlen(buff));
}
//SHIFTING THE POINTER 10 POSITIONS TO RIGHT FROM THE CURRENT POSITION
int ret=lseek(fd,offset,SEEK_CUR);
//RETURNING THE POSITION OF POINTER
printf("Return value of seek :%d\n",ret);
//WRITING AFTER 10 POSITIONS
write(fd,buff,strlen(buff));
}
// CHECK THE SPACES BY WRITING od -c test.txt.
