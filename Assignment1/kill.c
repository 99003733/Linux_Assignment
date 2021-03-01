#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <error.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h>

int main()
{
    FILE *getPIDS;
    char line[130];
    pid_t killpid;
    // setuid to that of root//
    pid_t mypid   = getpid();
    pid_t myppid  = getppid();
    getPIDS = popen("pidof -x yes","r");
    while (fgets(line,sizeof(line),getPIDS)) {
            printf("KILL PID: %s",line);
            kill(line,SIGKILL);
    }
}

