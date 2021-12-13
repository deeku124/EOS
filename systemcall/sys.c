#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int fd;    
    ssize_t ret_write;
    int ret_close;
    
    fd = open("desd2.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
         perror("Error! unable to open File: \n");
         exit(EXIT_FAILURE);
    }

    ret_write = write(fd, "deekshitha_raj\n", 18);
    if(ret_write == -1)
    {
        perror("Error! unable to write data into File: \n");
        exit(EXIT_FAILURE);
    }

    ret_close = close(fd);
    if(ret_close == -1)
    {
        perror("Error! unable to close File: \n");
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}
