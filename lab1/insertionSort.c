#include <stdio.h>
#include <stdlib.h> // For rand and srand
#include <time.h>   // For measuring execution time

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Compare and shift elements
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n = 1000; // Array size
    int arr[n];
    int originalArr[n];
    int iterations = 10000; // Number of iterations

    // Seed for random number generation
    srand(time(NULL));

    // Generate a random array
    for (int i = 0; i < n; i++) {
        originalArr[i] = rand() % 10000;
    }

    double total_time = 0.0;

    for (int iter = 0; iter < iterations; iter++) {
        // Copy the original array to ensure each sort is on the same data
        for (int i = 0; i < n; i++) {
            arr[i] = originalArr[i];
        }

        clock_t start = clock();
        insertionSort(arr, n);
        clock_t end = clock();

        total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    double average_time = total_time / iterations;
    printf("Average time taken by Insertion Sort in C (over %d runs): %f seconds\n", iterations, average_time);

    return 0;
}

