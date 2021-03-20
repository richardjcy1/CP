#include <stdio.h>
#include <signal.h>

void sigint_handler(int sig)
{
    printf("Caught SIGINT\n");
    _exit(0);
}

int main()
{
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
        printf("signal error");
    pause();
    return 0;
}