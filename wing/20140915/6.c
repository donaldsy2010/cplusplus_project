#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

typedef void (*sighandler_t)(int);
//sighandler_t signal(int signum, sighandler_t handler);

void handler(int sig)
{
    printf("foobar ....\n");
}


int main(int argc, const char *argv[])
{
    if(signal(SIGINT, handler) == SIG_ERR)
        ERR_EXIT("signal");

    for(;;)
        pause();

    return 0;
}











