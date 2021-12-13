#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

struct mq_attr msgq_atr;

int main()
{
    mqd_t msgq_desc;
    msgq_atr.mq_flags = 0;
    msgq_atr.mq_maxmsg = 4;
    msgq_atr.mq_msgsize = 64;
    msgq_atr.mq_curmsgs = 0;
    
    msgq_desc = mq_open("/desdmq", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR, &msgq_atr);
    
    if(msgq_desc == -1)
    {
        perror("Error opening MQ: ");
        return EXIT_FAILURE;
    }

    mq_send(msgq_desc, "hello\n", 6, 1);
    mq_close(msgq_desc);
    return 0;
}
