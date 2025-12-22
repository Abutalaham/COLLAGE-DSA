#include <stdio.h>

int main() {
    int n, i, j, temp;
    int bt[10], pr[10], pid[10];
    int wt = 0, tat = 0, t = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Burst Time & Priority of P%d: ", pid[i]);
        scanf("%d %d", &bt[i], &pr[i]);
    }

    /* Sort by Priority (Higher number = Higher priority) */
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] < pr[j]) {
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    /* Printing scheduled process */
    printf("\nOrder of Process Execution:\n");
    for (i = 0; i < n; i++) {
        printf("P%d is executed from %d to %d\n",
               pid[i], t, t + bt[i]);
        t += bt[i];
    }

    printf("\nPID\tBT\tWT\tTAT\n");
    wt = 0;
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n",
               pid[i], bt[i], wt, wt + bt[i]);
        tat += wt + bt[i];
        wt += bt[i];
    }

    printf("\nAverage Waiting Time = %.2f", (float)(wt - tat + wt) / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)tat / n);

    return 0;
}

