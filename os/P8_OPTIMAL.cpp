#include <stdio.h>
#include <limits.h>
#define FRAMES 3

int checkHit(int page, int frame[], int occupied) {
    for (int i = 0; i < occupied; i++) {
        if (frame[i] == page)
            return 1; // Hit
    }
    return 0; // Miss
}

int findOptimalPageReplacement(int frame[], int pages[], int currentIndex, int n, int occupied) {
    int farthestIndex = -1;
    int pageToReplace = -1;

    for (int i = 0; i < occupied; i++) {
        int nextUse = -1;

        for (int j = currentIndex + 1; j < n; j++) {
            if (frame[i] == pages[j]) {
                nextUse = j;
                break;
            }
        }

        if (nextUse == -1)
            return i;

        if (nextUse > farthestIndex) {
            farthestIndex = nextUse;
            pageToReplace = i;
        }
    }

    return pageToReplace;
}

void printFrames(int frame[], int occupied) {
    for (int i = 0; i < occupied; i++)
        printf("%d\t\t", frame[i]);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frame[FRAMES];
    int pageFaults = 0;
    int occupied = 0;

    printf("Page\tFrame 1\tFrame 2\tFrame 3\n");

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];

        if (checkHit(currentPage, frame, occupied)) {
            printf("%d\t\t", currentPage);
            printFrames(frame, occupied);
            printf("\n");
        } else {
            pageFaults++;
            if (occupied < FRAMES) {
                frame[occupied] = currentPage;
                occupied++;
            } else {
                int replaceIndex = findOptimalPageReplacement(frame, pages, i, n, occupied);
                frame[replaceIndex] = currentPage;
            }

            printf("%d\t\t", currentPage);
            printFrames(frame, occupied);
            printf("\n");
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}

