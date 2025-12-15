#include <stdio.h>

int main()
{
    int n;
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    int wait_time = 0, ta_time = 0;
    int arr_time[n], burst_time[n], temp_burst_time[n];
    int x = n;

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time of Process %d: ", i + 1);
        scanf("%d", &arr_time[i]);
        printf("Enter Burst Time of Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        temp_burst_time[i] = burst_time[i];
    }

    int time_slot;
    printf("Enter Time Slot: ");
    scanf("%d", &time_slot);

    int total = 0, counter = 0, i = 0;

    printf("\nProcess ID\tBurst Time\tTurnaround Time\tWaiting Time\n");

    while (x != 0) {

        if (temp_burst_time[i] <= time_slot && temp_burst_time[i] > 0) {
            total += temp_burst_time[i];
            temp_burst_time[i] = 0;
            counter = 1;
        }
        else if (temp_burst_time[i] > 0) {
            temp_burst_time[i] -= time_slot;
            total += time_slot;
        }

        if (temp_burst_time[i] == 0 && counter == 1) {
            x--;
            printf("%d\t\t%d\t\t%d\t\t%d\n",
                   i + 1,
                   burst_time[i],
                   total - arr_time[i],
                   total - arr_time[i] - burst_time[i]);

            wait_time += total - arr_time[i] - burst_time[i];
            ta_time += total - arr_time[i];
            counter = 0;
        }

        if (i == n - 1)
            i = 0;
        else if (arr_time[i + 1] <= total)
            i++;
        else
            i = 0;
    }

    printf("\nAverage Waiting Time = %.2f", (float)wait_time / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)ta_time / n);

    return 0;
}

