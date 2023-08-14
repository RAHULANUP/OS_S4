#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        printf("CHILD PROCESS NOT CREATED");
    }
    else
    {
        if (child_pid == 0)
        {
            printf("Process Just created");
        }
        else
        {
            printf("Process ongoing \n");
            printf("parent process id: %d\n", getpid());
            printf("Child process : %d", child_pid);
        }
    }
    return 0;
}