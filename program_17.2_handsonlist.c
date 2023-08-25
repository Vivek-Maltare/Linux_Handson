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
   struct flock f;
   int fd;
   f.l_type = F_WRLCK;
   f.l_len = 0;
   f.l_start = 0;
   f.l_whence = SEEK_SET;
   f.l_pid = getpid();
   if((fd = open("record_17.txt",O_RDWR))==-1)
   {
     perror("ERROR : ");
   }
   else
   {
     printf("BEFORE ENTERING INTO CRITICAL SECTION :\n");
     sleep(2);
     if((fcntl(fd,F_SETLK,&f))==-1)
     {
       perror("ERROR : ");
     }
     else
     {
       read(fd,&db,sizeof(db));
       printf("ENTERED INTO CRITICAL SECTION:\n");
       sleep(1);
       printf("CURRENT TICKET NUMBER %d\n",db.ticket_no);
       db.ticket_no++;
       sleep(1);
       printf("UPDATED TICKET NUMBER %d\n",db.ticket_no);
       lseek(fd,0L,SEEK_SET);
       printf("ENTER TO UNLOCK:");
       write(fd,&db,sizeof(db));
       getchar();
       printf("SUCCESSFULLY UNOCKED :\n");
     }
   }
}
