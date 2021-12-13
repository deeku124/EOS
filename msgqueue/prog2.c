#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

struct mq_attr msgq_atr;
int msg_prio;

int main()
{
    unsigned char buff[64];
    mqd_t msgq_desc = 0;
    ssize_t receive = 0;

    msgq_atr.mq_flags = 0;
    msgq_atr.mq_maxmsg = 4;
    msgq_atr.mq_msgsize = 64;
    msgq_atr.mq_curmsgs = 0;
    
    msgq_desc = mq_open("/desdmq", O_CREAT | O_RDONLY, S_IRUSR | S_IWUSR, &msgq_atr);
    if(msgq_desc == -1)
    {
        perror("Error receiving:");
        return EXIT_FAILURE;
    }
    receive = mq_receive(msgq_desc, buff, 64, &msg_prio);
    printf("%s\n", buff);
    mq_close(msgq_desc);
    return EXIT_SUCCESS;
}
