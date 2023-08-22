#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
// *****HEADER FILE WHERE FSTAT() FUNCTION IS PRESENT. THE FUNCTION CONSIST OF TWO PARAMETERS 1. THE FILE DESCRIPTOR AND 2. THE POINTER TO THE STRUCTURE WHERE WE WANT TO STORE INFORMATION ABOUT THE FILE. ***** 
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
int main()
{
// FILE NAME WHOSE INFO WE NEED
char a[]="test.txt";
//DECLARING A STRUCTURE OF TYPE STAT THAT WILL STORE FILE INFO
struct stat information;
int fd;
fd=open(a,O_RDWR|O_CREAT);
if(fd == -1)
{
 perror("open() error");
}
else
{
 // THE FSTAT FUNCTION WILL COLLECT THE INFORMATION OF THE FILE SPECIFIED BY FD AND STORE IT IN THE INFORMATION VARIABLE. ON SUCCESS RETURNS 0 ELSE -1;
 if(fstat(fd,&information)!=0)
 {
  perror("fstat() error");
 }
 else
 {
  puts("fstat() values : ");
  printf("inode value : %d\n",(int)information.st_ino);
  printf("Number of hard links : %d\n",(int)information.st_nlink);
  printf("UID : %d\n",(int)information.st_uid);
  printf("GID : %d\n", (int)information.st_gid);
  printf("File size : %d\n", (int)information.st_size);
  printf("Blocks size : %ld\n", (long)information.st_blksize);
  printf("Number of blocks : %d\n", (int)information.st_blocks);
  printf("Time of last access : %s\n",ctime(&information.st_atime));
  printf("Time of last modification : %s\n",ctime(&information.st_mtime));
  printf("Time of last change : %s\n",ctime(&information.st_ctime));  
 }
 close(fd);
}
return 0;
}
