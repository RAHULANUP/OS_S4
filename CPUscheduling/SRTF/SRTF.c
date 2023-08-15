#include <stdio.h>
#include <stdbool.h>

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
};
void swap(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}
void sort(struct Process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].arrivalTime > p[j + 1].arrivalTime)
            {
                swap(&p[j], &p[j + 1]);
            }
        }
    }
}
int srtf(struct Process p[], int n, int currentTime)
{
    int shortestJob = -1;
    int shortestTime = 9999;
    for (int i = 0; i < n; i++)
    {
        if (p[i].arrivalTime <= currentTime && p[i].remainingTime > 0)
        {
            if (p[i].remainingTime < shortestTime)
            {
                shortestTime = p[i].remainingTime;
                shortestJob = i;
            }
        }
    }
    return shortestJob;
}

int main()
{
    int n;
    printf("Enter the number of process : ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time : ");
        scanf("%d %d", &p[i].arrivalTime, &p[i].burstTime);
        p[i].id = i + 1;
        p[i].remainingTime = p[i].burstTime;
    }
    sort(p, n);
    int completed = 0;
    int currentTime = 0;
    printf("Gantt chart : \n");

    int completionTimes[n];
    int waitingTimes[n];
    int turnaroundTimes[n];

    while (completed < n)
    {
        int shortestJob = srtf(p, n, currentTime);

        if (shortestJob == -1)
        {
            printf("idle");
            currentTime++;
        }
        else
        {
            p[shortestJob].remainingTime--;
            printf("P%d ", p[shortestJob].id);
            currentTime++;
            if (p[shortestJob].remainingTime == 0)
            {
                completed++;
                completionTimes[shortestJob] = currentTime;
                waitingTimes[shortestJob] = completionTimes[shortestJob] - p[shortestJob].arrivalTime - p[shortestJob].burstTime;
                turnaroundTimes[shortestJob] = completionTimes[shortestJob] - p[shortestJob].arrivalTime;
            }
        }
    }
    printf("\nProcess\tArrival time\tBurst time\tcompletion time\twaiting time\tturnaround time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d \n", p[i].id, p[i].arrivalTime, p[i].burstTime, completionTimes[i], waitingTimes[i], turnaroundTimes[i]);
    }

    return 0;
}