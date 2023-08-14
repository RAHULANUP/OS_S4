#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    // ======================= cp =========================
    FILE *fp1, *fp2;
    char m;
    fp1 = fopen("trial.txt", "r");
    fp2 = fopen("newtrial.txt", "w");
    printf("CONTENTS IN trail.txt\n");
    while ((m = getc(fp1)) != EOF)
    {
        printf("%c", m);
        fputc(m, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    printf("\nCOPIED CONTENTS FROM TRIAL ARE AS FOLLOWS ...\n");
    fp2 = fopen("newtrial.txt", "r");
    while ((m = getc(fp2)) != EOF)
    {
        printf("%c", m);
    }

    // ========================== ls =============================

    DIR *dirp;
    struct dirent *dptr;
    char buff[100];

    printf("\nEnter the directory name : ");
    scanf("%s", buff);

    if ((dirp = opendir(buff)) == NULL)
    {
        printf("No such directory exist....");
        exit(0);
    }
    while (dptr = readdir(dirp))
    {
        printf("%s\n", dptr->d_name);
    }

    return 0;
}