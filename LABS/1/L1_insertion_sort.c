#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int A[N];
    srand(time(NULL)); // Seed the random number generator with current time

    printf("Lab 1 - Insertion Sort:\n");

    // Generate random numbers and fill the array
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100; // Generate random integers between 0 and 99
    }

    printf("List Prior to Sorting:\n");
    for (int i = 0; i < N; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");

    insertionSort(A, N);

    printf("List after Sorting:\n");
    for (int i = 0; i < N; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");

    return 0;
}