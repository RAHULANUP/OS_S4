#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char fn[20], temp[100], pat[20];
    FILE *fp;
    printf("Enter the name of the file : ");
    scanf("%s", fn);
    printf("Enter the pattern : ");
    scanf("%s", pat);
    fp = fopen(fn, "r");
    while (!feof(fp))
    {
        fgets(temp, 1000, fp);
        if (strstr(temp, pat))
        {
            printf("%s", temp);
        }
    }

    return 0;
}