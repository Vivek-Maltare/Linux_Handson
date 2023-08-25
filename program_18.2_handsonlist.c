# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
int main()
{
  int input;
  printf("ENTER THE TRAIN NUMBER : ");
  scanf("%d",&input);
  int fd = open("record_18.txt",O_RDWR);
  struct
  {
    int train_number;
    int ticket_count;
  } db;
  struct flock f;
  f.l_type = F_RDLCK;
  f.l_start = (input-1)*sizeof(db);
  f.l_len = sizeof(db); 
  f.l_whence = SEEK_SET;
  f.l_pid = getpid(); 
  printf("BEFORE ENTERING INTO CRITICAL SECTION :\n");
  sleep(1);
  fcntl(fd,F_SETLKW,&f);
  lseek(fd,(input-1)*sizeof(db),SEEK_SET);
  read(fd,&db,sizeof(db));
  printf("CURRENT TICKET COUNT :%d\n",db.ticket_count);
  f.l_type = F_WRLCK;
  db.ticket_count++;
  lseek(fd,-1*sizeof(db),SEEK_CUR);
  write(fd,&db,sizeof(db));
  sleep(1);
  printf("UPDATED TICEKT COUNT :%d\n",db.ticket_count);
  sleep(1);
  printf("TO BOOK PRESS ENTER\n");
  getchar();
  getchar();
  printf("BOOKED\n");
  f.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&f);
  close(fd);
}
