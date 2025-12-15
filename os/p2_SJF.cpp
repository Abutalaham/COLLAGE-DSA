#include <stdio.h>

int main() {
    int n;
    int pid[15], bt[15], wt[15], ta[15];
    int i, j, temp;
    int twt = 0, tta = 0;

    printf("ENTER THE NUMBER OF PROCESSES: ");
    scanf("%d", &n);

    printf("\nENTER PROCESS ID OF ALL PROCESSES:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pid[i]);

    printf("\nENTER BURST TIME OF ALL PROCESSES:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    
    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        ta[i] = wt[i] + bt[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n",
               pid[i], bt[i], wt[i], ta[i]);

        twt += wt[i];
        tta += ta[i];
    }

    printf("\nAverage Waiting Time = %.2f", (float)twt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)tta / n);

    return 0;
}

