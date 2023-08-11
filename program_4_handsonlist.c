#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
int main()
{
//opening an existing file
int fd=open("temp.txt",O_RDWR);
//if  it doesn't exist fd will hold  value  -1 after execution of above line
if(fd==-1)
{
 fd=creat("temp.txt",O_RDWR);
 printf("file created successfully\n");
}
//creating new  file if doesn't exist
else
{
 printf("file opened successfully\n");
}
int pd=open("file3.txt",O_EXCL|O_CREAT);
//if file  already exist o_excl and o_creat results in the pd value to be -1 
if(pd==-1)
{
 printf("error_no.=%d\n",errno);
 printf("file already exists"); 
}
else
{
 printf("file created successfully");
}
}

