// Dynamic Disk Scheduling Simulator in C
// Supports FCFS, SCAN, C-SCAN based on user input

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX 100

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void fcfs(int queue[], int n, int head) {
    int total = 0;
    printf("\nFCFS Order: %d ", head);
    for (int i = 0; i < n; i++) {
        total += abs(queue[i] - head);
        head = queue[i];
        printf("-> %d ", head);
    }
    printf("\nTotal Seek Time = %d\n", total);
}

void scan(int queue[], int n, int head, int size) {
    int total = 0;
    int left[MAX], right[MAX], l = 0, r = 0;

    for (int i = 0; i < n; i++) {
        if (queue[i] < head) left[l++] = queue[i];
        else right[r++] = queue[i];
    }

    qsort(left, l, sizeof(int), compare);
    qsort(right, r, sizeof(int), compare);

    printf("\nSCAN Order: %d ", head);
    for (int i = r - 1; i >= 0; i--) {
        total += abs(right[i] - head);
        head = right[i];
        printf("-> %d ", head);
    }
    if (head != size - 1) {
        total += abs((size - 1) - head);
        head = size - 1;
    }
    for (int i = 0; i < l; i++) {
        total += abs(left[i] - head);
        head = left[i];
        printf("-> %d ", head);
    }
    printf("\nTotal Seek Time = %d\n", total);
}

void cscan(int queue[], int n, int head, int size) {
    int total = 0;
    int left[MAX], right[MAX], l = 0, r = 0;

    for (int i = 0; i < n; i++) {
        if (queue[i] < head) left[l++] = queue[i];
        else right[r++] = queue[i];
    }

    qsort(left, l, sizeof(int), compare);
    qsort(right, r, sizeof(int), compare);

    printf("\nC-SCAN Order: %d ", head);
    for (int i = 0; i < r; i++) {
        total += abs(right[i] - head);
        head = right[i];
        printf("-> %d ", head);
    }
    if (head != size - 1) {
        total += abs((size - 1) - head);
        head = 0;
        total += (size - 1);
        printf("-> %d ", size - 1);
        printf("-> %d ", head);
    }
    for (int i = 0; i < l; i++) {
        total += abs(left[i] - head);
        head = left[i];
        printf("-> %d ", head);
    }
    printf("\nTotal Seek Time = %d\n", total);
}

int main() {
    int queue[MAX], n, head, max_cyl;
    char algo[10];

    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    printf("Enter the disk request queue: ");
    for (int i = 0; i < n; i++) scanf("%d", &queue[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter total number of cylinders: ");
    scanf("%d", &max_cyl);

    printf("Enter algorithm (fcfs / scan / cscan): ");
    scanf("%s", algo);

    if (strcmp(algo, "fcfs") == 0) fcfs(queue, n, head);
    else if (strcmp(algo, "scan") == 0) scan(queue, n, head, max_cyl);
    else if (strcmp(algo, "cscan") == 0) cscan(queue, n, head, max_cyl);
    else printf("Invalid algorithm selected!\n");

    return 0;
}  
