#include <stdio.h>
#include <stdlib.h>


int main() {
    int arr[] = {78, 17, 39, 26, 72, 94, 21, 12, 23, 68};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num_buckets = 5; // You can adjust the number of buckets based on your data

    printf("Original array: ");
    printArray(arr, n);

    // Perform bucket sort
    bucketSort(arr, n, num_buckets);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
// Function to perform insertion sort on each bucket
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

// Function to perform bucket sort
void bucketSort(int arr[], int n, int num_buckets) {
    // Create an array of buckets
    int buckets[num_buckets][n];

    // Initialize each bucket size to 0
    int bucket_sizes[num_buckets];
    for (int i = 0; i < num_buckets; i++) {
        bucket_sizes[i] = 0;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] * num_buckets / (100 + 1); // Adjust the range based on your data
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < num_buckets; i++) {
        insertionSort(buckets[i], bucket_sizes[i]);
    }

    // Combine the sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

}
