# include <stdio.h>
# include <unistd.h>
# include <sched.h>
# include <sys/resource.h>
int main()
{
        pid_t pid = getpid();
        struct sched_param p;
        int nice = getpriority(PRIO_PROCESS,pid);
        printf("CHANGING THE SCHEDULING POLICY OF PROCESS WITH PROCESS ID : %d AND NICENESS VALUE %d\n",pid,nice);
        int policy = sched_getscheduler(pid);
        if(policy == 0)
        {
                printf("THE EXISTING POLICY IS COMPLETELY FAIR SCHEDULAR\n");
        }
        if(policy == 1)
        {
                printf("THE EXISTING POLICY IS FIRST IN FIRST OUT\n");
        }
        if(policy == 2)
        {
                printf("THE EXISTING POLICY IS ROUND ROBBIN\n");
        }
        if(policy == 3)
        {
                printf("THE EXISTING POLICY IS BATCH SCHEDULING\n");
        } 
        if(policy == 5)
        {
                printf("THE EXISTING POLICY IS IDLE SCHEDULING\n");
        }
    p.sched_priority = 56;
        if((sched_setscheduler(pid,SCHED_FIFO,&p))==-1)
        {
                perror("ERROR:");
        } 
        else
        {
                policy = sched_getscheduler(pid);
                if(policy == 1)
                {
                        printf("THE NEW POLICY IS FIRST IN FIRST OUT AND THE NEW PRIORITY IS %d\n",p.sched_priority);
                }
        }
}
   
