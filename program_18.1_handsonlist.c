# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
int main()
{
  struct
  {
    int train_num;
    int ticket_no;
  } db[3];
  int fd;
  for(int i=0;i<3;i++)
  {
   db[i].train_num = i+1;
   db[i].ticket_no = i+1;
  }
  fd = open("record_18.txt",O_RDWR);
  write(fd,&db,sizeof(db));
  close(fd);
}
