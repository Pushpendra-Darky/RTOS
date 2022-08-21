#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_usr1_handler(int signum)
{
    printf("Signal USR1 is Triggered\n");
}

void sig_usr2_handler(int signum)
{
    printf("Signal USR2 is Triggered\n");
}


int main()
{
    signal(10,sig_usr1_handler);
    while(1)
    {
        printf("Sleeping..\n");
        sleep(1);
    }
    signal(12,sig_usr2_handler);


    return 0;
}