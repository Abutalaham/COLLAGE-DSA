#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct calelement {
    char *day;
    int date;
    char *activity;
};

struct calelement* create() {
    struct calelement *calendar;
    calendar = (struct calelement*)malloc(7 * sizeof(struct calelement));
    return calendar;
}

void read(struct calelement *calendar) {
    char day[20];
    char activity[50];
    int i;

    for (i = 0; i < 7; i++) {
        printf("ENTER THE DAY: ");
        scanf("%s", day);
        calendar[i].day = (char*)malloc(strlen(day) + 1);
        strcpy(calendar[i].day, day);

        printf("ENTER DATE: ");
        scanf("%d", &calendar[i].date);

        printf("ENTER ACTIVITY: ");
        scanf(" %[^\n]", activity);
        calendar[i].activity = (char*)malloc(strlen(activity) + 1);
        strcpy(calendar[i].activity, activity);
    }
}

void display(struct calelement *calendar) {
    int i;
    printf("\nYOUR CALENDAR:\n");
    printf("DAY\tDATE\tACTIVITY\n");

    for (i = 0; i < 7; i++) {
        printf("%s\t%d\t%s\n",
               calendar[i].day,
               calendar[i].date,
               calendar[i].activity);
    }
}

int main() {
    struct calelement *calendar;
    calendar = create();
    read(calendar);
    display(calendar);
    free(calendar);
    return 0;
}

