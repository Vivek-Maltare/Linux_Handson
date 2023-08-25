# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
int main()
{
   struct 
   {
     int ticket_no;
   } db;
   int fd;
   db.ticket_no=1;
   fd = open("record_17.txt",O_RDWR);
   write(fd,&db,sizeof(db));
   close(fd);
}
