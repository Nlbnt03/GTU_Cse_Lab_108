#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findClosest(int arr[], int query, int idx, int closestIdx, int minDiff) {
    if (idx < 0) {
        return arr[closestIdx];
    }

    int diff = abs(arr[idx] - query);

    if (diff < minDiff) {
        closestIdx = idx;
        minDiff = diff;
    }

    return findClosest(arr, query, idx - 1, closestIdx, minDiff);
}

int main() {
    int arr[10];
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 1001;
    }

    printf("Original array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int query;
    printf("Enter a query value (between 0 and 1000): ");
    scanf("%d", &query);

    int closest = findClosest(arr, query, 9, 0, INT_MAX);

    printf("Closest item to %d: %d\n", query, closest);

    return 0;
}