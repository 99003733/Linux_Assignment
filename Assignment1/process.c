#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* for fork */
#include <sys/wait.h> /* for wait */

int main()
{
   
    

    int pid=fork();

    if (pid==0)
    { /* child process */

        
        char *args[]={"./hello",NULL}; 
        execv(args[0],args); 

       
    }
    else { /* pid!=0; parent process */
        waitpid(pid,0,0); /* wait for child to exit */
    }
    return 0;
}


