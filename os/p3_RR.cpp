#include <stdio.h>

int main() {
    int n, tq, i = 0, total = 0, done = 0;
    int at[10], bt[10], rt[10];
    float wt = 0, tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    while (i < n) {
        printf("Arrival Time P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst Time P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        i++;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nPID\tBT\tTAT\tWT\n");

    while (!done) {
        done = 1;
        i = 0;

        while (i < n) {
            if (rt[i] > 0) {
                done = 0;

                if (rt[i] > tq) {
                    total += tq;
                    rt[i] -= tq;
                } else {
                    total += rt[i];
                    printf("%d\t%d\t%d\t%d\n",
                           i + 1, bt[i],
                           total - at[i],
                           total - at[i] - bt[i]);

                    wt += total - at[i] - bt[i];
                    tat += total - at[i];
                    rt[i] = 0;
                }
            }
            i++;
        }
    }

    printf("\nAverage Waiting Time = %.2f", wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", tat / n);

    return 0;
}

