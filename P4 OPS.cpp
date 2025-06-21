#include <stdio.h>

int main() {
    int n, i, j;
    int burst_time[20], process[20], waiting_time[20], turnaround_time[20];
    int total_waiting = 0, total_turnaround = 0;
    int temp;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    
    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        process[i] = i + 1; 
    }

    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burst_time[i] > burst_time[j]) {
                
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    waiting_time[0] = 0;
    for (i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++)
            waiting_time[i] += burst_time[j];
    }

    for (i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
    }

   
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }


    printf("\nAverage Waiting Time = %.2f", (float)total_waiting / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_turnaround / n);

    return 0;
}

