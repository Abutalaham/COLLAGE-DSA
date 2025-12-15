#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int b[n], p[n], index[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time and Priority for Process %d: ", i + 1);
        scanf("%d %d", &b[i], &p[i]);
        index[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        int max = p[i], pos = i;
        for (int j = i; j < n; j++) {
            if (p[j] > max) {
                max = p[j];
                pos = j;
            }
        }
        swap(&p[i], &p[pos]);
        swap(&b[i], &b[pos]);
        swap(&index[i], &index[pos]);
    }

    int time = 0;
    printf("\nOrder of Process Execution:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d executes from %d to %d\n", index[i], time, time + b[i]);
        time += b[i];
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    int wt = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n",
               index[i], b[i], wt, wt + b[i]);
        wt += b[i];
    }

    return 0;
}

