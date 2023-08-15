#include <stdio.h>
#include <stdlib.h>
struct Process
{
    int arrivalTime;
    int burstTime;
};
void fcfs(struct Process processes[], int n)
{
    int currentTime = 0;
    printf("\n Pid\t Arrival Time\t Burst Time\t Completion Time\t Waiting Time\t Turnaround Time\n ");
    for (int i = 0; i < n; i++)
    {
        int waitingTime = currentTime - processes[i].arrivalTime;
        if (waitingTime < 0)
        {
            currentTime = processes[i].arrivalTime;
            waitingTime = 0;
        }
        int completionTime = currentTime + processes[i].burstTime;
        int turnaroundTime = completionTime - processes[i].arrivalTime;

        printf("\n %d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].arrivalTime, processes[i].burstTime, completionTime, waitingTime, turnaroundTime);
        currentTime = completionTime;
    }
}
int main()
{
    int n;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time of process %d : ", i + 1);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
    }
    fcfs(processes, n);

    return 0;
}