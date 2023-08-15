#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

int main()
{

    int i;
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    printf("Key of the shared memory is %d ", shmid);
    shared_memory = shmat(shmid, NULL, 0);
    printf("Process attached at %p\n", shared_memory);
    printf("Enter the contents to be written : ");
    read(0, buff, 100);
    strcpy(shared_memory, buff);
    printf("The contents entered are : %s\n", (char *)shared_memory);

    return 0;
}