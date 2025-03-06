#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAvgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);

    findTurnaroundTime(processes, n, bt, wt, tat);

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_tat / n);
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];

    for (int i = 0; i < n; i++) {
        processes[i] = i + 1; // Process IDs are 1, 2, 3, ...
        printf("Enter burst time for process %d: ", processes[i]);
        scanf("%d", &burst_time[i]);
    }

    findAvgTime(processes, n, burst_time);

    return 0;
}


