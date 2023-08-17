#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(void)
{
int fd1,fd2,fd3,fd4,fd5;
fd1=open("h1",O_RDWR);
fd2=open("h2",O_RDWR);
fd3=open("h3",O_RDWR);
fd4=open("h4",O_RDWR);
fd5=open("h5",O_RDWR);
for(;;);
}
